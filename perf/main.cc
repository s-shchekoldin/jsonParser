#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>

#include "json.h"
#include "/home/rapidjson/include/rapidjson/reader.h"

#ifndef REPEAT_COUT
#define REPEAT_COUT (20*1000*1000)
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


struct MyHandler
{
    bool Null() { return true; }
    bool Bool(bool b) { return true; }
    bool Int(int i) { return true; }
    bool Uint(unsigned u) { return true; }
    bool Int64(int64_t i) { return true; }
    bool Uint64(uint64_t u) { return true; }
    bool Double(double d) { return true; }
    bool RawNumber(const char* str, rapidjson::SizeType length, bool copy) { return true; }
    bool String(const char* str, rapidjson::SizeType length, bool copy) { return true; }
    bool StartObject() { return true; }
    bool Key(const char* str, rapidjson::SizeType length, bool copy) { return true; }
    bool EndObject(rapidjson::SizeType memberCount) { return true; }
    bool StartArray() { return true; }
    bool EndArray(rapidjson::SizeType elementCount) { return true; }
};


int main()
{
    std::ifstream f("input.txt");
    std::string input((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());

    MyHandler handler;

    uint64_t reqCount = 0;
    uint64_t totalBytes = 0;
    auto startTime = std::chrono::high_resolution_clock::now();
    for(uint64_t i = 0; i < REPEAT_COUT; i++)
    {
        reqCount++;
        totalBytes += input.length();

#ifdef TEST_RAPIDJSON
        rapidjson::Reader reader;
        rapidjson::StringStream ss(input.c_str());
        reader.Parse(ss, handler);
        if (!reader.HasParseError())
            continue;
#else
        json state;
        if (state.parse(input.data(), input.size()))
            continue;
#endif
        printf("ERROR PARSE\n");
        return 1;
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    uint64_t usec = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    if (usec == 0)
    {
        printf("Warning! increase REPEAT_COUT=%lu\n", REPEAT_COUT);
        return 0;
    }
    printf("\t\t\tRESULT: usec=%lu, Mbites/sec=%lu ReqPerSeq: %lu TotalBytes: %lu\r\n",
        usec, totalBytes*8000*1000/usec/1024/1024, reqCount*1000*1000/usec, totalBytes);
    return 0;
}

