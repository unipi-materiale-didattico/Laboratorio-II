# Esercizi

## 1

````c
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
    double sum = 0;
    for(int i = 1; i < argc; i++){
        sum += atof(argv[i]);
    }
    printf("%f\n",sum);
    return 0;
}
````

## 2. Esercizio su matrici

Scrivere un programma che legge da standard input due matrici di interi di dimensione r1xc1 e r2xc2 e stampa la somma delle due matrici, se possibile. Il programma deve utilizzare una funzione per calcolare il prodotto. L'input e' organizzato in questo modo:

per ogni matrice vengono inseriti prima il numero di righe e colonne, poi i rxc valori interi. 

Il programma deve eseguire anche il controllo dell'input.

````c
void leggiMatrice(int c, int r, int m[][c]);
void printMatrix(int c, int r, int m[][c]);
void sum(int c, int r, int x[][c], int y[][c], int z[][c]);
int readInt(){
    int x;
    while(scanf("%d",&x)==0){
        printf("Errore in input, inserisci un intero valido\n");
        scanf("%*[^\n]\n");
    }
    return x;
}

int main(){
    //leggi matrici
    int r1,c1,r2,c2;
    r1 = readInt();
    c1 = readInt();
    int m1[r1][c1];
    leggiMatrice(r1,c1,m1);
    r2 = readInt();
    c2 = readInt;
    int m2[r2][c2];
    leggiMatrice(r2,c2,m2);
    if(r1 == r2 && c1 == c2){
        int m3[r1][c1];
        sum(r1,c1,m1,m2,m3);
        printMatrix(r1,c1,m3);
    }
    else{
        printf("Le matrici non si possono sommare\n");
    }
    return 0;
}

void leggiMatrice(int c, int r, int m[][c]){
    int i,j;
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            m[i][j] = readInt();
        }
    }
}

void printMatrix(int c, int r, int m[][c]){
    int i,j;
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++)
        printf("%d ", m[i][j]);
        printf("\n");
    }
}

void sum(int c, int r, int x[][c], int y[][c], int z[][c]){
    int i,j;
    for(i = 0; i < r; i++)
     for(j = 0; j < c; j++)
       z[i][j] = x[i][j] + y[i][j];
}
````

## 3. Programma che gestisce pazienti in un ospedale

I pazienti sono identificati da un id numerico intero. Possono essere o pazienti con diabete (1) o pazienti con malattie cardiovascolari (0). Per ogni tipo di paziente sono disponibili diversi tipi
di variabili cliniche. Per i pazienti con diabete abbiamo la glicemia (float) e il peso (float), per i pazienti cardio abbiamo 
pressione(int) e frequenza cardiaca(int). Il programma legge un numero n da tastiera, seguito da n pazienti. Per ogni paziente 
abbiamo l'ID e il tipo di malattia sulla prima riga, e le due variabili di interesse sulla seconda riga. Il programma stampa tutti i 
pazienti che hanno la stessa malattia dell'ultimo paziente inserito.

````c
#include <stdio.h>
typedef struct{
    float glicemia;
    float peso;
} ValDiabete;

typedef struct{
    int pressione;
    int frequenza;
}ValCardio;

typedef union{
    struct valCardio vc;
    struct valDiabete vd;
} Valori;


typedef struct{
    int id;
    int diagnosi;
    Valori val;
}Paziente;

int main(){
    int n;
    scanf("%d", &n);
    Paziente lista[n];
    for(int i = 0; i < n; i++){
        scanf("%d %d", &lista[i].id, &lista[i].diagnosi);
        if(lista[i].diagnosi == 0){
            scanf("%d %d", &lista[i].val.vc.frequenza,&lista[i].val.vc.pressione);
        }
        else{
            scanf("%d %d",&lista[i].val.vd.glicemia,&lista[i].val.vd.peso);
        }
    }
    for(int i = 0; u < n; i++){
        if(lista[i].diagnosi == lista[n-1].diagnosi){
            if(lista[i].diagnosi == 0){
                printf("ID: %d, FC: %d, Pressione: %d", lista[i].id, lista[i].val.vc.frequenza, lista[i].val.vc.pressione);
            }
            else{
                printf("ID: %d, Glicemia: %f, Peso: %f", lista[i].id, lista[i].val.vd.glicemia,lista[i].val.vd.peso);
            }
        }
    }
}
````