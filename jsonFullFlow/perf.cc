#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>

#include "json.h"

#ifndef REPEAT_COUNT
#define REPEAT_COUNT (10*1000*1000)
#endif

void jsonResult::pushDepth()
{
//    printf("pushDepth(%u): %s\n", depth, key.c_str());
}
void jsonResult::popDepth()
{
//    printf("popDepth(%u)\n", depth);
}
void jsonResult::gotKV()
{
//    printf("gotKV: %s->%s\n", key.c_str(), value.c_str());
}
void jsonResult::gotVal()
{
//    printf("gotVal(%u): %s\n", depth, value.c_str());
}

int main()
{
    std::ifstream f("../input.txt");
    std::string input((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());

    uint64_t reqCount = 0;
    uint64_t totalBytes = 0;
    auto startTime = std::chrono::high_resolution_clock::now();
    for(uint64_t i = 0; i < REPEAT_COUNT; i++)
    {
        reqCount++;
        totalBytes += input.length();

        json state;
        if (state.parse(input.data(), input.size()))
            continue;
        printf("ERROR PARSE\n");
        return 1;
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    uint64_t usec = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    if (usec == 0)
    {
        printf("Warning! increase REPEAT_COUNT=%lu\n", REPEAT_COUNT);
        return 0;
    }
    printf("\t\t\tRESULT: usec=%lu, Mbites/sec=%lu ReqPerSeq: %lu TotalBytes: %lu\r\n",
        usec, totalBytes*8000*1000/usec/1024/1024, reqCount*1000*1000/usec, totalBytes);
    return 0;
}
