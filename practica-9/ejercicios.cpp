#include "ejercicios.h"
#include <iostream>

// Ejercicio 1
vector<int> subseq(vector<int> v, int i, int j){
	vector<int> res;

	for(int k = i; k <= j; k++)
		res.push_back(v[k]);

	return res;
}

vector<int> mesetaMasLarga(vector<int> v){

	int i = 0;
	int d = 0;
	int h = 0;
	int maxD = 0;
	int maxH = 0;

	while(i < v.size() - 1){
		d = i;
		while(i < v.size() - 1 && v[i] == v[i+1])
			i++;
		h = i;

		if(h-d+1 > maxD - maxH + 1){
			maxD = d;
			maxH = h;
		}
		i++;
	}

	return subseq(v, maxD, maxH);
}

// Ejercicio 3
int sucesivosDesde(vector<int> v, int desde){
	int cantSucesivos = 1; // Contamos el elemento v[desde]
	int ultimo = desde;

	for(int i = desde + 1; i < v.size(); i++){
		if(v[ultimo] <= v[i]){
			cantSucesivos++;
			ultimo = i;
		}
	}

	return cantSucesivos;
}

int infrasecuenciaMayor(vector<int> v){
	int max = 1;
	int ultimo = 0;

	for(int i = 0; i < v.size(); i++){
		for(int j = i + 1; j < v.size(); j++){
			int sucesivos = 1; // Contamos el elemento v[i]

			if(v[i] <= v[j])
				sucesivos += sucesivosDesde(v, j);

			if(sucesivos > max)
				max = sucesivos;
		}
	}

	return max;
}

// Ejercicio 4
vector<vector<int> > productoCartesiano(vector<int> v1, vector<int> v2){
	vector<vector<int> > res(v1.size()*v2.size(), vector<int>(2));
	int k = 0;

	for(int i = 0; i < v1.size(); i++){
		for(int j = 0; j < v2.size(); j++){
			//cout << "[" << v1[i] << ", " << v2[j] << "]" << "\n";
			res[k][0] = v1[i]; //res[v2.size() * i + j]
			res[k][1] = v2[j];
			k++;
		}
	}

	for(int i = 0; i < res.size(); i++){
		cout << "[" << res[i][0] << ", " << res[i][1] << "]" << "\n";
	}

	return res;
}
