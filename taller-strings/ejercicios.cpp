#include "ejercicios.h"

using namespace std;

int cantApariciones(char c, string s){

	int cant = 0;

	for(int i = 0; i < s.size(); i++){
		if(s[i] == c){
			cant++;
		}
	}

	return cant;
}

bool anagramas(string s1, string s2){

	bool sonAnagramas = true;

	if(s1.size() == s2.size()){
		for(int i = 0; i < s1.size(); i++){
			if(cantApariciones(s1[i], s1) != cantApariciones(s1[i], s2)){
				sonAnagramas = false;
			}
		}
	}else{
		sonAnagramas = false;
	}

	return sonAnagramas;
}

string darVuelta(string s){

	string sResult;

	for(int i = 0; i < s.size(); i++){
		sResult.push_back(s[s.size()-1-i]);
	}

	return sResult;
}

vector<string> split(string s, char delim){

	string word;
	vector<string> sResult;
	int i = 0;

	while( i < s.size() ){
		while( i < s.size() && s[i] != delim){
			word.push_back(s[i]);
			i++;
		}

		if( word.size() > 0){
			sResult.push_back(word);
			word.clear();
		}

		i++;

	}

	return sResult;
}

string darVueltaPalabra(string s){

	string sResult;

	if(s.size() > 0){

		vector<string> vSplit = split(s, ' ');

		for(int i = 0; i < vSplit.size() - 1; i++){

			sResult += vSplit[vSplit.size()-1-i];
			//for(int j = 0; j < vSplit[vSplit.size()-1-i].size(); j++){
			//	sResult.push_back(vSplit[vSplit.size()-1-i][j]);
			//}
			sResult.push_back(' ');
		}


		//for(int j = 0; j < vSplit[0].size(); j++){
		//	sResult.push_back(vSplit[0][j]);
		//}

		sResult += vSplit[0];
	}

	return sResult;
}

bool subsecuencia(string s1, string s2) {

	int k = 0; // Indice en s1
	int i = 0; // Indice en s2

	while( i < s2.size() && k < s1.size()){
		if(s2[i] == s1[k]){
			k++;
		}
		i++;
	}

	return (k == s1.size());

}

vector<vector<string> > agruparAnagramas(vector<string> v){

	vector<vector<string>> vResult;

	if(v.size() > 0){

	}

	return {};
}

bool esPalindromo(string s){
	return true;
}

bool tieneRepetidos(string s){
	return true;
}

string rotar(string s, int j){
	return "";
}

string darVueltaK(string s, int k){
	return "";
}
