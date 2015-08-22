#include <iostream>
#include <chrono>
#include <vector>
#include <cstring>
#include <cassert>


auto constexpr bigNum = 100000;
auto constexpr loopNum = 100;

auto TimeToCopyArray () {
    // array
    int* dstArr = new int [bigNum];
    int* srcArr = new int [bigNum];
    for (auto ii = 0; ii < bigNum; ++ii ) {
        srcArr[ii] = ii;
        dstArr[ii] = 0;
    }
    assert(dstArr[3] == 0);
    auto ts1 = std::chrono::high_resolution_clock::now();
    for (int ii = 0; ii < loopNum; ++ii) {
        memcpy(dstArr,srcArr, sizeof(int)*bigNum);
    }
    auto ts2 = std::chrono::high_resolution_clock::now();
    assert(dstArr[3] == 3);
    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(ts2-ts1).count();
    delete[] dstArr;
    delete[] srcArr;
    return dur;
}

auto TimeToCopyVector () {
    std::vector<int> src(bigNum);
    std::vector<int> dest(bigNum, 0);
    assert(dest[10] == 0);
    int ii {0};
    for (auto it = src.begin(); it != src.end(); ++it ) {
        *it = ++ii;
    }
    assert(src[9] == 10);
    // assignment
    auto ts1 = std::chrono::high_resolution_clock::now();
    for (int ii = 0; ii < loopNum; ++ii) {
        dest = src;
    }
    auto ts2 = std::chrono::high_resolution_clock::now();
    assert(dest[8] == 9);
    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(ts2-ts1).count();
    return dur;
}

int main() {
    std::cout << "ArrayCopy(dur us), VectorCopy(dur us)\n";
    constexpr auto loops = 1000;
    for (int ii = 0; ii < loops; ++ii) {
        std::cout << TimeToCopyArray() << "," << TimeToCopyVector() << "\n";
    }
    return 0;
}
