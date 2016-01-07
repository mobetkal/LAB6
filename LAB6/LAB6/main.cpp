#include <random>
#include <iostream>
#include<vector>
#include <algorithm>
#include <cmath>
#include "binaryheap.h"

using namespace std;

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
	uniform_int_distribution<int> dis(1, 10);
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
	for_each(vec.begin(), vec.end(), [](int val){cout << val << " "; });
	cout << "\n\n\n";

	// ----------------------------------------- ZAD 2
	cout << "ZADANIE 2\n\n\n";
	sort(vec.rbegin(), vec.rend());//odwrocona kolejnosc

	//Wyświetlanie
	cout << "Elementy odwrocone: \n";
	for_each(vec.begin(), vec.end(), [](int val){cout << val << " "; });
	cout << "\n\n\n";

	int val = 2;
	auto it = find(vec.begin(), vec.end(), val);
	if (it != vec.end())
		cout << "Znaleziono funkcja FIND: " << *it << endl;
	else
		cout << "BRAK\n";

	if (binary_search(vec.begin(), vec.end(), 2, [](int i, int j) { return (i>j); }))
		cout << "Znaleziono funkcja BINARY_SEARCH: " << val << endl;
	else 
		cout << "BRAK\n";

	//Po zrobieniu (binary_search(vec.begin(), vec.end(), 2)) nie znajdzie
	//należy dorobic do niego comparator [](int i, int j) { return (i>j); }

	cout << "\n\n\n";

	// ----------------------------------------- ZAD 3
	cout << "ZADANIE 3\n\n";

	zad3();

	// ----------------------------------------- ZAD 4
	cout << "ZADANIE 7\n\n";
	
	default_random_engine engine;
	uniform_int_distribution<int> dis2(8, 120);
	vector<int> Vector(40);
	generate(Vector.begin(), Vector.end(), [&]{ return dis2(engine); });

	for_each(Vector.begin(), Vector.end(), Print);
	cout << "\n\n\n";

	auto comp = [](int a, int b){ return (int)(a / 10) % 10 > (int)(b / 10) % 10; };
	BinaryHeap<int, decltype(comp)> Test(move(Vector), comp);

	//for_each(Test.GetVector().begin(), Test.GetVector().end(), [](int val){cout << val << " "; });
	while (!Test.CheckHeap())
	{
		cout << Test.GetValue() << ", ";
		Test.DeleteFromHeap();
	}

	system("PAUSE");
}