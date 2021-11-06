#include "delivery.h"
#include <iostream>
int main(){

	Delivery a("Super Widget", 42, 4);

	std::cout << a.toString() << std::endl;

	return 1;
}