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
    std::string value;
    uint32_t depth = 0;

    // Don't forget to declare:
    void gotKV();
    void gotVal();
    void popDepth();
    void pushDepth();
};

struct json : jsonResult
{
    bool parse(const char * data, unsigned len);
    bool parse(const std::string & data) { return parse(data.data(), data.length()); }
    void reset();
    bool empty() const { return mainState.node == node_t::NO_STATE; }

private:
    enum class node_t
    {
        LOOP_1_0, // line_1
            RANGE_1_0, 
            RANGE_2_0, FUNC_2_1, FUNC_2_2, NOTIFY_2_3, 
            RANGE_3_0, FUNC_3_1, NOTIFY_3_2, 
            TEXT_4_0, STRING_4_1, TEXT_4_2, RANGE_4_3, CASES_4_4,
                TEXT_5_0, RANGE_5_1, CASES_5_2,
                    TEXT_6_0, STRING_6_1, TEXT_6_2, NOTIFY_6_3, 
                    STRING_7_0, NOTIFY_7_1, 
                    RANGE_8_0, FUNC_8_1, NOTIFY_8_2, 
                TEXT_9_0, FUNC_9_1, NOTIFY_9_2, 
                RANGE_10_0, FUNC_10_1, NOTIFY_10_2, FUNC_10_3, NOTIFY_10_4, 
            STRING_11_0, NOTIFY_11_1, 
        LOOP_13_0, // line_13
            UINT_13_0, 
        NO_STATE
    };
    struct state_t
    {
        const char * data = nullptr;
        const char * end = nullptr;
        uint64_t consumed = 0;
        node_t node = node_t::LOOP_1_0;
        unsigned remainDataLen() const { return (unsigned)(end - data); }
        const char * name() const;
    } __attribute__((packed));
    state_t mainState;

    void parse(state_t & state);
    bool loop_1_0(state_t & state);
    bool range_1_0(state_t & state);
    bool range_2_0(state_t & state);
    bool func_2_1(state_t & state);
    bool _func_2_1();
    bool func_2_2(state_t & state);
    bool _func_2_2();
    bool notify_2_3(state_t & state);
    bool range_3_0(state_t & state);
    bool func_3_1(state_t & state);
    bool _func_3_1();
    bool notify_3_2(state_t & state);
    bool text_4_0(state_t & state);
    bool string_4_1(state_t & state);
    void _string_4_1(const char * data, unsigned len, uint64_t consumed);
    bool text_4_2(state_t & state);
    bool range_4_3(state_t & state);
    bool cases_4_4(state_t & state);
    bool text_5_0(state_t & state);
    bool range_5_1(state_t & state);
    bool cases_5_2(state_t & state);
    bool text_6_0(state_t & state);
    bool string_6_1(state_t & state);
    void _string_6_1(const char * data, unsigned len, uint64_t consumed);
    bool text_6_2(state_t & state);
    bool notify_6_3(state_t & state);
    bool string_7_0(state_t & state);
    void _string_7_0(const char * data, unsigned len, uint64_t consumed);
    bool notify_7_1(state_t & state);
    bool range_8_0(state_t & state);
    bool func_8_1(state_t & state);
    bool _func_8_1();
    bool notify_8_2(state_t & state);
    bool text_9_0(state_t & state);
    bool func_9_1(state_t & state);
    bool _func_9_1();
    bool notify_9_2(state_t & state);
    bool range_10_0(state_t & state);
    bool func_10_1(state_t & state);
    bool _func_10_1();
    bool notify_10_2(state_t & state);
    bool func_10_3(state_t & state);
    bool _func_10_3();
    bool notify_10_4(state_t & state);
    bool string_11_0(state_t & state);
    void _string_11_0(const char * data, unsigned len, uint64_t consumed);
    bool notify_11_1(state_t & state);
    bool loop_13_0(state_t & state);
    bool uint_13_0(state_t & state);
    void _uint_13_0(const char * data, unsigned len, uint64_t consumed);
};
#endif
