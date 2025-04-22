#ifndef I_SORT_ALGORITHM_H
#define I_SORT_ALGORITHM_H

class ISortAlgorithm {
public:
	virtual bool step() = 0;
	virtual bool isSorted() const = 0;
	virtual ~ISortAlgorithm() = default;
};

#endif