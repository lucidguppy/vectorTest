#include <iostream>
#include <chrono>
#include <vector>
#include <cstring>
#include <cassert>
#include <utility>
#include <ctime>
#include <cstdlib>
#include <iomanip>

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

    std::vector<std::pair<int,int>> array;
    std::vector<std::pair<int,int>> vector;

    for (int ii = 0; ii < loops; ++ii) {
        array.push_back(TimeToCopyArray(theBigNum, loopNum));
        vector.push_back(TimeToCopyVector(theBigNum, loopNum));
    }

    // sum the times
    auto arrayTotal = 0;
    for(auto e : array)
    {
        arrayTotal += e.first;
    }

    auto vectorTotal = 0;
    for(auto e : vector)
    {
        vectorTotal += e.first;
    }

    // calculate the averages
    auto arrayAverage = arrayTotal / (double)array.size();
    auto vectorAverage = vectorTotal / (double)vector.size();

    // calculate the time relative to the vector
    auto vectorTimePercentage = (vectorAverage - arrayAverage) / vectorAverage;
    auto vectorDeltaString = (vectorTimePercentage > 0) ? "slower" : "faster";

    std::ios_base::fmtflags originalFlags = std::cout.flags();
    std::cout << "ArrayCopy(dur us) - " << theBigNum << " bytes, VectorCopy(dur us) - "
        << theBigNum << " bytes. Vector " << vectorDeltaString << " by "
        << std::fixed << std::setprecision(1) << (vectorTimePercentage * 100.0) << "%\n";
    std::cout.flags( originalFlags );
    for (int ii = 0; ii < loops; ++ii) {
        std::cout << array[ii].first << "," << vector[ii].first << "\n";
    }

    return 0;
}
