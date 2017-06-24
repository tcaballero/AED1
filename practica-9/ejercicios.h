#ifndef SRC_EJERCICIOS_H_
#define SRC_EJERCICIOS_H_

#include<vector>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

vector<int> mesetaMasLarga(vector<int> v);
vector<vector<int> > secuenciasConCerosNueves(int n);
vector<int> infrasecuenciaMayor(vector<int> v);
vector<vector<int> > productoCartesiano(vector<int> v1, vector<int> v2);
int distanciaHamming(vector<int> v1, vector<int> v2);
int quickSelect(vector<int> v, int k);
int indiceSuma(vector<int> v);
vector<vector<int> > comprimir(vector<int> v);
bool esSubcadena(string s1, string s2);
string subcadenaComunMasLarga(string s1, string s2);
string subcadenaOrdenadaDeLargoN(string s, int l);
string darVueltaPalabra(string s);

#endif /* SRC_EJERCICIOS_H_ */

