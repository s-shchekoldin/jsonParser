// ==============================================================
// Generated using https://www.vsyn.ru/
// Author: Sergey V. Shchekoldin     Email: shchekoldin@gmail.com
// ==============================================================

#ifndef JSON_H
#define JSON_H
#pragma once

#include <string>
#include <vector>
#include <cstdint>

struct jsonResult
{
    std::string key;
    uint32_t depth = 0;

    // Don't forget to declare:
    void keyValue(__attribute__((unused)) const char * data, __attribute__((unused)) unsigned len, __attribute__((unused)) bool isFirst, __attribute__((unused)) bool isLast);
    void value(__attribute__((unused)) const char * data, __attribute__((unused)) unsigned len, __attribute__((unused)) bool isFirst, __attribute__((unused)) bool isLast);
    void popDepth();
    void pushDepth();
};

struct json : jsonResult
{
    bool parse(const char * data, unsigned len);
    bool parse(const std::string & data) { return parse(data.c_str(), data.length()); }
    void reset();
    bool empty() const { return mainState.node == node_t::NO_STATE; }

private:
    enum class node_t
    {
        LOOP_1_0, // line_1
            LABEL_1_0, LOOP_1_1,
                RANGE_2_0, 
                RANGE_3_0, FUNC_3_1, FUNC_3_2, NOTIFY_3_3, 
                RANGE_4_0, FUNC_4_1, NOTIFY_4_2, 
                TEXT_5_0, STRING_5_1, TEXT_5_2, RANGE_5_3, CASES_5_4,
                    TEXT_6_0, RANGE_6_1, CASES_6_2,
                        TEXT_7_0, RANGE_7_1, TEXT_7_2, 
                        RANGE_8_0, FUNC_8_1, NOTIFY_8_2, 
                        RANGE_9_0, 
                    TEXT_10_0, FUNC_10_1, 
                    RANGE_11_0, FUNC_11_1, NOTIFY_11_2, 
                RANGE_12_0, 
        LOOP_14_0, // line_14
            UINT_14_0, 
        NO_STATE
    };
    struct state_t
    {
        const char * data = nullptr;
        const char * end = nullptr;
        uint64_t consumed = 0;
        node_t node = node_t::LOOP_1_0;
        unsigned retStackCount = 0;
        node_t retStack[2];
        unsigned remainDataLen() const { return (unsigned)(end - data); }
        const char * name() const;
    };
    state_t mainState;

    void parse(state_t & state);
    bool loop_1_0(state_t & state);
    bool label_1_0(state_t & state);
    bool loop_1_1(state_t & state);
    bool range_2_0(state_t & state);
    bool range_3_0(state_t & state);
    bool func_3_1(state_t & state);
    bool _func_3_1();
    bool func_3_2(state_t & state);
    bool _func_3_2();
    bool notify_3_3(state_t & state);
    bool range_4_0(state_t & state);
    bool func_4_1(state_t & state);
    bool _func_4_1();
    bool notify_4_2(state_t & state);
    bool text_5_0(state_t & state);
    bool string_5_1(state_t & state);
    void _string_5_1(const char * data, unsigned len, bool isFirst);
    bool text_5_2(state_t & state);
    bool range_5_3(state_t & state);
    bool cases_5_4(state_t & state);
    bool text_6_0(state_t & state);
    bool range_6_1(state_t & state);
    bool cases_6_2(state_t & state);
    bool text_7_0(state_t & state);
    bool range_7_1(state_t & state);
    bool text_7_2(state_t & state);
    bool range_8_0(state_t & state);
    bool func_8_1(state_t & state);
    bool _func_8_1();
    bool notify_8_2(state_t & state);
    bool range_9_0(state_t & state);
    bool text_10_0(state_t & state);
    bool func_10_1(state_t & state);
    bool _func_10_1();
    bool range_11_0(state_t & state);
    bool func_11_1(state_t & state);
    bool _func_11_1();
    bool notify_11_2(state_t & state);
    bool range_12_0(state_t & state);
    bool loop_14_0(state_t & state);
    bool uint_14_0(state_t & state);
    void _uint_14_0(const char * data, unsigned len, bool isFirst);
};
#endif
