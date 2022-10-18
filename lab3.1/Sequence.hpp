#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

template<typename Type>
class Sequence {
public:
	//getters
	virtual Type GetFirst() const = 0;
	virtual Type GetLast() const = 0;
	virtual Type Get(int index) const = 0;
	virtual int GetLength() const = 0;
	virtual Sequence<Type>* GetSubsequence(int startIndex, int endIndex) const = 0;
	//setters
	virtual void Swap(int i, int j) = 0;
	virtual void Append(Type item) = 0;
	virtual void Prepend(Type item) = 0;
	virtual void InsertAt(Type item, int index) = 0;
	virtual void Set(Type item, int index) = 0;
	virtual Sequence <Type>* Concat(Sequence <Type>* list) = 0;
	virtual Sequence<Type>* GetCopy() = 0;
	//destructor
	virtual ~Sequence() {}
};

#endif