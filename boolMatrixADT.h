#ifndef UNTITLED9_BOOLMATRIXADT_H
#define UNTITLED9_BOOLMATRIXADT_H

/**
 * Se desea implementar una matriz booleana "infinita" (cada elemento es 1 ó 0) pero se sabe que la gran mayoría de los
 * elementos tienen el valor 0 (falso).
 * Para ahorrar espacio se usa una multilista, donde la lista principal o "troncal" representa las filas y cada sublista
 * representa las columnas. Ambas listas están ordenadas en forma ascendente.
 * Una multilista vacía se representa con el valor NULL
 *
 * Ejercicio de Parcial 1C Año 2011
 */
#include <stdlib.h>


typedef struct boolMatrixCDT * boolMatrixADT;

typedef enum {FALSE = 0, TRUE } boolean;

/*
 * Crea una matriz con todos los elementos en falso
 */
boolMatrixADT newBoolMatrix(void);

/*
** Si @value es true entonces m[row][col] = value
** Si @value es false entonces borra m[row][col]
*/
void setValue(boolMatrixADT m, size_t row, size_t col, boolean value);

/*
 * Retorna el valor almacenado en m[row][col]
 */
boolean getValue(const boolMatrixADT m, size_t row, size_t col);

/*
 * Libera toda la memoria reservada
 */
void freeBoolMatrix(boolMatrixADT m);

/*
 * Todos los true pasan a ser false y los false pasan a ser ture
 */
void negate(boolMatrixADT m);

#endif //UNTITLED9_BOOLMATRIXADT_H