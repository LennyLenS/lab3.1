#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#include <iostream>

template<typename Type>
class LinkedList {
private:
	typedef struct element {
		Type value;
		element* next;
	}element;
	element* start;
	int lenght;

public:
	//constructs
	LinkedList(Type* items, int count);
	LinkedList();
	LinkedList(LinkedList <Type>* list);

	//getters
	Type GetFirst() const;
	Type GetLast() const;
	Type Get(int index) const;
	LinkedList<Type>* GetSubList(int startIndex, int endIndex) const;
	int GetLength() const;

	//setters
	void Append(Type item);
	void Prepend(Type item);
	void InsertAt(Type item, int index);
	void Set(Type item, int index);
	LinkedList<Type>* Concat(LinkedList<Type>* list);
};



//constructs
template<typename Type>
LinkedList<Type>::LinkedList() {
	start = new element;
	this->lenght = 0;
	this->start->next = nullptr;
}

template<typename Type>
LinkedList<Type>::LinkedList(Type* items, int count) {
	this->lenght = 0;
	for (int i = 0; i < count; ++i) {
		//system("pause");
		this->Append(items[i]);
	}
}

template<typename Type>
LinkedList<Type>::LinkedList(LinkedList <Type>* list) {
	this->lenght = 0;
	element* current = list->start->next;
	for (int i = 1; i < list->GetLength(); ++i) {
		this->Append(current->value);
		current = current->next;
	}
}



//getters
template<typename Type>
Type LinkedList<Type>::GetFirst() const {
	return this->start->value;
}

template<typename Type>
Type LinkedList<Type>::GetLast() const {
	element* current = this->start;
	for (int i = 0; i < this->lenght - 1; ++i) {
		current = current->next;
	}
	return current->value;
}

template<typename Type>
Type LinkedList<Type>::Get(int index) const  {
	if (index < 0 || index >= this->lenght) {
		//throw out_of_range("Out of range");
	}
	element* current = this->start;
	for (int i = 0; i < index; ++i) {
		current = current->next;
	}
	return current->value;
}

template<typename Type>
int LinkedList<Type>::GetLength()  const  {
	return this->lenght;
}

template<typename Type>
LinkedList<Type>* LinkedList<Type>::GetSubList(int startIndex, int endIndex) const {
	LinkedList<Type>* newlist = new LinkedList<Type>();
	int curpos = 0;
	element* current = this->start;
	for (int i = 0; i < this->lenght; ++i) {
		if (i >= startIndex && i <= endIndex) {
			newlist->Append(current->value);
		}
		current = current->next;
	}
	return newlist;
}


//setters
template<typename Type>
void LinkedList<Type>::Append(Type item) {
	if (this->lenght == 0) {
		this->start = new element;
		this->start->value = item;
		this->lenght++;
		//system("pause");
		return;
	}
	element* a = new element;
	a->value = item;
	a->next = nullptr;
	element* current = this->start;
	for (int i = 0; i < this->lenght - 1; ++i) {
		current = current->next;
	}
	current->next = a;
	this->lenght++;
}

template<typename Type>
void LinkedList<Type>::Prepend(Type item) {
	if (this->lenght == 0) {
		this->start->value = item;
		this->lenght++;
		return;
	}
	element* a = new element;
	a->value = item;
	a->next = this->start;

	this->start = a;
	this->lenght++;
}

template<typename Type>
void LinkedList<Type>::InsertAt(Type item, int index) {
	if (index < 0 || index >= lenght) {
		//throw out_of_range("Out of range");
	}
	if (this->lenght == 0) {
		this->start->value = item;
		this->lenght++;
		return;
	}
	element* a = new element;
	a->value = item;

	element* current = start;
	for (int i = 0; i < index - 1; ++i) {
		current = current->next;
	}

	a->next = current->next;
	current->next = a;
	this->lenght++;
}


template<typename Type>
void LinkedList<Type>::Set(Type item, int index) {
	if (index < 0 || index >= lenght) {
		//throw out_of_range("Out of range");
	}
	element* a = new element;
	a->value = item;

	element* current = start;
	for (int i = 0; i < index; ++i) {
		current = current->next;
	}

	current->value = item;
}


template<typename Type>
LinkedList<Type>* LinkedList<Type>::Concat(LinkedList<Type>* list) {
	if (this->lenght == 0) {
		this->start = list;
		this->lenght = list->GetLength();
		return this;
	}

	element* current = start;
	for (int i = 0; i < this->lenght; ++i) {
		current = current->next;
	}

	current->next = list->start;
	this->lenght = this->lenght + list->GetLength();
	return this;
}
#endif // !LINKED_LIST_H
