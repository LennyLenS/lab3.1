#ifndef SELECTIONSORT_HPP
#define SELECTIONSORT_HPP

#include "ISorter.hpp"

template<typename Type>
class SelectionSort : public ISorter<Type> {
public:
	Sequence<Type>* SortSequence(Sequence<Type>* seq, int(*cmp) (Type, Type)) override;
};

template<typename Type>
Sequence<Type>* SelectionSort<Type>::SortSequence(Sequence<Type>* seq, int(*cmp) (Type, Type)) {
	Sequence<Type>* newSeq = seq->GetCopy();
	for (int i = 0; i < newSeq->GetLength(); ++i) {
		int indexmin = i;
		for (int j = i; j < newSeq->GetLength(); ++j) {
			if (!cmp(newSeq->Get(indexmin), newSeq->Get(j))) {
				indexmin = j;
			}
		}
		newSeq->Swap(indexmin, i);
	}

	return newSeq;
}

#endif  //  SELECTIONSORT 