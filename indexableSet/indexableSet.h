#ifndef INDEXABLESET_H_
#define INDEXABLESET_H_
#include <set>
#include <iterator>
#include <iostream>

template <typename T, typename COMPARE=std::less<T>> class IndexableSet :public std::set<T, COMPARE>
{
	using IndexableSetType = std::set<T, COMPARE>;
	using size_type = typename IndexableSetType::size_type;
	using std::set<T, COMPARE>::set;

	//IndexableSet()=default;

	//IndexableSet<T, COMPARE> iSet{};


public:
	T const & front(){
		return *this->begin();
	}

	T const & back(){
		return *this->end();
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

	decltype(auto) operator[](size_type index) const {
		return this->at(index);
	}

	decltype(auto) operator[](size_type index) {
			return this->at(index);
	}
};


#endif /* INDEXABLESET_H_ */
