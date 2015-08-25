#include "TimeToCopyArray.h"
#include <chrono>
#include <string.h>

std::pair<int,int> TimeToCopyArray (int bigNum, int loopNum) {
    // array
    int* dstArr = new int [bigNum];
    int* srcArr = new int [bigNum];
    for (auto ii = 0; ii < bigNum; ++ii ) {
        srcArr[ii] = ii;
        dstArr[ii] = 0;
    }
#ifdef VERIFY
    assert(dstArr[3] == 0);
#endif
    auto ts1 = std::chrono::high_resolution_clock::now();
    for (int ii = 0; ii < loopNum; ++ii) {
        memcpy(dstArr,srcArr, sizeof(int)*bigNum);
    }
    auto ts2 = std::chrono::high_resolution_clock::now();
#ifdef VERIFY
    assert(dstArr[bigNum-1] == bigNum-1);
#endif
    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(ts2-ts1).count();
    int d = *srcArr;
    delete[] dstArr;
    delete[] srcArr;
    return std::make_pair((int)dur,d);
}
