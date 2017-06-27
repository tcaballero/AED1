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

//Ejercicio 2
vector<vector<int> > generarSubsecuencias(vector<vector<int> > v){
	vector<vector<int> > res;

	// Para cada subsecuencia de v generamos 10 nuevas secuencias con los valores del 0 al 9
	for(int s = 0; s < v.size(); s++){
		for(int val = 0; val < 10; val++){
			vector<int> aux = v[s];
			aux.push_back(val);
			res.push_back(aux);
		}
	}

	return res;
}

vector<vector<int> > secuenciasConCerosNueves(int n){
	vector<vector<int> > base;

	// Creamos el arreglo base {{0}, ..., {9}}
	for(int i = 0; i < 10; i++){
		vector<int> aux;
		aux.push_back(i);
		base.push_back(aux);
	}

	// Por cada subsecuencia generamos 10 nuevas pusheando valores del 0 al 9
	for(int i = 1; i < n; i++){
		base = generarSubsecuencias(base);
	}

	return base;
}

// Ejercicio 3
vector<int> infrasecuenciaMayorDesde(vector<int> original, int desde, vector<int> actual){
	if(desde + 1 >= original.size() - 1)
		return actual;

	int ultimo = actual.size() - 1;

	if(actual[ultimo] < original[desde]){

		vector<int> aux = actual;
		aux.push_back(original[desde]);

		vector<int> infraConValor = infrasecuenciaMayorDesde(original, desde + 1, aux);
		vector<int> infraSinValor = infrasecuenciaMayorDesde(original, desde + 1, actual);

		if(infraConValor.size() > infraSinValor.size()){
			return infraConValor;
		}else{
			return infraSinValor;
		}
	}else{
		return infrasecuenciaMayorDesde(original, desde + 1, actual);
	}
}

vector<int> infrasecuenciaMayor(vector<int> v){
	vector<int> infraMax;

	infraMax.push_back(v[0]);
	for(int i = 0; i < v.size(); i++){
		vector<int> infraAux;
		infraAux.push_back(v[i]);
		infraAux = infrasecuenciaMayorDesde(v, i+1, infraAux);

		if(infraAux.size() > infraMax.size()){
			infraMax = infraAux;
		}
	}

	return infraMax;
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

// Ejercicio 5
bool pertenece(int value, vector<int> v){
	int i = 0;

	while(i < v.size() && v[i] != value)
		i++;

	return (i < v.size());
}

int distanciaHamming(vector<int> v1, vector<int> v2){
	int distancia = 0;

	for(int i = 0; i < v1.size(); i++){
		if(!pertenece(v1[i], v2))
			distancia++;
		if(!pertenece(v2[i], v1))
			distancia++;
	}

	return distancia;
}

// Ejercicio 6
int quickSelect(vector<int> v, int k){
	int kMin = 1;
	int i = 1;

	sort(v.begin(), v.end());
	// Supongo que existe kEsimo minimo
	while(i < v.size() && kMin < k){
		if(v[i] != v[i-1])
			kMin++;
		i++;
	}

	return v[i-1];
}

// Ejercicio 7
int suma(vector<int> v, int desde, int hasta){
	int suma = 0;

	for(int i = desde; i < hasta; i++)
		suma += v[i];

	return suma;
}

int indiceSuma(vector<int> v){
	int i = 0;

	while(i < v.size() && suma(v, 0, i) != suma(v, i, v.size()))
		i++;

	return i;
}

// Ejercicio 8
int consecutivosDesde(vector<int> v, int &desde){
	int consecutivos = 1;

	desde++;
	while(desde < v.size() && v[desde - 1] + 1 == v[desde]){
		consecutivos++;
		desde++;
	}

	return consecutivos;
}
vector<vector<int> > comprimir(vector<int> v){
	int i = 0;
	int k = 0;
	vector<vector<int> > res;

	while(i < v.size()){
		vector<int> comprimido;
		comprimido.push_back(v[i]);
		comprimido.push_back(consecutivosDesde(v, i));

		res.push_back(comprimido);
	}

	return res;
}

// Ejercicio 9
bool iguales(string s1, string s2){
	int i = 0;

	// Supongamos tamaños iguales
	while(i < s1.size() && s1[i] == s2[i])
		i++;

	return (i == s1.size());
}

string subcadena(string s, int desde, int hasta){
	string res;

	for(int i = desde; i < hasta; i++)
		res.push_back(s[i]);

	return res;
}

bool esSubcadena(string s1, string s2){
	int i = 0;

	while(i <= s2.size() - s1.size() && !iguales(s1, subcadena(s2, i, i + s1.size())))
		i++;

	return (i <= s2.size() - s1.size());
}

// Ejercicio 10
string subcadenaComunDeLargoN(string s1, string s2, int largo){
	int j = 0;

	// Voy tomando subcadenas de tamaño "largo" en s1 y veo si son subcadenas de s2
	while(j <= s1.size() - largo && !esSubcadena(subcadena(s1, j, j + largo), s2))
		j++;

	if(j <= s1.size() - largo)
		return subcadena(s1, j, j + largo);
	else
		return "";

}

// Pre: |s1| <= |s2|
string subcadenaComunMasLarga(string s1, string s2){
	string substr = "";
	int size = s1.size();
	int i = 0;

	while(1 < size - i && substr.size() == 0){
		substr = subcadenaComunDeLargoN(s1, s2, size - i);
		i++;
	}

	return substr;
}

// Ejercicio 11
string subcadenaOrdenadaDeLargoN(string s, int l){
	sort(s.begin(), s.end());

	return subcadena(s, 0, l);
}

// Ejercicio 12
vector<string> split(string s, char delim){

	string word;
	vector<string> res;
	int i = 0;

	while( i < s.size() ){
		while( i < s.size() && s[i] != delim){
			word.push_back(s[i]);
			i++;
		}

		if( word.size() > 0){
			res.push_back(word);
			word.clear();
		}

		i++;
	}

	return res;
}

string darVueltaPalabra(string s){

	char delim = '#';
	string res;

	if(s.size() > 0){

		vector<string> vSplit = split(s, delim);

		for(int i = 0; i < vSplit.size() - 1; i++){

			res += vSplit[vSplit.size()-1-i];
			res.push_back(delim);
		}

		res += vSplit[0];
	}

	return res;
}
