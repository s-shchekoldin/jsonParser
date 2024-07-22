#include "json.h"
#include <fstream>

void jsonResult::pushDepth()
{
    printf("pushDepth(%u): %s\n", depth, std::string(key).c_str());
}
void jsonResult::popDepth()
{
    printf("popDepth(%u)\n", depth);
}
void jsonResult::gotKV()
{
    printf("gotKV(%u): %s->%s\n", depth, std::string(key).c_str(), std::string(value).c_str());
}
void jsonResult::gotVal()
{
    printf("gotVal(%u): %s\n", depth, std::string(value).c_str());
}


int main()
{
    std::ifstream f("../input.txt");
    std::string input((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());

    json state;

    printf("===Test1 - full request:===\n");
    state.parse(input);

    return 0;
}
