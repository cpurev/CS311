//ssarray.h
//Chuluunbat Purev
//2021-9-11
//
//Template class SSArray(Somewhat Smart Array)

#ifndef _SSARRAY_H_
#define _SSARRAY_H_

#include <cstddef>	// std::size_t
#include <algorithm>	// std::copy
#include <utility>	//std::swap
#include <cassert> //std::assert


// *********************************************************************
// class SSArray - Class definition
// *********************************************************************


// class SSArray
// Somewhat Smart Array, with client-specified value type
// Invariants:
//     _size must be non-negative integer, pointers created with given size and with their default ctors.
// Requirements on Types:
//     T must have a copy ctor, a (non-throwing) dctor and op[].
template<typename T>
class SSArray{
	// ***** SSArray: Types *****
public:

    using size_type = std::size_t;  // Unsigned type for size of array,
                                    //  indices
    using value_type = T;         // Type of item in this container

    // ***** SSArray: Ctors, Dctors, op=  *****
public:
	//Default ctor
	//creates size of 8.
	SSArray() : _ptr(new value_type[size_type(8)]), _size(size_type(8)) {}

	//Dctor
	//Delete dynamically allocated pointer(_ptr)
	~SSArray() noexcept{
		delete [] _ptr;
	}

	//Copy ctor
	//Using STL copy, copy right side object(other) to left side(this).
	//Invariant:
	//			both objeccts has to be the same type, or else compiler error.
	SSArray(const SSArray & other) : _ptr(new value_type[other.size()]), _size(other.size()){
		std::copy(other.begin(), other.end(), begin());
	}

	//Move ctor
	//Set ptr to nullptr and size to 0.
	//Invariant:
	//			both objeccts has to be the same type, or else compiler error.
	SSArray(SSArray && other) noexcept : _ptr(other.begin()), _size(other.size()){
		other._ptr = nullptr;
		other._size = 0;
	}

	//Copy assignment
	SSArray & operator=(const SSArray & rhs){
		SSArray copy_of_rhs(rhs);
		swap(copy_of_rhs);
		return *this;
	}

	//Move assignment
	SSArray & operator=(SSArray && rhs) noexcept{
		swap(rhs);
		return *this;
	}

	//1-param ctor
	//		size: set size
	SSArray(size_type size) : _ptr(new value_type[size]), _size(size) {}

	//2-parameters ctor
	//		size: set size
	//		value: a value in value_type to fill array
	SSArray(size_type size, value_type value) : _ptr(new value_type[size]),_size(size){
		for(size_type i = 0; i < _size; i++){
			_ptr[i] = value;
		}
	}


	// ***** SSArray: Functions *****
public:
	//return number of items in array
	size_type size() { return _size; }

	size_type size() const { return _size; }

	//return starting pointer, return item 0
	value_type * begin() { return _ptr; }

	const value_type * begin() const { return _ptr; }

	//return just past last pointer, return item size
	value_type * end() { return _ptr + _size;}

	const value_type * end() const { return _ptr + _size;}

	//op[]
	//Given integer subscript from 0 to size - 1, return a reference to proper item.
	value_type & operator[](size_type ix) { return _ptr[ix];}

	const value_type & operator[](size_type ix) const { return _ptr[ix];}

private:
	//1-param
	//Swap this objects contents with other objects contents
	//Using STL swap.
	void swap(SSArray & other) noexcept{
		std::swap(_ptr, other._ptr);
		std::swap(_size, other._size);

	}

	// ***** SSArray: Data members  *****
private:
	value_type * _ptr; // Points to the start of array;

	size_type _size; // Array size;
};


	// ***** SSArray: Global overlaoded functions  *****

// op==
// Strict comparing, must be same size and all eleemnts must be same.
// Invariant:
//			both objects must have same value_type or it will throw compiler error.
template<typename T>
bool operator== (const SSArray<T>& lhs, const SSArray<T>& rhs){
	if(lhs.size() == rhs.size()){
		for(size_t i = 0; i < rhs.size(); ++i){
			if(lhs[i] != rhs[i])
				return false;	//if both object elements don't match
		}
	}
	else
		return false; //if both objects do not have same size

	return true; //passed all test
}
//op !=
//Call op== and negate it.
template<typename T>
bool operator!=(const SSArray<T>& lhs, const SSArray<T>& rhs){ return !(lhs == rhs); }

//op <
//lexicographic order comparing, if a[0] < b[0] then a < b. Otherwise, proceed to next index a[1] < b[1], if true then a < b
//if smallest object iterated throught and it was all equal up till then size will be compared.
//Invariant:
//			Both object has to have same value_type, or else compiler error.
template<typename T>
bool operator<(const SSArray<T>& lhs, const SSArray<T>& rhs){

	//for loop till the smallest array size to not go out of bounds(segfault).
	for(size_t i =  0; i < ((lhs.size() < rhs.size()) ? lhs.size() : rhs.size()); ++i){
		if(lhs[i] < rhs[i])
			return true;
		if(rhs[i] < lhs[i]) // Because GG did not write operator> in test class.
			return false;
	} 

	if(lhs.size() < rhs.size())
		return true;	//(maybe smallest) array have same elements as other array thus comparing size

	return false;	//failed all test
}
//op>
// Using op< but swapping the objects.
//Invariant:
//			Both object has to have same value_type, or else compiler error.
template<typename T>
bool operator>(const SSArray<T>& lhs, const SSArray<T>& rhs){ return rhs < lhs; }

//op<=
//Using op> and negate it.
//Invariant:
//			Both object has to have same value_type, or else compiler error.
template<typename T>
bool operator<=(const SSArray<T>& lhs, const SSArray<T>& rhs){ return !(lhs > rhs); }

//op>=
//Using op< and negate it.
//Invariant:
//			Both object has to have same value_type, or else compiler error.
template<typename T>
bool operator>=(const SSArray<T>& lhs, const SSArray<T>& rhs){ return !(lhs < rhs); }

#endif // _SSARRAY_H_