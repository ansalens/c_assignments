# Dynamic libraries
### 10/4/24 ~ 13:27
> https://medium.com/@meghamohan/everything-you-need-to-know-about-libraries-in-c-e8ad6138cbb4

### What are dynamic libraries
- Dinamicki kompajlirana biblioteka je ona biblioteka koja se ucitava pri potrebi.
- Ime biblioteke je u izvrsnom programu, i to je jedino sto je potrebno kao referenca za datu biblioteku.
- Linkovanje se desava u toku pokretanja kada su oba fajla ucitana u memoriju.

### Pros & cons
- Prednosti:
1. Ucitava se samo jedna instanca biblioteke u memoriji.
- Ovo znaci da ako vise programa koriste jednu te istu biblioteku, memorija se nece za dzabe trositi.
2. Prilikom updejtovanja biblioteke, programi ne trebaju da se rekompajliraju, promena se reflektuje odmah.
- Mane:
1. Sporije ucitavanje i pokretanje programa zbog linkovanja (koje se desava pri pokretanju)

### How to make dynamic library
- Kompajliraj sve .c fajlove
```terminal
$ gcc hello.c -c -fPIC -shared -o hello.so
```


