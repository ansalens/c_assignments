# Function call hooking
- Odnosi se na tehnike koje menjaju ponasanje pozivajucoj funkciji prilikom izvrsavanja programa.
- Jedna od tih tehnika je koriscenje __dynamic linker API__ i __LD_PRELOAD__.

## Static vs Dynamic binary
![staticbin](scrs/static.png)
- Kada izvrsni program sadrzi u sebi sve potrebne funkcije koje koristi, taj program je staticno kompajliran.
- Staticno kompajliran program nema druge programe od kojih zavisi (on nema __dependencies__).
- Time sto je staticno kompajliran, nemoguce je promeniti ponasanje funkcija u programu a da se ne menja ceo program (dakle nemoguce je hookovati funkcije).
- Dinamicna binarka je binarka koja koristi __shared object (.so)__ fajlove.
- Shared object fajlovi su biblioteke koje su kompajlirane zasebno i cuvaju se negde na sistemu.
- Ovi fajlovi se ukljucuju u izvrsni program onda kada su potrebni prilikom izvrsavanja.
- Komponenta u Linuxu zaduzena za dynamic linking je __dynamic linker__ odnosno ld.so ili ld-linux.so.* 
- Ovo je nacin na koji mozemo da prepoznamo da li je program staticki ili dinamicki kompajliran:
```terminal_session
$ readelf -h static
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - GNU
  ABI Version:                       0
  Type:                              EXEC (Executable file)
$ readelf -h hello
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              DYN (Position-Independent Executable file)
```
- Type nam govori o kom programu je rec, EXEC je staticki, DYN dinamicki.

## Shared library/object
- Shared library je fajl koji sadrzi programski kod koji mogu da koriste drugi programi. 
- __write() syscall wrapper__ funkcija je definisana u libc shared library.
- Direktan pristup sistemskim pozivima nije moguce, vec __libc__ definise __wrapper__ funkcije koje sluze kao posrednik izmedju korisnika i syscall.
- Mozemo videti koje shared objekte referencira program sa `ldd`
```terminal_session
$ ldd /bin/ls
	linux-vdso.so.1 (0x00007ffd6b3f3000)
	libcap.so.2 => /usr/lib/libcap.so.2 (0x00007f8506141000)
	libc.so.6 => /usr/lib/libc.so.6 (0x00007f8505f5b000)
	/lib64/ld-linux-x86-64.so.2 => /usr/lib64/ld-linux-x86-64.so.2 (0x00007f850619c000)
```

### Abusing LD_PRELOAD
- LD_PRELOAD je promenljiva okruzenja.
- To je lista __ELF shared objects__ koji su dati od strane __KORISNIKA!__
- Neformalno LD_PRELOAD je path do shared lib koji ce se ucitati pre drugih libova, i koja ima tu moc da preklopi (override) sve funkcije koje se pojavljuju u drugim libovima.
- LD_PRELOAD objekti se ucitavaju pre nego sto se ucita bilo sta drugo.
- LD_PRELOAD se koristi za debagovanje, testiranje, reversing i za pisanje rootkit.

#### LD_PRELOAD vs /etc/ld.so.preload
- /etc/ld.so.preload vazi za ceo sistem i za sve procese koji se pokrecu.
- LD_PRELOAD vazi samo za tog korisnika koji je koristi u svom okruzenju.
- __LD_PRELOAD__ ima __prednost pri ucitavanju__ i zato se ucitava prvi.

## How to hook libc functions
- Proces je sledeci:
1. Prototip ciljane funkcije deklarises u svom programu na isti nacin na koji je ona deklarisana u svom header fajlu
```c
ssize_t write(int fildes, const void *buf, size_t nbyte);
```
2. Definises ciljanu funkciju koristeci prototip
3. Definises pokazivac koji ce pokazivati na pravu funkciju
```c
    ssize_t (*old_write)(int fildes, const void *buf, size_t nbyte);
```
3. Inicijalizujes pokazivac sa __dlsym()__ ukoliko je pokazivac NULL
```c
    if (!old_write)
        old_write = dlsym(RTLD_NEXT, "write");
```
4. Dodas svoj kod koji menja ponasanje funkciji
5. Pozoves pravu funkciju na kraju
```c
    return old_write(fildes, buf, nbyte);
```

## Dynamic linker API
- __dlsym()__ govori dynamic linker API da zeli dobiti adresu originalne funkcije iz shared library prilikom izvrsavanja.
- __RTLD_NEXT__ nalazi __sledecu__ instancu funkcije, odnosno onu definisanu u libc.
```c
int (*new_puts)(const char *msg);
new_puts = dlsym(RTLD_NEXT, "puts");
```
- Prva linija definise novi pokazivac na funkciju, dok sledeca linija inicijalizuje taj pokazivac na sledecu instancu te funckije.

### Compiling shared object
```terminal_session
$ gcc assignment27.c -o malicious.so -fPIC -shared -ldl
```
+ fPIC - generise position independent code
+ shared - za kompajliranje shared objekata
+ ldl - za koriscenje dynamic linkera

### Anti-debugging bypass
- `ptrace()` je syscall koji sluzi za kontrolisanje izvrsavanja drugog procesa.
- __PTRACE_TRACEME__ se koristi kako bi proces pratio izvrsavanje samog sebe.
- Ako se program koristi u debageru, ptrace sa ovom zastavom generise gresku odnosno vraca -1.
- Na taj nacin, mozemo hookovati ptrace kako bi uvek vratio 0, cak i kada je u gdb.
```c
#include <sys/types.h>

long ptrace(int request, pid_t pid, void *addr, void *data) {
  return 0;
}
```

### LD_PRELOAD abuse detection
1. Ukoliko postoji /etc/ld.so.preload a da ga ti nisi napravio
2. /proc/{pid}/LD_PRELOAD ceprkaj da vidis ima li cudnih libary poziva
3. Uporedi runtime filesystem sa snapshot
4. Ako koristis kontejner koristi drift execution
5. Koristi ostale alatke kao sto su [unhide](https://github.com/YJesus/Unhide)


##### Sources
+ https://tbrindus.ca/correct-ld-preload-hooking-libc/
+ https://www.netspi.com/blog/technical/network-penetration-testing/function-hooking-part-i-hooking-shared-library-function-calls-in-linux/

##### Read
+ https://www.wiz.io/blog/linux-rootkits-explained-part-1-dynamic-linker-hijacking
