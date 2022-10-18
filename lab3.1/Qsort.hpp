#ifndef QSORT_HPP
#define QSORT_HPP

#include <iostream>
#include "ISorter.hpp"

template<typename Type>
void Qsortfunc(Sequence<Type>* Seq, int left, int right, int(*cmp) (Type, Type));

template<typename Type>
class Qsort: public ISorter<Type> {
public:
	Sequence<Type>* SortSequence(Sequence<Type>* seq, int(*cmp) (Type, Type)) override;
};

template<typename Type>
Sequence<Type>* Qsort<Type>::SortSequence(Sequence<Type>* seq, int(*cmp) (Type, Type)) {
	Sequence<Type>* newSeq = seq->GetCopy();
	Qsortfunc(newSeq, 0, newSeq->GetLength() - 1, cmp);
	return newSeq;
}

template<typename Type>
void Qsortfunc(Sequence<Type>* Seq, int left, int right, int(*cmp) (Type, Type)) {
	int l = left, r = right;
	Type mid = Seq->Get((r + l) / 2);
	while(l <= r) {
		while (l <= right && cmp(Seq->Get(l), mid)) {
			++l;
		}
		while (r >= left && cmp(mid, Seq->Get(r))) {
			--r;
		}
		if (l <= r) {
			Seq->Swap(l++, r--);
		}
	}

	if (left < r) {
		Qsortfunc(Seq, left, r, cmp);
	}
	if (right > l) {
		Qsortfunc(Seq, l, right, cmp);
	}
}


#endif  //  QSORT_HPP
