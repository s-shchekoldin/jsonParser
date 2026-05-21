// ==============================================================
// Date: 2026-05-21 21:55:09 GMT
// Generated using vProto(2026.05.21)        https://www.cgen.dev
// Author: Sergey Shchekoldin        Email: shchekoldin@gmail.com
// ==============================================================

#ifndef JSON_H
#define JSON_H
#pragma once

#include <array>
#include <cstdint>
#include <cstdio>
#include <string>

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
    template<class... Args> explicit json(Args && ... args) : jsonResult(std::forward<Args>(args)...) {}
    bool parse(const char * data, const char * end);
    bool parse(const char * data, size_t length) { return parse(data, data + length); }
    bool parse(const std::string & data) { return parse(data.data(), data.data() + data.length()); }
    bool empty() const { return mstate.node == NodeT::NoState; }
    void reset();

private:
    enum class NodeT
    {
        Loop1_0, // line_1
            Range1_0,
            Range2_0, Func2_1, Notify2_2,
            Range3_0, Func3_1, Notify3_2,
            Text4_0, String4_1, Text4_2, Range4_3, Cases4_4,
                Text5_0, Range5_1, Cases5_2,
                    Text6_0, String6_1, Text6_2, Notify6_3,
                    String7_0, Notify7_1,
                    Range8_0, Func8_1, Notify8_2,
                Text9_0, Func9_1, Notify9_2,
                Range10_0, Func10_1, Notify10_2, Cases10_3,
                    Func11_0, Notify11_1,
            String12_0, Notify12_1,
        Loop14_0, // line_14
            Uint14_0,
        Loop16_0, // line_16
        NoState
    };
    struct StateT
    {
        uint64_t consumed = 0;
        NodeT node = NodeT::Loop1_0;
        const char * name() const;
    };
    StateT mstate;

    void parse(StateT & state, const char *& data, const char * end);
    bool func2_1();
    bool func3_1();
    void string4_1(const char * data, size_t len, uint64_t consumed);
    void string6_1(const char * data, size_t len, uint64_t consumed);
    void string7_0(const char * data, size_t len, uint64_t consumed);
    bool func8_1();
    bool func9_1();
    bool func10_1();
    bool func11_0();
    void string12_0(const char * data, size_t len, uint64_t consumed);
    void uint14_0(const char * data, size_t len, uint64_t consumed);
};
#endif
