#include "json.h"
#include <fstream>

void jsonResult::gotKV()
{
    printf("gotKV: %s->%s\n", key.c_str(), value.c_str());
}
void jsonResult::gotVal()
{
    printf("gotVal(%lu): %s\n", depth, value.c_str());
}
void jsonResult::pushDepth()
{
    printf("pushDepth(%lu): %s\n", depth, nameDepth.c_str());
}
void jsonResult::popDepth()
{
    printf("popDepth(%lu)\n", depth);
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
