//dp6.h
// Chuluunbat Purev
// Nov-1-2021
//
//Header for DP6
// A: Reversing Single List
//		Efficient reversing function for a Linked List with smart pointers.
// B: Associative Dataset Class Template
//		A class template that uses a Linked List to hold an associative dataset. 
//		Will also use smart pointers.

#ifndef _DP6_HEADER_INCLUDED
#define _DP6_HEADER_INCLUDED

#include "llnode2.h"

#include <memory>	// For std::unique_ptr & std::make_unique
#include <iostream>
#include <utility>  // For std::move

//reverseList ~ A
//Given a unique_ptr to a Linked List—an empty unique_ptr if the list is empty.
//It alters the list so that the values appear in reverse order. 
//A pointer to the new list is returned via the reference parameter.
// Strong Guarantee
// Exception Neutral
template<typename ValType>
void reverseList(std::unique_ptr<LLNode2<ValType>> & head){

	std::unique_ptr<LLNode2<ValType>> newHead = nullptr;

	while(head){
		auto temp = std::move(newHead);
		auto temp2 = std::move(head->_next);
		newHead = std::move(head);
		head = std::move(temp2);
		newHead -> _next = std::move(temp);
	}

	head = std::move(newHead);

	return;
}


// *********************************************************************
// class LLMap - Struct definition
// *********************************************************************

//class LLMap ~ B
// Manages an associative dataset consisting of key-value pairs.
// The types of the keys (the key type) and associated values (the data type) should be specified by the client.
// Duplicate keys not be allowed. Determining whether two keys are the same is done by using the equality (==) operator.
//Invariants:
//			None
//Requirements on Types:
//			type K must have op==
template <typename K, typename V>
class LLMap{

// ***** LLMap: types *****
public:

	//key_type: type of keys
	using key_type = K;

	//value_type: type of data item
	using value_type = V;

// ***** Counter: Ctors, dctor, op= *****
public:

	//Default ctor
	//Creates an empty list
	//No-Throw Guarantee
	LLMap() : _data(nullptr){}

	//Dctor
	//unique_ptr is RAII object, thus we do not need to do clean up.
	//No-Throw Guarantee
    ~LLMap() = default;

	// No copy/move operations.
    LLMap(const LLMap & other) = delete;
    LLMap & operator=(const LLMap & other) = delete;
    LLMap(LLMap && other) = delete;
    LLMap & operator=(LLMap && other) = delete;

// ***** LLMap: Member functions *****
public:

	//size
	//No-Throw Guarantee
	//Note:
	//		I could have just used LLNode2::size() but it has the same name and it wont overload for some reason??????
	std::size_t size() const {
		auto p = _data.get();       // Iterates through list
		std::size_t counter = 0;  	// Number of nodes so far
		while (p != nullptr)
		{
		    p = p->_next.get();
		    ++counter;
		}
		return counter;
	}
	
	//empty
	//No-Throw Guarantee
	bool empty() const{
		return _data ? false : true;
	}

	//find
	//One parameter, key. Finds that key and returns the pointer to the associated value.
	//If not found return null.
	// Requirements on Types:
	//     Key must have a op==.
	//No-Throw Guarantee
	const value_type * find(const key_type & Key) const{

		auto p = _data.get();  

		while(p){
			if(p -> _data.first == Key){
				return &p->_data.second;
			}

			p = p->_next.get();

		}	

		return nullptr;
	}

	// find
	// One parameter, key. Finds that key and returns the pointer to the associated value.
	// If not found return null.
	// Requirements on Types:
	//     Key must have a op==.
	// No-Throw Guarantee
	value_type * find(const key_type & Key) {

		auto p = _data.get();  

		while(p){
			if(p -> _data.first == Key)
				return &p->_data.second;

			p = p->_next.get();
		}	

		return nullptr;
	}

	// insert
	// If an equal Key is not in dateset, then Val is inserted into the front.
	// If an equal Key exists in dataset, change it to Val
	// Strong Guarantee
	void insert(key_type Key, value_type Val){
		auto temp = find(Key);

		if(_data == nullptr || !temp){
			push_front(_data, std::make_pair(Key, Val));
			return;
		}

		*temp = Val;
		return;
	}

	// erase
	// If an equal key lies in the dataset, then that key-value pair is removed.
	// If an equal key does not lie in the dataset, then the function does nothing.
	// No-Throw Guarantee
	void erase(const key_type & Key){

		auto p = _data.get(); 
    	auto prev = _data.get(); 

	    while(p){
	        if(p -> _data.first == Key){
	            prev->_next = std::move(p->_next);
	            break;
	        }

	        prev = p;
	        p = p->_next.get();

	    } 	

		return;
	}

	// Traverse
	// The passed function is expected to take two parameters, key type and data type, and return nothing.
	// The passed function is called on each key-value pair in the dataset.
	// No-Throw Guarantee
	template <typename T>
	void traverse(T f){

		auto p = _data.get();      // Iterates through list
		while (p != nullptr)
		{
			f(p->_data.first, p->_data.second);
		    p = p->_next.get();
		}

		return;

	}

// ***** LLMap: data member *****
private:

    std::unique_ptr<LLNode2<std::pair<key_type, value_type>>> _data;	//Data for this node

}; // End class LLMap

#endif //_DP6_HEADER_INCLUDED