#include <iostream>
#include <chrono>
#include <vector>
#include <cstring>
#include <cassert>


auto constexpr bigNum = 100000;
auto constexpr theQuestion = 7;

auto TimeToCopyArray () {
    // array
    int dstArr[bigNum] {};
    int srcArr[bigNum] {};
    for (auto ii = 0; ii < bigNum; ++ii ) {
        srcArr[ii] = ii;
    }
    assert(dstArr[3] == 0);
    auto ts1 = std::chrono::high_resolution_clock::now();
    memcpy(dstArr,srcArr, sizeof(srcArr));
    auto ts2 = std::chrono::high_resolution_clock::now();
    assert(dstArr[3] == 3);
    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(ts2-ts1).count();
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
    dest = src;
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