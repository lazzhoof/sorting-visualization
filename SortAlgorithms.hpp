#ifndef SORT_ALGORITHMS_H
#define SORT_ALGORITHMS_H

#include <vector>
#include "I_SortAlgorithm.hpp"

class BubbleSort : public ISortAlgorithm {
public:
	BubbleSort(std::vector<int>& array);
	bool step() override;
	bool isSorted() const override;

private:
	std::vector<int>& arr;
	size_t i, j;
	bool sorted;
};

#endif