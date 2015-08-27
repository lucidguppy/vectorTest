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

auto constexpr loops = 100;

int theBigNum;
int loopNum;

#include "TimeToCopyArray.h"
#include "TimeToCopyVector.h"

int main(int argc, char* argv[]) {
    theBigNum = atoi(argv[1]);
    loopNum = atoi(argv[2]);
    std::cout << "ArrayCopy(dur us) - " << theBigNum << " bytes, VectorCopy(dur us) - " << theBigNum << " bytes\n";
    for (int ii = 0; ii < loops; ++ii) {
        std::cout << TimeToCopyArray(theBigNum, loopNum).first << "," << TimeToCopyVector(theBigNum, loopNum).first << "\n";
    }
    return 0;
}
