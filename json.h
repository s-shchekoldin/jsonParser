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
    std::string nameDepth;
    std::string tmpValue;
    std::string value;
    uint64_t depth = 0;
    // Don't forget to declare:
    void gotKV();
    void gotVal();
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
                RANGE_3_0, FUNC_3_1, NOTIFY_3_2, FUNC_3_3, 
                RANGE_4_0, FUNC_4_1, NOTIFY_4_2, 
                TEXT_5_0, GOTO_5_1, FUNC_5_2, 
        LOOP_7_0, // line_7
            LABEL_7_0, LOOP_7_1,
                STRING_8_0, RANGE_8_1, RANGE_8_2, CASES_8_3,
                    TEXT_9_0, RANGE_9_1, CASES_9_2,
                        TEXT_10_0, GOTO_10_1, NOTIFY_10_2, RET_10_3, 
                        TEXT_11_0, FUNC_11_1, NOTIFY_11_2, RET_11_3, 
                        TEXT_12_0, FUNC_12_1, NOTIFY_12_2, RET_12_3, 
                        TEXT_13_0, FUNC_13_1, NOTIFY_13_2, RET_13_3, 
                        STRING_14_0, NOTIFY_14_1, RET_14_2, 
                 // catch:
                        FUNC_15_0, RET_15_1, 
                    TEXT_16_0, FUNC_16_1, NOTIFY_16_2, RET_16_3, 
                 // catch:
                    FUNC_17_0, NOTIFY_17_1, RET_17_2, 
        LOOP_19_0, // line_19
            LABEL_19_0, FUNC_19_1, LOOP_19_2,
                STRING_20_0, FUNC_20_1, 
                TEXT_21_0, RET_21_1, 
                TEXT_22_0, CASES_22_1,
                    TEXT_23_0, FUNC_23_1, 
                    TEXT_24_0, FUNC_24_1, 
                    TEXT_25_0, FUNC_25_1, 
                    TEXT_26_0, FUNC_26_1, 
                    TEXT_27_0, FUNC_27_1, 
        LOOP_29_0, // line_29
            UINT_29_0, STRING_29_1, 
        NO_STATE
    };
    struct state_t
    {
        const char * data = nullptr;
        const char * end = nullptr;
        uint64_t consumed = 0;
        node_t node = node_t::LOOP_1_0;
        unsigned retStackCount = 0;
        node_t retStack[4];
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
    bool notify_3_2(state_t & state);
    bool func_3_3(state_t & state);
    bool _func_3_3();
    bool range_4_0(state_t & state);
    bool func_4_1(state_t & state);
    bool _func_4_1();
    bool notify_4_2(state_t & state);
    bool text_5_0(state_t & state);
    bool goto_5_1(state_t & state);
    bool func_5_2(state_t & state);
    bool _func_5_2();
    bool loop_7_0(state_t & state);
    bool label_7_0(state_t & state);
    bool loop_7_1(state_t & state);
    bool string_8_0(state_t & state);
    void _string_8_0(const char * data, unsigned len, bool isFirst);
    bool range_8_1(state_t & state);
    bool range_8_2(state_t & state);
    bool cases_8_3(state_t & state);
    bool text_9_0(state_t & state);
    bool range_9_1(state_t & state);
    bool cases_9_2(state_t & state);
    bool text_10_0(state_t & state);
    bool goto_10_1(state_t & state);
    bool notify_10_2(state_t & state);
    bool ret_10_3(state_t & state);
    bool text_11_0(state_t & state, bool isCaseCall);
    bool func_11_1(state_t & state);
    bool _func_11_1();
    bool notify_11_2(state_t & state);
    bool ret_11_3(state_t & state);
    bool text_12_0(state_t & state, bool isCaseCall);
    bool func_12_1(state_t & state);
    bool _func_12_1();
    bool notify_12_2(state_t & state);
    bool ret_12_3(state_t & state);
    bool text_13_0(state_t & state, bool isCaseCall);
    bool func_13_1(state_t & state);
    bool _func_13_1();
    bool notify_13_2(state_t & state);
    bool ret_13_3(state_t & state);
    bool string_14_0(state_t & state);
    void _string_14_0(const char * data, unsigned len, bool isFirst);
    bool notify_14_1(state_t & state);
    bool ret_14_2(state_t & state);
    bool func_15_0(state_t & state);
    bool _func_15_0();
    bool ret_15_1(state_t & state);
    bool text_16_0(state_t & state);
    bool func_16_1(state_t & state);
    bool _func_16_1();
    bool notify_16_2(state_t & state);
    bool ret_16_3(state_t & state);
    bool func_17_0(state_t & state);
    bool _func_17_0();
    bool notify_17_1(state_t & state);
    bool ret_17_2(state_t & state);
    bool loop_19_0(state_t & state);
    bool label_19_0(state_t & state);
    bool func_19_1(state_t & state);
    bool _func_19_1();
    bool loop_19_2(state_t & state);
    bool string_20_0(state_t & state);
    void _string_20_0(const char * data, unsigned len, bool isFirst);
    bool func_20_1(state_t & state);
    bool _func_20_1();
    bool text_21_0(state_t & state);
    bool ret_21_1(state_t & state);
    bool text_22_0(state_t & state);
    bool cases_22_1(state_t & state);
    bool text_23_0(state_t & state);
    bool func_23_1(state_t & state);
    bool _func_23_1();
    bool text_24_0(state_t & state);
    bool func_24_1(state_t & state);
    bool _func_24_1();
    bool text_25_0(state_t & state);
    bool func_25_1(state_t & state);
    bool _func_25_1();
    bool text_26_0(state_t & state);
    bool func_26_1(state_t & state);
    bool _func_26_1();
    bool text_27_0(state_t & state);
    bool func_27_1(state_t & state);
    bool _func_27_1();
    bool loop_29_0(state_t & state);
    bool uint_29_0(state_t & state);
    void _uint_29_0(const char * data, unsigned len, bool isFirst);
    bool string_29_1(state_t & state);
    void _string_29_1(const char * data, unsigned len, bool isFirst);
};
#endif
