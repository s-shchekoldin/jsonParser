#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>

#include <rapidjson/reader.h>

#ifdef REPEAT_COUNT
uint64_t repeatCount = REPEAT_COUNT;
#else
uint64_t repeatCount = 10*1000*1000;
#endif

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
    std::ifstream f("../input.txt");
    std::string input((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());

    MyHandler handler;

    uint64_t reqCount = 0;
    uint64_t totalBytes = 0;
    auto startTime = std::chrono::high_resolution_clock::now();
    for(uint64_t i = 0; i < repeatCount; i++)
    {
        reqCount++;
        totalBytes += input.length();

        rapidjson::Reader reader;
        rapidjson::StringStream ss(input.c_str());
        reader.Parse(ss, handler);
        if (!reader.HasParseError())
            continue;
        printf("ERROR PARSE\n");
        return 1;
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    uint64_t usec = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    if (usec == 0)
    {
        printf("Warning! increase repeatCount=%lu\n", repeatCount);
        return 0;
    }
    printf("\t\t\tRESULT: usec=%lu, Mbites/sec=%lu ReqPerSeq: %lu TotalBytes: %lu\r\n",
        usec, totalBytes*8000*1000/usec/1024/1024, reqCount*1000*1000/usec, totalBytes);
    return 0;
}

