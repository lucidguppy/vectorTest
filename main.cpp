#include <iostream>
#include <chrono>
#include <vector>
#include <cstring>
#include <cassert>
#include <utility>
#include <ctime>
#include <cstdlib>

// Define VERIFY to perform some asserts.
// Is disabled by default to simplify the
// output assembly code for easier analysis.
#undef VERIFY


auto constexpr bigNum = 100000;
auto constexpr loopNum = 60000;

std::pair<int,int> TimeToCopyArray () {
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

std::pair<int, int> TimeToCopyVector () {
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

int main() {
    srand(time(NULL));
    std::cout << "ArrayCopy(dur us), VectorCopy(dur us)\n";
    constexpr auto loops = 10;
    for (int ii = 0; ii < loops; ++ii) {
        std::cout << TimeToCopyArray().first << "," << TimeToCopyVector().first << "\n";
    }
    return 0;
}
