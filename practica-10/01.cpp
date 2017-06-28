/*
 * Dada una matriz cuadrada triangular (es decir, todos los elementos por debajo de la diagonal son cero)
 * de números enteros, escribir un algoritmo que calcule su determinante. Recordar que el determinante de una matriz triangular
 * es el producto de los elementos de su diagonal.
 */

#include "header.h"

int determinante(matriz m){
	int det = 1;

	for(int i = 0; i < m.size(); i++)
		det *= m[i][i];

	return det;
}
