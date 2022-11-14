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
	for (int i = 0; i < newSeq->GetLength(); ++i) {
		for (int j = 0; j <= i; ++j) {
			if (!cmp(newSeq->Get(j - 1), newSeq->Get(j))) {
				newSeq->Swap(j - 1, j);
			}
		}
	}

	return newSeq;
}

#endif  //  INSERTIONSORT_HPP