#ifndef COUNTERSORT_HPP
#define COUNTERSORT_HPP

#include "ISorter.hpp"

template<typename Type>
class CounterSort : public ISorter<Type> {
public:
	Sequence<Type>* SortSequence(Sequence<Type>* seq, int(*cmp) (Type, Type)) override;
};

template<typename Type>
Sequence<Type>* CounterSort<Type>::SortSequence(Sequence<Type>* seq, int(*cmp) (Type, Type)) {
	Sequence<Type>* newSeq = seq->GetCopy();
	Type min_value = newSeq->GetFirst();
	Type max_value = newSeq->GetFirst();
	for (int i = 0; i < newSeq->GetLength(); ++i) {
		if (!cmp(newSeq->Get(i), max_value)) {
			max_value = newSeq->Get(i);
		}
		if (cmp(newSeq->Get(i), min_value)) {
			min_value = newSeq->Get(i);
		}
	}
	Type count = max_value - min_value + 1;

	Type* arr = new Type[count];
	for (int i = 0; i < count; ++i) {
		arr[i] = 0;
	}

	for (int i = 0; i < newSeq->GetLength(); ++i) {
		arr[newSeq->Get(i) - min_value]++;
	}

	int j = 0;
	for (int i = 0; i < count; ++i) {
		while (arr[i]) {
			newSeq->Set(i + min_value, j++);
			arr[i]--;
		}
	}

	delete[] arr;

	return newSeq;
}

#endif  //  COUNTERSORT 