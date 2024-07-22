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
#include <string_view>

struct jsonResult
{
    std::string_view key;
    std::string_view value;
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
            LABEL_1_0, LOOP_1_1,
                RANGE_2_0, 
                RANGE_3_0, FUNC_3_1, FUNC_3_2, NOTIFY_3_3, 
                RANGE_4_0, FUNC_4_1, NOTIFY_4_2, 
                TEXT_5_0, STR_VIEW_5_1, TEXT_5_2, RANGE_5_3, CASES_5_4,
                    TEXT_6_0, RANGE_6_1, CASES_6_2,
                        TEXT_7_0, STR_VIEW_7_1, TEXT_7_2, NOTIFY_7_3, 
                        STR_VIEW_8_0, NOTIFY_8_1, 
                        RANGE_9_0, FUNC_9_1, NOTIFY_9_2, 
                    TEXT_10_0, FUNC_10_1, NOTIFY_10_2, 
                    RANGE_11_0, FUNC_11_1, NOTIFY_11_2, FUNC_11_3, NOTIFY_11_4, 
                STR_VIEW_12_0, NOTIFY_12_1, 
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
    bool str_view_5_1(state_t & state);
    void _str_view_5_1(const char * data, unsigned len, uint64_t consumed);
    bool text_5_2(state_t & state);
    bool range_5_3(state_t & state);
    bool cases_5_4(state_t & state);
    bool text_6_0(state_t & state);
    bool range_6_1(state_t & state);
    bool cases_6_2(state_t & state);
    bool text_7_0(state_t & state);
    bool str_view_7_1(state_t & state);
    void _str_view_7_1(const char * data, unsigned len, uint64_t consumed);
    bool text_7_2(state_t & state);
    bool notify_7_3(state_t & state);
    bool str_view_8_0(state_t & state);
    void _str_view_8_0(const char * data, unsigned len, uint64_t consumed);
    bool notify_8_1(state_t & state);
    bool range_9_0(state_t & state);
    bool func_9_1(state_t & state);
    bool _func_9_1();
    bool notify_9_2(state_t & state);
    bool text_10_0(state_t & state);
    bool func_10_1(state_t & state);
    bool _func_10_1();
    bool notify_10_2(state_t & state);
    bool range_11_0(state_t & state);
    bool func_11_1(state_t & state);
    bool _func_11_1();
    bool notify_11_2(state_t & state);
    bool func_11_3(state_t & state);
    bool _func_11_3();
    bool notify_11_4(state_t & state);
    bool str_view_12_0(state_t & state);
    void _str_view_12_0(const char * data, unsigned len, uint64_t consumed);
    bool notify_12_1(state_t & state);
    bool loop_14_0(state_t & state);
    bool uint_14_0(state_t & state);
    void _uint_14_0(const char * data, unsigned len, uint64_t consumed);
};
#endif
