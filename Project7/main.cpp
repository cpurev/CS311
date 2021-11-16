#include "treesorter.h"
#include <iostream>
#include <vector>
#include <stddef.h>
#include <list>
#include <iterator>
#include <algorithm>

class IntPair {

public:

    // Default ctor, ctor from 1 int, ctor from 2 ints
    // Sets _x, _y to given values; 0 if not given.
    // Pre: None.
    // Post:
    //     _x, _y set as indicated.
    // Does not throw (No-Throw Guarantee)
    explicit IntPair(int theX = 0,
                     int theY = 0)
        :_x(theX),
         _y(theY)
    {}

    ~IntPair() = default;
    IntPair(const IntPair &) = default;
    IntPair(IntPair &&) = default;
    IntPair & operator=(const IntPair &) = default;
    IntPair & operator=(IntPair &&) = default;

    // getX
    // returns _x
    // Pre: None.
    // Post:
    //     Return value == _x.
    // Does not throw (No-Throw Guarantee)
    int getX() const
    { return _x; }

    // getY
    // returns _y
    // Pre: None.
    // Post:
    //     Return value == _y.
    // Does not throw (No-Throw Guarantee)
    int getY() const
    { return _y; }

private:

    int _x;  // First item in pair
    int _y;  // Second item in pair

};  // End class IntPair

// operator== (IntPair)
// The usual == op for a pair: compares both items.
// Pre: None.
// Post:
//     Return value == (a._x == b._x && a._y == b._y).
bool operator==(const IntPair & a,
                const IntPair & b)
{ return a.getX() == b.getX() && a.getY() == b.getY(); }


// operator< (IntPair)
// Calls op< on _x only.
// Pre: None.
// Post:
//     Return value == (a._x == b._x).
bool operator<(const IntPair & a,
               const IntPair & b)
{ return a.getX() < b.getX(); }

int main(){

    std::vector<int> dataX
            { 16,  8,  7,  7,  6, 10, 15,  2,  3, 14,  2, 11,  9, 11,
               3, 15,  4, 10,  8, 16,  3,  1,  1, 12, 14, 13, 12,  4,
               5,  6,  5,  9 };

    std::vector<int> dataY
            {  1,  1,  1,  2,  1,  1,  1,  1,  1,  1,  2,  1,  1,  2,
               1,  2,  1,  2,  2,  2,  2,  1,  2,  1,  2,  2,  2,  2,
               1,  2,  2,  2 };

    std::vector<IntPair> vp1(32);
    std::vector<IntPair> vp2;

    for (size_t i = 0; i < 32; ++i){
            vp1[i] = IntPair(dataX[i], dataY[i]);
            std::cout << dataX[i] << ":" << dataY[i] << " ";
    }
    std::cout<< std::endl;
    vp2 = vp1;
    treesort(vp1.begin(), vp1.end());
    std::cout<< std::endl;
    std::stable_sort(vp2.begin(), vp2.end());
    if(std::equal(vp1.begin(), vp1.end(), vp2.begin()))
        std::cout << "STAVLE" << std::endl;

    for(auto x : vp1){
        std::cout << x.getX() << ":" << x.getY() << " ";
    }
    std::cout<< std::endl;

    for(auto x : vp2){
        std::cout << x.getX() << ":" << x.getY() << " ";
    }
    std::cout<< std::endl;
	return 1;
}
