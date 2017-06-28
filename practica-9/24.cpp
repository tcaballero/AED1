#include "header.h"

int intercambios(vector<int> v){
	vector<int> ordenado;

	for(int i = 0; i < v.size(); i++)
		ordenado.push_back(v[i]);

	sort(ordenado.begin(), ordenado.end());

	// La cantidad de intercambios va a ser la cantidad de elementos que no estén en la misma posición
	// en el vector v y el ordenado divido 2 (Cada 2 elementos es un swap)
	int en_posicion_distinta = 0;

	for(int i = 0; i < v.size(); i++){
		if(v[i] != ordenado[i])
			en_posicion_distinta++;
	}

	return (en_posicion_distinta / 2);
}
