#include "ejercicios.h"
#include <iostream>

// Ejercicio 1
int indice_min_subsec(vector<int> v, int i, int j) {
	int l = j;
	int res = l;

	while( i <= l ){
		if( v[l] < v[res] ){
			res = l;
		}

		l--;
	}

	return res;
}

// Ejercicio 2
int sumatoria(vector<int> v) {
	int i = 1;
	int medio = v.size() / 2;
	int suma = 0;

	if( v.size() > 0 ){
		suma = v[medio];

		while( i <= medio ){
			suma += v[medio - i];

			if(medio + i < v.size()){
				suma += v[medio + i];
			}

			i++;
		}
	}

	return suma;
}

// Ejercicio 3
int mcd(int m, int n) {
	int a = m;
	int b = n;
	int mcd;

	while( a > 0 && b > 0 ){
		if( a > b ){
			a -= b;
		}else{
			b -= a;
		}
	}

	if( a == 0 ){
		mcd = b;
	}else{
		mcd = a;
	}

	return mcd;
}

// Ejercicio 4
pair<int, int> division(int n, int d) {
	int r = n;
	int q = 0;

	while( r >= d){

		q++;
		r -= d;

	}

	return make_pair(q,r) ;
}

// Ejercicio 5
void fibonaccizar(vector<int>& v) {
	int i = 2;
	int k;
	int vLen = v.size();

	if( vLen > 2 ){
		v[i] = v[i-1] + v[i-2];
		while( i < (vLen/2) + 1){
			k = 2*i-1;
			v[k] = v[k-1] + v[k-2];
			if( k+1 < vLen )
				v[k+1] = v[k] + v[k-1];
			i++;
		}
	}
}

// Ejercicio 6
bool existePico(vector<int> v) {

	int i = 1;

	while( i < v.size()-1 && (v[i-1] >= v[i] || v[i] <= v[i+1])){
		i++;
	}

	return (i < v.size() - 1);
}

// Ejercicio 7

void swap(vector<int>& v, int i, int j) {
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void ordenar(vector<int>& v) {
}

// Ejercicio 8
void ordenar2(vector<int>& v) {
}

// Ejercicio 9
int nonCrooks(vector<int> f, vector<int> g) {
	return 0;
}
