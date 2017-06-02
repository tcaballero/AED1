#ifndef SRC_EJERCICIOS_H_
#define SRC_EJERCICIOS_H_

#include<vector>
#include <utility>
using namespace std;

int indice_min_subsec(vector<int> v, int i, int j);
int sumatoria(vector<int> v);
int mcd(int m, int n);
pair<int,int> division(int n, int d);
void fibonaccizar(vector<int>& v);
bool existePico(vector<int> v);
void ordenar(vector<int>& v);
void ordenar2(vector<int>& v);
int nonCrooks(vector<int> f, vector<int> g);
int plateau(vector<int> v);

#endif /* SRC_EJERCICIOS_H_ */
