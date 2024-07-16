#include "json.h"
#include <fstream>

void jsonResult::value(__attribute__((unused)) const char * data, __attribute__((unused)) unsigned len, __attribute__((unused)) bool isFirst, __attribute__((unused)) bool isLast)
{
    printf("gotVal(%u)[%u:%u]: %s\n", depth, isFirst, isLast, std::string(data, len).c_str());
}
void jsonResult::keyValue(__attribute__((unused)) const char * data, __attribute__((unused)) unsigned len, __attribute__((unused)) bool isFirst, __attribute__((unused)) bool isLast)
{
    printf("gotKV(%u)[%u:%u]: %s->%s\n", depth, isFirst, isLast, key.c_str(), std::string(data, len).c_str());
}
void jsonResult::pushDepth()
{
    printf("pushDepth(%u): %s\n", depth, key.c_str());
}
void jsonResult::popDepth()
{
    printf("popDepth(%u)\n", depth);
}

int main()
{
    std::ifstream f("input.txt");
    std::string input((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());

    json state;

    printf("===Test1 - full request:===\n");
    state.parse(input);

    printf("===Test2 - data fragmentation 1 byte===\n");
    for(const auto & c : input)
        if (!state.parse(&c, 1))
            printf("Error parse\n");

    return 0;
}
