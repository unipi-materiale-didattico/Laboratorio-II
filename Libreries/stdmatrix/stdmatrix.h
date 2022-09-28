//
// Created by Gabriele Scannagatti on 27/09/22.
//

#define ERROR_SUCCESS 0
#define MATRIX_ALLOCATION_ERROR 1
#define INCOMPATIBLE_MATRICES_ERROR 2

/**
 * La funzione alloca in maniera sicura la matrice row X col
 * In caso di errore in fase di creazione la memoria viene liberata
 * @param row Numero di righe
 * @param col Numero di colonne
 * @param out_matrix puntatore alla matrice allocata dinamicamente
 * @return int rappresentante il codice di errore (0 successo)
 */
int allocMatrix_s(int row, int col, int** out_matrix);

/**
 * La funzione alloca una matrice row X col
 * @param row Numero di righe
 * @param col Numero di colonne
 * @return puntatore alla matrice
 */
int** allocMatrix(int row, int col);

/**
 * La funzione valorizza ogni cella della matrice da input utente
 * @param matrix Matrice da valorizzare
 * @param row Numero di righe
 * @param col Numero di colonne
 */
void readMatrix(int** matrix, int row, int col);

/**
 * La funzione controlla se le due matrici sono sommabili e le somma in caso positivo
 * @param a Matrice da sommare
 * @param b Matrice da sommare
 * @param row_a Numero righe matrice a
 * @param col_a Numero colonne matrice b
 * @param row_b Numero righe matrice b
 * @param col_b Numero colonne matrice b
 * @param out_matrix Puntatore alla matrice risultato dell'operazione
 * @return int rappresentate il codice di errore (0 successo)
 */
int addMatrix_s(int** a, int** b, int row_a, int col_a, int row_b, int col_b, int** out_matrix);

/**
 * La funzione somma due matrici
 * @param a Matrice da sommare
 * @param b Matrice da sommare
 * @param row Numero righe matrici
 * @param col Numero colonne matrici
 * @return Matrice risultato operazione o NULL in caso di errore allocazione matrice risultato
 */
int** addMatrix(int** a, int** b, int row, int col);