#include <random>
#include <iostream>
#include<vector>
#include <algorithm>
#include <utility>

using namespace std;
void Print_pair(pair<int, int> vec_pa)
{
	cout << vec_pa.first << " " << vec_pa.second << " | ";
}

void zad3()
{
	default_random_engine gen;
	poisson_distribution<int> dis(5); 
	vector<pair<int, int>> vec_pa(100);
	generate(vec_pa.begin(), vec_pa.end(), [&]{ return make_pair(dis(gen), dis(gen)); });


	for_each(vec_pa.begin(), vec_pa.end(), Print_pair);
	cout << "\n\n\n";

	sort(vec_pa.begin(), vec_pa.end(), [](const pair<int, int> &left, const pair<int, int> &right) { return left.second < right.second; });
	cout << "Wektor par 100 elem z rozkladem Poissona ze sr. 5.0 po sortowaniu wzgledem drugiego elementu pary: \n";
	for_each(vec_pa.begin(), vec_pa.end(), Print_pair);
	cout << "\n\n\n";

	sort(vec_pa.begin(), vec_pa.end(), [](const pair<int, int> &left, const pair<int, int> &right) { return left.first < right.first; });
	cout << "Wektor par 100 elem z rozkladem Poissona ze sr. 5.0 po sortowaniu wzgledem pierwszego elementu pary: \n";
	for_each(vec_pa.begin(), vec_pa.end(), Print_pair);
	cout << "\n\n\n";

	cout << "Wywolanie STABLE_SORT: \n\n";

	stable_sort(vec_pa.begin(), vec_pa.end());

	cout << "Wektor par 100 elem z rozkladem Poissona ze sr. 5.0 po sortowaniu STABLE_SORT: \n";
	for_each(vec_pa.begin(), vec_pa.end(), Print_pair);
	cout << "\n\n\n";

	//sortowanie SORT sortuje wzgledem pierwszej lub drugiej liczby w parze
	//sortowanie STABLE_SORT sortuje w kolejności liczb w parze
	//(1.1)(1.2)(1.3)(2.2)(3.5)(3.6)
	
}