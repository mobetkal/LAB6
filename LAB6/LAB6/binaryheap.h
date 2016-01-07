#pragma once
#include <iostream>
#include <algorithm>
#include <vector>


template <class T, class Comp>
class BinaryHeap
{
	const Comp& comparator;
	std::vector<T> Wector;

public:
	BinaryHeap(std::vector<T>&& Wector, const Comp& comparator) : Wector(std::move(Wector)), comparator(comparator)
	{
		std::make_heap(this->Wector.begin(), this->Wector.end(), comparator);
	}
	void AddToHeap(const T& value)
	{
		Wector.push_back(value);
		std::push_heap(Wector.begin(), Wector.end(), comparator);
	}
	const T& GetValue()
	{
		return *Wector.begin();
	}
	bool DeleteFromHeap()
	{
		if (!CheckHeap())
		{
			std::pop_heap(Wector.begin(), Wector.end(), comparator);
			Wector.pop_back();
			return true;
		}
		else
			return false;
	}
	bool CheckHeap()
	{
		if (Wector.size() > 0)
			return false;
		else
			return true;
	}
	std::vector<T>& GetVector() { return Wector; }
};