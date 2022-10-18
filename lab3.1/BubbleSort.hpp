#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

#include <iostream>
#include "ISorter.hpp"

template<typename Type>
class BubbleSort: public ISorter<Type> {
public:
	Sequence<Type>* SortSequence(Sequence<Type>* seq, int(*cmp) (Type, Type)) override;
};

template<typename Type>
Sequence<Type>* BubbleSort<Type>::SortSequence(Sequence<Type>* seq, int(*cmp) (Type, Type)) {
	Sequence<Type>* newSeq = seq->GetCopy();
	for (int i = newSeq->GetLength() - 1; i >= 0; --i) {
		for (int j = 1; j <= i; ++j) {
			if (!cmp(newSeq->Get(j - 1), newSeq->Get(j))) {
				newSeq->Swap(j - 1, j);
			}
		}
	}

	return newSeq;
}

#endif  //  BUBBLESORT_HPP