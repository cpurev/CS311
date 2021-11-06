//delivery.cpp
//Chuluunbat Purev
//2021-9-1
//Source for class Delivery

#include "delivery.h"

//Month string array
extern const std::string MON[12] ={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

std::string Delivery::toString() const{
		std::string str = _name;
		str += " (";
		str += std::to_string(_quantity);
		str += "), ";
		str += MON[_month - 1];

		return str;
}

//operator== (Delivery, Delivery)
bool operator==(const Delivery& lhs, const Delivery& rhs){
	return lhs.getName() == rhs.getName() && lhs.getQuantity() == rhs.getQuantity()
			&& lhs.getMonth() == rhs.getMonth();
}

//operator!= (Delivery, Delivery)
bool operator!=(const Delivery& lhs, const Delivery& rhs){
	return !(lhs == rhs); //DRY
}

//operator<< (ostream, Delivery)
std::ostream & operator<<(std::ostream & str, const Delivery & obj){
	return str << obj.toString(); //DRY
}