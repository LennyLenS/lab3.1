#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include <iostream>
#include "ISorter.hpp"

template<typename Type>
class InsertionSort : public ISorter<Type> {
public:
	Sequence<Type>* SortSequence(Sequence<Type>* seq, int(*cmp) (Type, Type)) override;
};

template<typename Type>
Sequence<Type>* InsertionSort<Type>::SortSequence(Sequence<Type>* seq, int(*cmp) (Type, Type)) {
	Sequence<Type>* newSeq = seq->GetCopy();
	for (int i = 1; i < newSeq->GetLength(); ++i) {
		for (int j = i; j > 0; --j) {
			if (cmp(newSeq->Get(j), newSeq->Get(j - 1))) {
				newSeq->Swap(j - 1, j);
			}
			else {
				break;
			}
		}
	}

	return newSeq;
}

#endif  //  INSERTIONSORT_HPP