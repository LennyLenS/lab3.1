#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP
#include <stdexcept>

template<typename Type>
class DynamicArray {
private:
	Type* arr;
	int size;

public:
	//constructs
	DynamicArray();
	DynamicArray(Type* items, int count);
	DynamicArray(int count);
	DynamicArray(DynamicArray<Type>& dynamicArray);

	//getters
	Type Get(int index) const;
	int GetSize() const;

	//setters
	void Set(int index, Type value);
	void Resize(int newSize);

	//operators
	Type& operator[] (int index) {
		return arr[index];
	}
	//destructor
	~DynamicArray() {
		delete [] arr;
		size = 0;
	}
};

//constructs
template<typename Type>
DynamicArray<Type>::DynamicArray() {
	this->arr = nullptr;
	this->size = 0;
}

template<typename Type>
DynamicArray<Type>::DynamicArray(Type* items, int count) {
	this->arr = new Type[count];
	memcpy(arr, items, count * sizeof(Type));
	this->size = count;
}

template<typename Type>
DynamicArray<Type>::DynamicArray(int count) {
	this->arr = new Type[count];
	this->size = count;
}

template<typename Type>
DynamicArray<Type>::DynamicArray(DynamicArray<Type>& dynamicArray) {
	this->size = dynamicArray.GetSize();
	this->arr = new Type[size];
	memcpy(arr, &dynamicArray, size * sizeof(Type));
}

//getters
template<typename Type>
Type DynamicArray<Type>::Get(int index) const{
	if (index < 0 || index >= size) {
		//throw out_of_range("Out of range");
	}
	return this->arr[index];
}

template<typename Type>
int DynamicArray<Type>::GetSize() const {
	return this->size;
}

//setters
template<typename Type>
void DynamicArray<Type>::Set(int index, Type value) {
	if (index < 0 || index >= size) {
		//throw out_of_range("Out of range");
	}
	memcpy(this->arr + index, &value, sizeof(Type));
}

template<typename Type>
void DynamicArray<Type>::Resize(int newSize) {
	if (newSize < 0) {
		//throw invalid_argument("Invalid argument");
	}
	Type* new_arr = new Type[newSize];
	if(this->size > 0)
		memcpy(new_arr, this->arr, newSize * sizeof(Type));
	delete[] this->arr;
	this->arr = new_arr;
	this->size = newSize;
}
#endif