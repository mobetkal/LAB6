#include <random>
#include <iostream>
#include<vector>
#include <algorithm>
#include <utility>

using namespace std;

void zad3()
{
	default_random_engine gen;
	poisson_distribution<int> dis(5); ///5 to średnia z zadania
	vector<std::pair<int, int>> vec_pa(100);
	generate(vec_pa.begin(), vec_pa.end(), [&]{ return make_pair(dis(gen), dis(gen)); });


	for (int i = 0; i < vec_pa.size(); i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << vec_pa[i].first << ' ' << vec_pa[i].second << "  |  ";
	}
	cout << "\n\n\n";

	sort(vec_pa.begin(), vec_pa.end(), [](const pair<int, int> &left, const pair<int, int> &right) { return left.second < right.second; });
	cout << "Wektor par 100 elem z rozkladem Poissona ze sr. 5.0 po sortowaniu wzgledem drugiego elementu pary: \n";
	for (int i = 0; i < vec_pa.size(); i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << vec_pa[i].first << ' ' << vec_pa[i].second << "  |  ";
	}
	cout << "\n\n\n";

	sort(vec_pa.begin(), vec_pa.end(), [](const pair<int, int> &left, const pair<int, int> &right) { return left.first < right.first; });
	cout << "Wektor par 100 elem z rozkladem Poissona ze sr. 5.0 po sortowaniu wzgledem pierwszego elementu pary: \n";
	for (int i = 0; i < vec_pa.size(); i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << vec_pa[i].first << ' ' << vec_pa[i].second << "  |  ";
	}
	cout << "\n\n\n";

	cout << "Wywolanie STABLE_SORT: \n\n";

	stable_sort(vec_pa.begin(), vec_pa.end());
	cout << "Wektor par 100 elem z rozkladem Poissona ze sr. 5.0 po sortowaniu wzgledem drugiego elementu pary: \n";
	for (int i = 0; i < vec_pa.size(); i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << vec_pa[i].first << ' ' << vec_pa[i].second << "  |  ";
	}
	cout << "\n\n\n";

	sort(vec_pa.begin(), vec_pa.end());
	cout << "Wektor par 100 elem z rozkladem Poissona ze sr. 5.0 po sortowaniu wzgledem pierwszego elementu pary: \n";
	for (int i = 0; i < vec_pa.size(); i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << vec_pa[i].first << ' ' << vec_pa[i].second << "  |  ";
	}
	cout << "\n\n\n";
}