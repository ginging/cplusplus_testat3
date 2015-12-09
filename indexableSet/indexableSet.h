#ifndef INDEXABLESET_H_
#define INDEXABLESET_H_
#include <set>
#include <iterator>
#include <iostream>
#include <stdexcept>

template <typename T, typename COMPARE=std::less<T>> class IndexableSet :public std::set<T, COMPARE>
{
	using std::set<T, COMPARE>::set;

public:
	T const & front() const{
		return *this->begin();
	}

	T const & back() const{
		return *(--this->end());
	}

	T const & at(int index) const {
		int size = this->size();

		if(index >= size || (index < (-1 * size))){
			throw std::out_of_range{"Index is out of range"};
		}
		if (index < 0) {
			index = size + index;
		}
		auto positionIterator = this->cbegin();
		std::advance(positionIterator, index);
		return *positionIterator;
	}

	T const & operator[](int index) const {
		return this->at(index);
	}

};


#endif /* INDEXABLESET_H_ */
