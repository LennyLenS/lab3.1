#ifndef ARRAY_SEQUENCE_HPP
#define ARRAY_SEQUENCE_HPP

#include <iostream>
#include "dynamic_array.hpp"
#include "Sequence.hpp"

template<typename Type>
class ArraySequence : public Sequence<Type> {
private:
	DynamicArray<Type>* arr;
public:
	//constructs
	ArraySequence();
	ArraySequence(Type* items, int count);
	ArraySequence(int count);
	ArraySequence(DynamicArray<Type>& dynamicArray);

	//getters
	Type GetFirst() const override;
	Type GetLast() const override;
	Type Get(int index) const override;
	int GetLength() const override;
	Sequence<Type>* GetSubsequence(int startIndex, int endIndex) const override;
	ArraySequence<Type>* GetCopy() override;
	//setters
	void Swap(int i, int j) override;
	void Append(Type item) override;
	void Prepend(Type item) override;
	void InsertAt(Type item, int index) override;
	void Set(Type item, int index) override;
	ArraySequence<Type>* Concat(Sequence<Type>* list) override;
	
	//operators
	Type& operator[] (int index);
	//destructs
	~ArraySequence() {
		delete this->arr;
	}
};


//constructs
template<typename Type>
ArraySequence<Type>::ArraySequence() {
	this->arr = new DynamicArray<Type>();
}

template<typename Type>
ArraySequence<Type>::ArraySequence(Type* items, int count) {
	this->arr = new DynamicArray<Type>(items, count);
}

template<typename Type>
ArraySequence<Type>::ArraySequence(int count) {
	this->arr = new DynamicArray<Type>(count);
}

template<typename Type>
ArraySequence<Type>::ArraySequence(DynamicArray<Type>& dynamicArray) {
	this->arr = new DynamicArray<Type>(dynamicArray);
}

//getters
template<typename Type>
Type ArraySequence<Type>::GetFirst() const {
	return	this->arr->Get(0);	
}

template<typename Type>
Type ArraySequence<Type>::GetLast() const {
	return	this->arr->Get(this->arr->GetSize() - 1);
}

template<typename Type>
Type ArraySequence<Type>::Get(int index) const {
	return this->arr->Get(index);
}

template<typename Type>
int ArraySequence<Type>::GetLength() const {
	return	this->arr->GetSize();
}

template<typename Type>
Sequence<Type>* ArraySequence<Type>::GetSubsequence(int startIndex, int endIndex) const {
	int size = endIndex - startIndex + 1;
	Type* elements = new Type[size];
	for (int i = 0; i < size; ++i) {
		elements[i] = this->arr->Get(startIndex + i);
	}

	ArraySequence<Type>* ArraySeq = new ArraySequence(elements, size);
	return ArraySeq;
}

template<typename Type>
ArraySequence<Type>* ArraySequence<Type>::GetCopy() {
	ArraySequence<Type>* new_element = new ArraySequence<Type>();
	for (int i = 0; i < this->GetLength(); ++i) {
		new_element->Append(this->Get(i));
	}
	return new_element;
}
//setters
template<typename Type>
void ArraySequence<Type>::Swap(int i, int j) {
	Type a = this->arr->Get(i), b = this->arr->Get(j);
	this->arr->Set(j, a);
	this->arr->Set(i, b);
}

template<typename Type>
void ArraySequence<Type>::Append(Type item) {
	this->arr->Resize(this->arr->GetSize() + 1);
	this->arr->Set(this->arr->GetSize() - 1, item);
}

template<typename Type>
void ArraySequence<Type>::Prepend(Type item) {
	this->arr->Resize(this->arr->GetSize() + 1);
	for (int i = this->arr->GetSize() - 1; i > 0; --i) {
		this->arr->Set(i, this->arr->Get(i - 1));
	}
	this->arr->Set(0, item);
}

template<typename Type>
void ArraySequence<Type>::InsertAt(Type item, int index) {
	this->arr->Resize(this->arr->GetSize() + 1);
	for (int i = this->arr->GetSize() - 1; i > index; --i) {
		this->arr->Set(i, this->arr->Get(i - 1));
	}
	this->arr->Set(index, item);
}

template<typename Type>
void ArraySequence<Type>::Set(Type item, int index) {
	this->arr->Set(index, item);
}

template<typename Type>
ArraySequence<Type>* ArraySequence<Type>::Concat(Sequence<Type>* list) {
	int size = this->arr->GetSize();
	this->arr->Resize(this->arr->GetSize() + list->GetLength());
	for (int i = size; i < this->arr->GetSize(); ++i) {
		this->arr->Set(i, list->Get(i - size));
	}
	return this;
}

//operators

template<typename Type>
Type& ArraySequence<Type>::operator[] (int index) {
	return this->arr[index];
}

#endif