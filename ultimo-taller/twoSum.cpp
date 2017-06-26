#include <algorithm>
#include "twoSum.h"

pair<int, int> twoSum(vector<int> v, int k){
	int izq = 0;
	int der = v.size() - 1;
	pair<int, int> res;

	sort(v.begin(), v.end());

	while(izq < der && v[izq] + v[der] != k){
		if(v[izq] + v[der] < k)
			izq++;
		else
			der--;
	}

	if(izq == der)
		res = make_pair(-1, v.size());
	else
		res = make_pair(izq, der);

	return res;
}
