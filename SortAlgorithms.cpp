#include "SortAlgorithms.hpp"
#include <utility>
#include <algorithm>

BubbleSort::BubbleSort(std::vector<int>& array)
	: arr(array), i(0), j(0), sorted(false) {}

bool BubbleSort::step() {
	if ((i) < arr.size()) {
		if ((j) < arr.size() - (i)-1) {
			if (arr[(j)] > arr[(j)+1]) {
				std::swap(arr[(j)], arr[(j)+1]);
			}
			(j)++;
		}
		else {
			(j) = 0;
			(i)++;
		}
	}
	else {
		sorted = true;
	}
	return sorted;
}
// TODO:how to send the state of algorithm when to values are compared?
// TODO:how to store sorting algorithms?

bool BubbleSort::isSorted() const {
	return sorted;
}

