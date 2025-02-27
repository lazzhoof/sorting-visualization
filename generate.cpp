#include "generate.hpp"
#include <vector>
#include <time.h>
#include <utility>
#include <iostream>

std::vector<int> generateVector(int n)
{
	std::vector<int> v(n);

	for (int i = 0; i < n; i++)
		v[i] = i + 1;
	
	return v;
}

int getNum(std::vector<int>& v)
{
	int n = v.size();
	srand(time(NULL));
	int index = rand() % n;
	int num = v[index];

	std::swap(v[index], v[n - 1]);
	v.pop_back();

	return num;
}

std::vector<int> generatePermutation(std::vector<int>& v, int koef)
{
	std::vector<int> v_rand;
	while (v.size())
	{
		v_rand.push_back(getNum(v)*koef);
	}

	return v_rand;
}
