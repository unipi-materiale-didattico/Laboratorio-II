# Lezione 13/10/2022

## Puntatori a funzioni
Le funzioni in C non sono variabili, possiamo però ottenere puntatori a funzioni
```c
int sum(int,int);
int mult(int, int);

int main(){
    int (*f)(int,int);
    f = sum;
    int (*g[2])(int,int)={sum, mult};
    return 0;
}
```
Possiamo avere array di puntatori a funzioni
ad esempio per interfacce utente o per creare automi
Oppure usare le funzioni come argomenti per altre funzioni
````c
//In stdlib

/**
 * @param base - Array
 * @param num - Numero elementi
 * @param size - dimensione singolo elemento
 * @param compar - puntatore a funzione per confronto
 */
void qsort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*))

// Le funzioni comparatore devono avere questa firma 
int compInt(const void*, const void*);
int compFloat(const void*, const void*);
````

## Stringhe

Array di caratteri con '\0' alla fine (carattere NULL, con valore 0)

````c
char s[]="Ciao"; // -> ['C','i','a','o','\0'] Mutabile
char* str="Ciao"; // -> Costante
````
Come lavorare con Array

## Operazioni su stringhe

Lib *string.h*
```c
size_t strlen(const char * str)
char* strcpy(char* dest, const char* src)
int strcmp(const char* str1, const char* str2)
char* strcat(char * dest, const char * src)
// Consuma la stringa originale, usare una copia
char* strtok(char * str, const char * delim) 
```

## Operazioni su caratteri

Lib *ctype.h*

````c
int isalpha(int)
int issupper(int)
...etc

int getChar(void); // Legge un carattere alla volta
char * fgets(char* str, int num, FILE * stream) // stdin per leggere da stream

int sscanf(const char* s, const char * format, ...); // Scanf su una stringa
````
## Steam standard error

````c

int main(){
    int* p=NULL;
    fprintf(stderr, "Sono qui\n");
    printf("%d" *p);
}
````

Lib *assert.h*

````c
void assert(int expr)
#Define NDEBUG // per ignorare gli assert
int main(){
    int x;
    scanf("%d", &x);
    assert(x>0);
}
````

## Tool di debug (gdb e valgrind)

* gdb permette di eseguire il programma passo per pass
* valgrind permette di analizzare la memoria allocata

**Nota:** non possiamo fare debug su librerie

Compilare con il flag -g
### GDB
Per avviare il debugger usare il comando
````shell
gdb [opzioni] <eseguibile> [opzioni eseguibile]
````

* Settare un breakpoint:
  * b 6 - breakpoint a riga 6
  * b main.c:6 - breakpoint nel file main.c riga 6
  * b push
* Settare un watchpoint:
  * watch a - watchpoint su variabile a
* Printare variabili
  * p x - stampa il valore di x
* Stampare lo stack dei record di attivazione
  * bt
### Valgrind

```shell
valgrind --leak-check=full [eseguibile] [argomenti eseguibile]
```

