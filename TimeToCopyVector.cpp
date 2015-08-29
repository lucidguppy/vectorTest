
#include "TimeToCopyVector.h"
#include <chrono>
#include <vector>

std::pair<int, int> TimeToCopyVector (int bigNum, int loopNum) {
    std::vector<int> src(bigNum);
    std::vector<int> dest(bigNum, 0);
#ifdef VERIFY
    assert(dest[10] == 0);
#endif
    int ii {0};
    for (auto it = src.begin(); it != src.end(); ++it ) {
        *it = ii++;
    }
#ifdef VERIFY
    assert(src[9] == 9);
#endif
    // assignment
    auto ts1 = std::chrono::high_resolution_clock::now();
    for (int ii = 0; ii < loopNum; ++ii) {
        dest = src;
    }
    auto ts2 = std::chrono::high_resolution_clock::now();
#ifdef VERIFY
    assert(dest[bigNum-1] == bigNum-1);
#endif
    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(ts2-ts1).count();
    return std::make_pair((int)dur,src[0]);
}
