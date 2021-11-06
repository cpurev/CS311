#include "dp6.h"
#include <iostream>
#include <sstream>

template <typename ValType>
void print_list(const std::unique_ptr<LLNode2<ValType>> & head,
                std::ostream & outstr = std::cout)
{
    auto p = head.get();
    while (p != nullptr)
    {
        outstr << p ->_data.first << "," << p ->_data.second;
        p = p->_next.get();
        if (p != nullptr)
            outstr << " ";
    }
    outstr << std::endl;
}

int main(){
    std::unique_ptr<LLNode2<std::pair<int, int>>> _data = nullptr;

    push_front(_data, std::make_pair(1, 11));
    push_front(_data, std::make_pair(2, 22));
    push_front(_data, std::make_pair(3, 33));
    push_front(_data, std::make_pair(4, 44));
    push_front(_data, std::make_pair(5, 55));
    push_front(_data, std::make_pair(6, 6));

    auto p = _data.get(); 
    auto prev = _data.get(); 

    while(p){
        if(p -> _data.first == 4){
            prev->_next = std::move(p->_next);
            break;
        }

        prev = p;
        p = p->_next.get();

    } 

    print_list(_data);

    /*
    const int SIZE = 10;  // Size for loops
    LLMap<int, int> m;
    for (int i = 0; i < SIZE; ++i)
    {
        m.insert(i, i);
    }
    m.print();
    std::cout << std::endl << std::endl;
    m.erase(1);

    m.print();
    if(m.size() == SIZE-1){
        std::cout << "GYAT" << std::endl;
    }*/
    
	return 1;
}
