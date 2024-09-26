## Function hooking on Linux
### Shared library
- Je skup prekompajliranog C koda dostupan za koriscenje bilo gde.
- U tom kodu se nalaze precizno definisane funkcije, konstante, strukture...
- Svaka biblioteka sadrzi tacnu adresu gde se sta nalazi u memoriji.
- Tako da, kada tvoj program koristi `write()` syscall on konsultuje `libc` biblioteku da bi saznao njenu adresu i definiciju.

### Execution of program
- ld.so je dinamicki linker u Linuxu.
- On je zaduzen da ucita sve biblioteke prilikom izvrsavanja programa.
- __ld.so__ to radi koriscenjem promenljivih okruzenja kao sto su __DT_RPATH__, __DT_RUNPATH__, __LD_LIBRARY_PATH__, __DT_NEEDED__...
- I pomocu fajlova koji su na sistemu kao sto su: /etc/ld.so.cache, __/etc/ld.so.preload__

### Compilation of malicious shared object
```terminal_session
$ gcc malicious.c -o malicious.so -shared -fPIC -ldl -D_GNU_SOURCE
```
- `-fPIC` znaci generate position independent code sto u prevodu znaci da ce program koristiti reference funkcija u odnosu na GOT (Global offset table), i da ce se kod moci pokretati na vise arhitektura.
- `-shared` znaci da proizvodi deljeni objekat koji se moze drugde koristiti.
- `-D_GNU_SOURCE` zadovoljava #ifdef uslov za koriscenje RTLD_NEXT markoa
- `-ldl` linkuje libdl odnosno biblioteku koja se koristi za dinamicki linker
- __linux-gate.so__ je kernel biblioteka koje cini da syscalls budu brzi.
