#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>

#include "json.h"

#ifndef REPEAT_COUNT
#define REPEAT_COUNT (10*1000*1000)
#endif

void jsonResult::value(__attribute__((unused)) const char * data, __attribute__((unused)) unsigned len, __attribute__((unused)) bool isFirst, __attribute__((unused)) bool isLast)
{
//    printf("gotVal(%u): %s\n", depth, std::string(data, len).c_str());
}
void jsonResult::keyValue(__attribute__((unused)) const char * data, __attribute__((unused)) unsigned len, __attribute__((unused)) bool isFirst, __attribute__((unused)) bool isLast)
{
//    printf("gotKV(%u): %s->%s\n", depth, key.c_str(), std::string(data, len).c_str());
}
void jsonResult::pushDepth()
{
//    printf("pushDepth(%u): %s\n", depth, key.c_str());
}
void jsonResult::popDepth()
{
//    printf("popDepth(%u)\n", depth);
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
