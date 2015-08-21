#include <iostream>
#include <chrono>
#include <vector>
#include <cstring>

int main() {
    auto bigNum = 100000;
    auto theAnswer = 42;
    auto theQuestion = 7;

    // array
    int dstArr[bigNum];

    auto tsArr1 = std::chrono::high_resolution_clock::now();
    int srcArr[bigNum];
    for(auto& val: srcArr)
        val = theQuestion;
    auto tsArr2 = std::chrono::high_resolution_clock::now();
    auto arrDur = std::chrono::duration_cast<std::chrono::microseconds>(tsArr2-tsArr1).count();

    std::cout << "Array creation using auto loop " << arrDur << " usec\n";
    auto ts5 = std::chrono::high_resolution_clock::now();
    memcpy(dstArr,srcArr, sizeof(srcArr));
    auto ts6 = std::chrono::high_resolution_clock::now();
    auto dur3 = std::chrono::duration_cast<std::chrono::microseconds>(ts6-ts5).count();
    std::cout << "Array copy " << dur3<< " usec\n";
    std::cout << "-------------------------\n";
    std::cout << "Array value sample " << dstArr[43] << "\n";
    std::cout << "-------------------------\n";
    auto ts1 = std::chrono::high_resolution_clock::now();
    std::vector<int> src(bigNum, theAnswer);
    auto ts2 = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(ts2-ts1).count();
    std::cout << "Vector Creation took " << dur << " usec\n";
    auto ts3 = std::chrono::high_resolution_clock::now();
    std::vector<int> dest(src);
    auto ts4 = std::chrono::high_resolution_clock::now();
    auto dur2 = std::chrono::duration_cast<std::chrono::microseconds>(ts4-ts3).count();
    std::cout << "Vector Constructor copy took " << dur2<< " usec\n";

    std::vector<int> dest2(bigNum);
    // assignment
    auto ts3eq = std::chrono::high_resolution_clock::now();
    dest2 = src;
    auto ts4eq = std::chrono::high_resolution_clock::now();
    auto dur2eq = std::chrono::duration_cast<std::chrono::microseconds>(ts4eq-ts3eq).count();
    std::cout << "Vector copy of two created vectors using equal " << dur2eq << " usec\n";

    std::vector<int> dest3(bigNum);
    //  assignment with move
    auto ts3mv = std::chrono::high_resolution_clock::now();
    dest3 = std::move(src);
    auto ts4mv = std::chrono::high_resolution_clock::now();
    auto dur2mv = std::chrono::duration_cast<std::chrono::microseconds>(ts4mv-ts3mv).count();
    std::cout << "Vector copy of two created vectors using move equal " << dur2mv << " usec\n";

    std::cout << "-------------------------\n";
    std::cout << "dest3 size " << dest3.size() << " " << dest2[43] << "\n";
    std::cout << "-------------------------\n";
    return 0;
}