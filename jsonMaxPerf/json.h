// ==============================================================
// Date: 2026-05-06 08:57:59 GMT
// Generated using vProto(2026.05.06)        https://www.cgen.dev
// Author: Sergey Shchekoldin        Email: shchekoldin@gmail.com
// ==============================================================

#ifndef JSON_H
#define JSON_H
#pragma once

#include <array>
#include <cstdint>
#include <cstdio>
#include <string>
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
    template<class... Args> explicit json(Args && ... args) : jsonResult(std::forward<Args>(args)...) {}
    bool parse(const char * data, unsigned len);
    bool parse(const std::string & data) { return parse(data.data(), data.length()); }
    bool empty() const { return mstate.node == NodeT::NoState; }
    void reset();

private:
    enum class NodeT
    {
        Loop1_0, // line_1
            Range1_0,
            Range2_0, Func2_1, Notify2_2,
            Range3_0, Func3_1, Notify3_2,
            Text4_0, StrView4_1, Text4_2, Range4_3, Cases4_4,
                Text5_0, Range5_1, Cases5_2,
                    Text6_0, StrView6_1, Text6_2, Notify6_3,
                    StrView7_0, Notify7_1,
                    Range8_0, Func8_1, Notify8_2,
                Text9_0, Func9_1, Notify9_2,
                Range10_0, Func10_1, Notify10_2, Cases10_3,
                    Func11_0, Notify11_1,
            StrView12_0, Notify12_1,
        Loop14_0, // line_14
            Uint14_0,
        Loop16_0, // line_16
        NoState
    };
    struct StateT
    {
        const char * data = nullptr;
        const char * end = nullptr;
        uint64_t consumed = 0;
        NodeT node = NodeT::Loop1_0;
        unsigned remain() const { return unsigned(end - data); }
        const char * name() const;
    };
    StateT mstate;

    void parse(StateT & state);
    bool loop1_0(StateT & state);
    bool range1_0(StateT & state) const;
    bool range2_0(StateT & state) const;
    bool func2_1(StateT & state);
    bool func2_1();
    bool notify2_2(StateT & state);
    bool range3_0(StateT & state) const;
    bool func3_1(StateT & state);
    bool func3_1();
    bool notify3_2(StateT & state);
    bool text4_0(StateT & state) const;
    bool strview4_1(StateT & state);
    void strview4_1(const char * data, unsigned len, uint64_t consumed);
    bool text4_2(StateT & state) const;
    bool range4_3(StateT & state) const;
    bool cases4_4(StateT & state) const;
    bool text5_0(StateT & state) const;
    bool range5_1(StateT & state) const;
    bool cases5_2(StateT & state);
    bool text6_0(StateT & state) const;
    bool strview6_1(StateT & state);
    void strview6_1(const char * data, unsigned len, uint64_t consumed);
    bool text6_2(StateT & state) const;
    bool notify6_3(StateT & state);
    bool strview7_0(StateT & state);
    void strview7_0(const char * data, unsigned len, uint64_t consumed);
    bool notify7_1(StateT & state);
    bool range8_0(StateT & state) const;
    bool func8_1(StateT & state);
    bool func8_1();
    bool notify8_2(StateT & state);
    bool text9_0(StateT & state) const;
    bool func9_1(StateT & state);
    bool func9_1();
    bool notify9_2(StateT & state);
    bool range10_0(StateT & state) const;
    bool func10_1(StateT & state);
    bool func10_1();
    bool notify10_2(StateT & state);
    bool cases10_3(StateT & state);
    bool func11_0(StateT & state);
    bool func11_0();
    bool notify11_1(StateT & state);
    bool strview12_0(StateT & state);
    void strview12_0(const char * data, unsigned len, uint64_t consumed);
    bool notify12_1(StateT & state);
    bool loop14_0(StateT & state);
    bool uint14_0(StateT & state);
    void uint14_0(const char * data, unsigned len, uint64_t consumed);
    bool loop16_0(StateT & state) const;
};
#endif
