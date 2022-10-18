#ifndef CHOOSENSORT_HPP
#define CHOOSENSORT_HPP

#include "ISorter.hpp"

template<typename Type>
class ChoosenSort : public ISorter<Type> {
public:
	Sequence<Type>* SortSequence(Sequence<Type>* seq, int(*cmp) (Type, Type)) override;
};

template<typename Type>
Sequence<Type>* ChoosenSort<Type>::SortSequence(Sequence<Type>* seq, int(*cmp) (Type, Type)) {
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

#endif  //  CHOOSENSORT_HPP