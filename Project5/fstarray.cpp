// FSTArray.cpp  INCOMPLETE
// VERSION 6
// Glenn G. Chappell
// Started: 2021-10-12
// Updated: 2021-10-20
//
// For CS 311 Fall 2021
// Source for class FSTArray
// Frightfully smart array of int
// Preliminary to Project 5


#include "fstarray.h"  // For class FSTArray definition
#include <algorithm>
using std::copy;


// *********************************************************************
// class FSTArray - Member function definitions
// *********************************************************************


// Copy ctor
// See header for info.
/*template<typename T>
FSTArray<T>::FSTArray(const FSTArray<T> & other)
    :_capacity(other._capacity),
     _size(other.size()),
     _data(other._capacity == 0 ? nullptr
                                : new value_type[other._capacity])
{
    copy(other.begin(), other.end(), begin());
    // The above call to std::copy does not throw, since it copies int
    // values. But if value_type is changed, then the call may throw, in
    // which case this copy ctor may need to be rewritten.
}*/


// Move ctor
// See header for info.
template<typename T>
FSTArray<T>::FSTArray(FSTArray<T> && other) noexcept
    :_capacity(other._capacity),
     _size(other._size),
     _data(other._data)
{
    other._capacity = 0;
    other._size = 0;
    other._data = nullptr;
}


// Copy assignment operator
// See header for info.
template<typename T>
FSTArray<T> & FSTArray<T>::operator=(const FSTArray<T> & other)
{
    //swap(other);
    return *this;
}


// Move assignment operator
// See header for info.
template<typename T>
FSTArray<T> & FSTArray<T>::operator=(FSTArray<T> && other) noexcept
{
    // TODO: WRITE THIS!!!
    return *this; // DUMMY
}


// resize
// See header for info.
template<typename T>
void FSTArray<T>::resize(FSTArray<T>::size_type newsize)
{
    // TODO: WRITE THIS!!!
}


// insert
// See header for info.
template<typename T>
typename FSTArray<T>::iterator FSTArray<T>::insert(FSTArray<T>::iterator pos,
                                  const FSTArray<T>::value_type & item)
{
    // TODO: WRITE THIS!!!
    return begin();  // DUMMY
}


// erase
// See header for info.
template<typename T>
typename FSTArray<T>::iterator FSTArray<T>::erase(FSTArray<T>::iterator pos)
{
    // TODO: WRITE THIS!!!
    return begin();  // DUMMY
}


// swap
// See header for info.
template<typename T>
void FSTArray<T>::swap(FSTArray<T> & other) noexcept
{
    std::swap(_capacity, other._capacity);
    std::swap(_size, other._size);
    std::swap(_data, other._data);
}
