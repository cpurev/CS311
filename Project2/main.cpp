#include "ssarray.h"

#include <iostream>
#include <utility>
#include <string>

class Count{
public:
	Count(){
		++_ctorCount;
	}
	~Count(){
		--_ctorCount;
		++_DctorCount;
	}
	static size_t _ctorCount;
	static size_t _DctorCount;
};

size_t Count::_ctorCount = size_t(0);
size_t Count::_DctorCount = size_t(0);

int main(){
	
	SSArray<std::string> ss1;
	SSArray<int> ss2;

	std::cout << ((ss1 == ss2) ? "yes" : "no") << std::endl;

	return 1;
}