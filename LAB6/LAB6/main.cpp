#include <random>
#include <iostream>
#include<vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool funkcja_odwr(int i, int j) { return (i>j); }
void zad3();

void main()
{
	// ----------------------------------------- ZAD 1
	cout << "ZADANIE 1\n\n";
	default_random_engine gen;
	uniform_int_distribution<> dis(1, 10);
	vector<int> vec(100);
	generate(vec.begin(), vec.end(), [&]{ return dis(gen); });///[&] wszyst zmienne przez ref

	//Wyświetlanie
	cout << "Wygenerowany wektor 100 elementow: \n";
	for (int i = 0; i < vec.size(); i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << ' ' << vec[i];
	}
	cout << "\n\n\n";


	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	//Wyświetlanie
	cout << "Elementy unikalne: \n";
	for (int i = 0; i < vec.size(); i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << ' ' << vec[i];
	}
	cout << "\n\n\n";

	// ----------------------------------------- ZAD 2
	cout << "ZADANIE 2\n\n\n";
	sort(vec.rbegin(), vec.rend());//odwrocona kolejnosc

	//Wyświetlanie
	cout << "Elementy odwrocone: \n";
	for (int i = 0; i < vec.size(); i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << ' ' << vec[i];
	}
	cout << "\n\n\n";

	//std::vector<int>::iterator it;
	int val = 2;
	auto it = find(vec.begin(), vec.end(), val);
	if (it != vec.end())
		std::cout << "Znaleziono funkcja FIND: " << *it << '\n';
	else
		std::cout << "BRAK\n";

	if (binary_search(vec.begin(), vec.end(), 2, funkcja_odwr))
		cout << "Znaleziono funkcja BINARY_SEARCH: " << val << '\n';
	else 
		cout << "BRAK\n";
	cout << "\n\n\n";

	// ----------------------------------------- ZAD 3
	cout << "ZADANIE 3\n\n";

	zad3();

	// ----------------------------------------- ZAD 4
	cout << "ZADANIE 4\n\n";

	//JESZCZE BRAK! :)

	system("PAUSE");
}