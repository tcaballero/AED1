#include "ejercicios.h"

void trasponer(vector<vector<int> > &m) {
	int aux;

	for(int i = 0; i < m.size(); i++){
		for(int j = i; j < m.size(); j++){
			aux = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = aux;
		}
	}
}

vector<vector<int> > multiplicar(vector<vector<int> > m1, vector<vector<int> > m2){
	vector<vector<int> > res(m1.size(), vector<int>(m2[0].size()));
	int producto;

	//Recorro las filas de m1
	for(int fila_m1 = 0; fila_m1 < m1.size(); fila_m1++){
		//Recorro las columnas de m2
		for(int col_m2 = 0; col_m2 < m2[0].size(); col_m2++){
			producto = 0;
			//Hago producto interno de la filas de m1 por las columnas de m2
			for(int k = 0; k < m2.size(); k++){
				producto += m1[fila_m1][k]*m2[k][col_m2];
			}
			res[fila_m1][col_m2] = producto;
		}
	}

	return res;
}

int promedioVecinos(vector<vector<int> > m, int f, int c){
	int sumaVecinos = 0;
	int cantVecinos = 0;

	for(int i = f-1; i <= f+1; i++){
		for(int j = c-1; j <= c+1; j++){
			if(0 <= i && i < m.size() && 0 <= j && j < m[0].size()){
				sumaVecinos += m[i][j];
				cantVecinos++;
			}
		}
	}

	return (sumaVecinos/cantVecinos);
}

vector<vector<int> > promediar(vector<vector<int> > m){
	vector<vector<int> > res(m.size(), vector<int>(m[0].size()));

	for(int i = 0; i < m.size(); i++){
		for(int j = 0; j < m[0].size(); j++){
			res[i][j] = promedioVecinos(m, i, j);
		}
	}

	return res;
}

bool esPico(vector< vector<int> > m, int i, int j){
	int f = i-1;
	int c;
	bool esPico = true;

	while(f <= i+1 && esPico){
		if(0 <= f && f < m.size()){
			c = j-1;
			while(c <= j+1 && esPico){
				if(0 <= c && c < m[0].size()){
					if((f != i || c != j) && (m[i][j] <= m[f][c])){
						esPico = false;
					}
				}
				c++;
			}
		}
		f++;
	}

	return esPico;
}

int contarPicos(vector<vector<int> > m){
	int cantPicos = 0;

	for(int i = 0; i < m.size(); i++){
		for(int j = 0; j < m[0].size(); j++){
			if(esPico(m, i, j)){
				cantPicos++;
			}
		}
	}

	return cantPicos;
}

int abs(int n){
	int res;

	if(n < 0){
		res = -n;
	}else{
		res = n;
	}

	return res;
}

bool seAmenazan(vector< vector<int> > m, int i1, int j1, int i2, int j2){
	return (i1 == i2 || j1 == j2 || abs(i1-i2) == abs(j1-j2));
}

bool amenazaAlguna(vector< vector<int> > m, int i1, int j1){
	int i2 = 0;
	int j2;
	bool hayAmenaza = false;

	while(i2 < m.size() && !hayAmenaza){
		j2 = 0;
		while(j2 < m[i2].size() && !hayAmenaza){
			if((i1 != i2 || j1 != j2) && m[i2][j2] == 1 && seAmenazan(m, i1, j1, i2, j2)){
				hayAmenaza = true;
			}
			j2++;
		}
		i2++;
	}

	return hayAmenaza;
}

bool existeAmenaza(vector< vector<int> > m){
	int i1 = 0;
	int j1;
	bool hayAmenaza = false;

	while(i1 < m.size() && !hayAmenaza){
		j1 = 0;
		while(j1 < m[i1].size() && !hayAmenaza){
			if(m[i1][j1] == 1 && amenazaAlguna(m, i1, j1)){
				hayAmenaza = true;
			}
			j1++;
		}
		i1++;
	}

	return hayAmenaza;
}

int hayAmenaza(vector<vector<int> > m){
	int res;

	if(existeAmenaza(m)){
		res = 1;
	}else{
		res = 0;
	}

	return res;
}
