#include <algorithm>
#include "threeSum.h"
#include "twoSum.h"

vector<int> subVector(vector<int> v, int desde, int hasta){
	vector<int> res;

	for(int i = desde; i < hasta; i++)
		res.push_back(v[i]);

	return res;
}

// Supongamos |v| > 2
vector<int> threeSum(vector<int> v, int k){
	int j;
	vector<int> res;
	vector<int> comp;
	pair<int, int> p;

	sort(v.begin(), v.end());

	for(int i = 0; i < v.size(); i++)
		comp.push_back(k - v[i]);

	j = 1;
	p = twoSum(subVector(v, j, v.size()), comp[j - 1]);

	while(j < v.size() - 2 && p.first == -1 && p.second == v.size() - j){
		j++;
		p = twoSum(subVector(v, j, v.size()), comp[j - 1]);
	}

	res.push_back(p.second + j);
	res.push_back(p.first + j);
	res.push_back(j);

	return res;
}
