#include "header.h"

vector<int> proximaMesetaDesde(vector<int> v, int &desde){
	vector<int> meseta;

	meseta.push_back(v[desde]);
	while(desde < v.size() - 1 && v[desde] == v[desde + 1]){
		meseta.push_back(v[desde + 1]);
		desde++;
	}

	return meseta;
}

vector<int> mesetaMasLarga(vector<int> v){
	vector<int> meseta_max;
	vector<int> meseta;
	int i = 0;

	while(i < v.size()){
		meseta = proximaMesetaDesde(v, i);
    
		if(meseta.size() > meseta_max.size())
			meseta_max = meseta;

		i++;
	}

	return meseta_max;
}
