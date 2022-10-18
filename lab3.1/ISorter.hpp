#ifndef ISORTER_HPP
#define ISORTER_HPP

#include "Sequence.hpp"

template<typename Type>
class ISorter {
public: 
	virtual Sequence<Type>* SortSequence(Sequence<Type>* seq, int(*cmp) (Type, Type)) = 0;
};


#endif  //  ISORTER_HPP