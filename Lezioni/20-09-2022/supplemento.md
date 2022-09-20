# Lezione 20/09/2022

## Funzioni

È buona prassi separare la dichiarazione della funzione dalla definizione
solitamente si dichiarano in file esterni [.h]

Sintassi C:

* Dichiarazione
  * Parametri e tipo di ritorno del prototipo
* Definizione
  * Include il corpo della funzione con il codice da eseguire

Se manca la definizione => linker error <br>
Se manca la dichiarazione => compiler error

````c
//inside .h file
int my_function(int param1, char param2);

//inside .c file
int my function(int param1, char param2) {
    //Body of the function
}
````

## Funzioni I/O

Libreria standard I/O è stdio.h

 ```c
//Output on console
int foo = 5;
printf("My output: %d", foo); 
//Output: "My output: 5"

// Placeholders:
// %s string (array of char)
// %c char
// %d int
// %f float
// %e per notazione scientifica
// %p per gli indirizzi di memoria
// per i long ed i double si antepone L

//Input
int bar;
float foobar;
scanf("%d %f", &bar, &foobar); 
// restituisce il numero di valori letti correttamente 
// (se la lettura fallisce bisogna svuotare il buffer e riprovare) 
// per svuotare il buffer: [scanf("%*[^\n]\n")]
// per i double usare %lf
// per ignorare parte dell'input %*
// %nc [%10c] legge esattamente 10 caratteri
// %ns [%10s] legge fino al primo whitespace o fino al max degli n caratteri
// %n[regex] legge una stringa di n caratteri che soddisfa la regex
 

```

## Scoping

I nomi sono utilizzati dal momento in cui sono dichiarati fino alla fine dello scope in cui sono dichiarati
* Variabili extern possiamo utilizzare variabili globali dichiarate in un altro file
* Variabili static:
  * Per nascondere variabili globali
  * Per rendere visibili solo nella funzione

````c
// max.c
int countA=0; // Se scrivessi static int countA non potrei vederla in main.c
int countB=0;
int max(int a, int b){
    if(a>b)
        return a
    return b    
}

// max.h
int max(int a, int b);
// main.c
#include<stdio.h>
#include "max.h"

extern int countA;

int main(void){
    // ...
}
````

## Gestione della memoria

* Programma e dati - memoria
* Zona dati:
  * Dati statici inferiti a tempo di compilazione (variabili globali , statici)
  * Stack - record di attivazione (UNO per ogni blocco di codice)
  * Heap - dati dinamici (runtime), frammentati, memoria allocata dinamicamente tramite puntatori

## Puntatori

Qualsiasi dato che sta in memoria ha un valore e un indirizzo di memoria.
Un puntatore è una **variabile** che contiene un indirizzo di memoria, possiamo:
* leggere e scrivere il valore a un certo indirizzo di memoria (operatore di referencing *)
* leggere e scrivere l'indirizzo di memoria di una variabile (operatore di addressing &)

````c
// solitamente gli indirizzi sono in HEX
int a = 5; //Valore 5 indirizzo 13 (indirizzo fittizio)
int *aPtr = &a; //Valore 13 indirizzo 36 (indirizzo fittizio)
int *aPtr1 = &a;

(*aPtr) = 10; // cambio il valore di a
(*aPtr1) = 20; // anche con questo cambio l'indirizzo di a


int b = 5;
double *bPtr = &b;
// L'operazione funziona, ma quando provo a leggere il valore di b 
// dal puntatore si ha un valore invalido
````

## Passaggio parametri a funzione

Il passaggio dei parametri viene fatto sempre per valore - si passa sempre una copia del valore della variabile
per poter cambiare il valore di una variabile in una funzione si utilizzano i puntatori passando l'indirizzo di memoria di una variabile

````c
void swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
````

## Array, puntatori e funzioni

```c
int a[10]; 
// Crea una variabile a, 
// alloca sullo stack 10 interi contigui, 
// memorizza in a l'indirizzo dell'inizio della zona di memoria allocata
```

Passare un array come parametro a una funzione - viene passato il puntatore al primo elemento dell'array

## Array bidimensionali

````c
int a[3][3];

// La seconda dimensione è molto importante 
// (aiuta il compilatore a calcolare la locazione di memoria giusta, 
// dati gli indici)
int f(int [][3]);
````

## Parametri da linea di comando

Possiamo passare dei parametri e opzioni, come nel caso dei comandi UNIX

````c
// argc: numero di parametri
// argv: array con tutti i parametri (argv[0] è il nome del programma)
int main(int argc, char* argv[]) {
    printf("%d", argv[2])
}
````

`````shell
./main.out 7 5
# Stampa 5
`````