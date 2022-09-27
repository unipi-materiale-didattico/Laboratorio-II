# Lezione 27/09/2022

## Aritmetica dei puntatori

```c
int a[10];
// La variabile a in realtà è un puntatore
a == &(a[0])
(a+1) == &(a[1])

int* intPtr = &a;

int* intPtrI = intPtr+i * sizeof(int);

a[i] == * (a+i); // a[i] è zucchero sintattico
```

### Allocazione dinamica della memoria

Heap dati dinamici (runtime), frammentati
possiamo allocare memoria in Heap solo tramite puntatori
```c
// Allocazione statica
int a; // Valore non definito
int* aPtr; // Valore non definito (contenuto della memoria, potrebbe non essere 0)
```
Per uscire dallo stack usiamo la stdlib
```c
#include<stdlib.h>
//...
int * aPtr = (int*)malloc(sizeof(int));
int * bPtr = (int*)calloc(1, sizeof(int));

void *malloc (size_t n) // Restituisce un Void Ptr
void *calloc (size_t n, size_t size); // Bisogna fare il casting al tipo giusto
// Se non trovano memoria restituiscono 0, in stdlib si usa la costante NULL
// != NULL
```
Esempio di cast
```c
#include<stdio.h>

int main(void) {
    int a=10;
    void* aP = &a;
    //printf("%d\n", *aP); Da errore
    printf("%d\n", *(int *)aP); //Bisogna usare il cast
}
```

Liberare la memoria utilizzata:
````c
free(ptr); // Bisogna liberare la memoria quando un oggetto non è più necessario
````

Errori Comuni:

* Non liberare un puntatore e poi perdere il puntatore - Memory Leak
* Liberare la memoria allocata in modo statico
* Utilizzare un puntatore dopo aver liberato la memoria

Nota: Allocazione statica > Allocazione dinamica (preferire la prima alla seconda quando possibile)

### Array di puntatori

````c
// N puntatori a int non inizializzati
int** ps = (int **)malloc(n*sizeof(int*));
// N puntatoti a int inizializzati a NULL
int** ps2 = (int **)calloc(n, sizeof(int*)); 

````

* è più generico rispetto ad un array bidimensionale statico **int[N][M]**
  ogni riga può avere dimensione diversa, senza spreco di memoria
* Più facile da passare come parametro a funzioni (non serve conoscere M)
* L'organizzazione in memoria è diversa (in Heap non necessariamente sono contigue)

#### Vantaggi dell'allocazione dinamica

* Più controllo sulla memoria utilizzata
* Meno spreco di memoria
* Programmi più generici
* Più modularità, passaggio più facile di parametri

#### Svantaggi

* Complessità aggiunta della gestione della memoria
* possibilità di avere Memory leak

### Puntatori a struct

````c
typedef struct {
    int elements[N];
    int n;
} Stack;

Stack* s = (Stack*)malloc(sizeof(Stack));

// Per accedere ai campi usare l'operatore ->
// una struct può contenere come membro puntatori a se stessa (self-referential struct)

s->n;
````
#### Linked list
```c
struct n {
    int value;
    struct n* next;
};
typedef struct n Node;
```