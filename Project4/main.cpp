#include "hdtcount.h"
#include <iostream>
#include <vector>
int main(){

		
	std::cout << hdtCount(3,2,2,1,0,0) << std::endl; // 1

	std::cout << hdtCount(4,1, 1,0, 3,0) << std::endl; // 0
	std::cout << hdtCount(4,3, 2,0, 3,2) << std::endl; // 4

	std::cout << hdtCount(   2,   7,  0,  0,  1,  0) << std::endl; //13

	std::cout << hdtCount(   8,   5,  6,  4,  7,  4) << std::endl; //8291

	return 1;
}