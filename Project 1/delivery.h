//delivery.h
//Chuluunbat Purev
//2021-9-1
//Header for class Delivery

#ifndef DELIVERY_H
#define DELIVERY_H

#include <string> // std::string
#include <ostream> // std::ostream
#include <cassert>  // For assert

// *********************************************************************
// class Delivery - Class definition
// *********************************************************************

class Delivery{
public:

	//Default Ctor
	//sets the product to ("UNSPECIFIED"), the quantity to zero, and the month to one (meaning January).
	Delivery() : _name("UNSPECIFIED"), _quantity(0), _month(1) { assert(_quantity >= 0);}

	//str - product
	//q - quantity
	//m - month
	Delivery(const std::string &str, const unsigned int &q, const int &m): _name(str), _quantity(q), _month(m) {
		assert(_quantity >= 0);
		assert(0 < _month && _month < 13);
	}

	// ***** Delivery: General public functions *****
	//Get functions
	std::string getName() const{
		return _name;
	}
	int getQuantity() const{
		return _quantity;
	}
	int getMonth() const{
		return _month;
	}

	//Set functions
	void setName(const std::string & name){
		_name = name;
	}
	void setQuantity(const int & quan){
		assert(quan >= 0);
		_quantity = quan;
	}
	void setMonth(const int & month){
		assert(0 < month && month< 13);
		_month = month;
	}

	//Return true if quantity is 0
	//false if otherwise
	bool empty() const{
		if(_quantity == 0)
			return true;
		return false;
	}

	//Return members in a formated string e.g "Super Widget (42), Apr"
	std::string toString() const;

	// ***** Delivery: General public operators *****

	//op++
	//Increase quantity by one.
	Delivery & operator++(){
		++_quantity;

		return *this;
	}

	//op++ [post]
	//Increase quantity by one.
	Delivery operator++([[maybe_unused]] int dummy){

		auto save = *this;
        ++(*this);
        return save;
	}

	//op--
	//Decrease quantity by one.
	Delivery & operator--(){
		--_quantity;
		if(_quantity == -1)
			_quantity = 0;
		return *this;
	}

	//op-- [post]
	//Decrease quantity by one.
	Delivery operator--([[maybe_unused]] int dummy){

		 auto save = *this;
        --(*this);
        return save;
	}


private:
	std::string _name; //Name of product
	int _quantity; //Quantity of ordered product
	int _month; // Which month to deliver (range 1..12)

}; //End of class Delivery

// *********************************************************************
// class Delivery - Declarations of associated global operators
// *********************************************************************
//Functions defined in source file.

//Return true if product name, quantity and month matches.
bool operator==(const Delivery& lhs, const Delivery& rhs);

//Return true if one of the members are not equal.
bool operator!=(const Delivery& lhs, const Delivery& rhs);

//Prints in given Delivery object as defined in toString().
std::ostream & operator<<(std::ostream & str, const Delivery & obj);

#endif // DELIVERY_H