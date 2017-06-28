/*
 * Dada una matriz cuadrada A con coeficientes enteros,
 * escribir un algoritmo que calcule el producto A.A^t siendo A^t la matriz transpuesta de A.
 */

#include "header.h"

matriz transpuesta(matriz m){
	matriz t(m.size(), vector<int>(m.size()));

	for(int i = 0; i < m.size(); i++){
		for(int j = 0; j < m[0].size(); j++){
			t[i][j] = m[j][i];
		}
	}

	return t;
}

int productoInterno(vector<int> v1, vector<int> v2){
	int producto = 0;

	for(int i = 0; i < v1.size(); i++)
		producto += v1[i] * v2[i];

	return producto;
}

vector<int> columna(matriz m, int c){
	vector<int> col;

	for(int i = 0; i < m.size(); i++)
		col.push_back(m[i][c]);

	return col;
}

matriz producto(matriz m1, matriz m2){
	matriz prod(m1.size(), vector<int>(m2[0].size()));

	for(int i = 0; i < m1.size(); i++){
		for(int j = 0; j < m2[0].size(); j++){
			prod[i][j] = productoInterno(m1[i], columna(m2, j));
		}
	}

	return prod;
}
