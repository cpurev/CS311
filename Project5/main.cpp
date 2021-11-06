#include <iostream>
#include <utility>
using std::move;
#include "fstarray.h"
#include <vector>
using std::vector;
#include <assert.h>

int main(){
    const size_t SIZE = size_t(10);
    FSTArray<int> ti_original(SIZE);
    for (size_t i = 0; i < SIZE; ++i)
    {
        ti_original[i] = i;
    }

    
    const size_t SIZE2 = size_t(100000);
    FSTArray<int> ti = ti_original;

    vector<int> v(ti_original.begin(), ti_original.end());

     for (size_t i = SIZE+1; i <= SIZE2; ++i)
    {
        v.insert(v.end(), 70000-(int(i)-1));
    }

    int realloccount = 0;       // # of times realloc-&-copy done
    bool realloctwice = false;  // Did realloc-&-copy 2x in a row?
    bool realloclast = false;   // Was realloc-&-copy just done?
    for (size_t i = SIZE+1; i <= SIZE2; ++i)
    {
        int * savedata = ti.begin();
        auto result = ti.insert(ti.end(), 70000-int(ti.size()));
        bool reallocdone = (ti.begin() != savedata);  // realloc-&-copy?
        if (reallocdone)
        {
            ++realloccount;
            if (realloclast)
                realloctwice = true;
            if( result == ti.end()-1 ){
                std::cout << "Many inserts - check return value on reallocate-and-copy" << std::endl;
            }
        }
        realloclast = reallocdone;
    }


    return 0;
}