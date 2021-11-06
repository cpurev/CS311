// dp3.h 
// Chuluunbat Purev
// 2021-09-20
//
// For CS 311 Fall 2021
// Header for Project 3 functions

#ifndef FILE_DP3_H_INCLUDED
#define FILE_DP3_H_INCLUDED

#include "llnode.h"    // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function
#include <stdexcept>   // For std::out_of_range

//lookup
//Does look up and return specified index in Linked List.
//if not found throw out of range error
//Requirements on types:
//      LLNode is a forward iterator
//      ValueType must have copy assignment
//Pre:
//      index must be nonnegative
//      head must not be empty
// Throws out of range on index and empty head pointer.
template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head,
                 std::size_t index)
{
    if(index < 0 )
        throw std::out_of_range("Negative Index Error!");

    if(head == nullptr)
        throw std::out_of_range("Empty List!");

    auto p = head;

    for(std::size_t i = 0; i < index; i++){
        p = p->_next;

        if( p == nullptr)
            throw std::out_of_range("Out Of Range Error!");
    }
    return p->_data;
}


// Implementation in source file
void didItThrow(const std::function<void()> & ff,
                bool & threw);

//uniqueCount
//Count all the unique items within given range
//if empty return 0.
//long int not size_t to make compiler -Wsign-conversion error happy.
//Requirements on types:
//      RAIter must valid iterator
//Pre:
//      RAIter data must have operator==
template <typename RAIter>
std::size_t uniqueCount(RAIter first,
                        RAIter last)
{
    //Empty list check
    if( first == last)
        return 0;

    //Base case:
    //     If not empty then there atleast must be 1 unique item
    long int result = 1;

    //Find size of given range
    long int size = (last - first);
 
    // Pick all elements one by one
    for (long int i = 1; i < size; ++i){
        long int j = 0;//To save j

        for (j = 0; j < i; ++j)
            if (*(first + i) == *(first + j))
                break;
                
        
        if (i == j)
            ++result;
    }

    //To make compiler happy.
    return std::size_t(result);
}


// Implementation in source file
int gcd(int a,
        int b);


#endif  //#ifndef FILE_DP3_H_INCLUDED
