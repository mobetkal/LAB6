#include <random>
#include <iostream>
#include<vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool F_odwrotna(int i, int j) { return (i>j); }
void zad3();
void Print(int vec)
{
	cout << vec << " ";
}

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
	for_each(vec.begin(), vec.end(), Print);
	
	cout << "\n\n\n";


	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	//Po zrobieniu unique i erase skracającego tablicę nie będzie unikalnych elementów
	//bo usunie powtarzające się po sobie jak będzie 2 2 2 4 2 2 to powstanie 2 4 2
	//nalezy posortowac wektor :)

	//Wyświetlanie
	cout << "Elementy unikalne: \n";
	for_each(vec.begin(), vec.end(), Print);
	cout << "\n\n\n";

	// ----------------------------------------- ZAD 2
	cout << "ZADANIE 2\n\n\n";
	sort(vec.rbegin(), vec.rend());//odwrocona kolejnosc

	//Wyświetlanie
	cout << "Elementy odwrocone: \n";
	for_each(vec.begin(), vec.end(), Print);
	cout << "\n\n\n";

	int val = 2;
	auto it = find(vec.begin(), vec.end(), val);
	if (it != vec.end())
		cout << "Znaleziono funkcja FIND: " << *it << endl;
	else
		cout << "BRAK\n";

	if (binary_search(vec.begin(), vec.end(), 2, F_odwrotna))
		cout << "Znaleziono funkcja BINARY_SEARCH: " << val << endl;
	else 
		cout << "BRAK\n";

	//Po zrobieniu (binary_search(vec.begin(), vec.end(), 2)) nie znajdzie
	//należy dorobic do niego comparator F_odwrotna

	cout << "\n\n\n";

	// ----------------------------------------- ZAD 3
	cout << "ZADANIE 3\n\n";

	zad3();

	// ----------------------------------------- ZAD 4
	cout << "ZADANIE 4\n\n";

	//JESZCZE BRAK! :)

	system("PAUSE");
}