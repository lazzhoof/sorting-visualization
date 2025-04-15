#include "sorts.hpp"
#include <utility>

bool bubbleSortStep(std::vector<int>& v, int* i, int* j, int NUM_BARS)
{
	if ((*i) < NUM_BARS - 1)
	{
		if ((*j) < NUM_BARS - (*i) - 1)
		{
			if (v[(*j)] > v[(*j) + 1])
			{
				std::swap(v[(*j)], v[(*j) + 1]);
			}
			(*j)++;
		}
		else
		{
			(*j) = 0;
			(*i)++;
		}
		return true;
	}
	return false;
}
