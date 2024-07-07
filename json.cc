// ==============================================================
// Generated using https://www.vsyn.ru/
// Author: Sergey V. Shchekoldin     Email: shchekoldin@gmail.com
// ==============================================================

#include "json.h"

inline void json::parse(state_t & state)
{
    while(true)
    {
#ifdef DEBUG_MODE
        printf("State%s: %s data: [%x, %x, %x, %x, %x]=%.*s\n", &state == &mainState ? "" : "*", state.name(),
            uint8_t(&state.data[0] < state.end ? state.data[0] : 0),
            uint8_t(&state.data[1] < state.end ? state.data[1] : 0),
            uint8_t(&state.data[2] < state.end ? state.data[2] : 0),
            uint8_t(&state.data[3] < state.end ? state.data[3] : 0),
            uint8_t(&state.data[4] < state.end ? state.data[4] : 0),
            10, state.data);
#endif
        node_t n = state.node;
        const char * d = state.data;
        switch(state.node)
        {
            case node_t::LOOP_1_0: loop_1_0(state); break;
            case node_t::LABEL_1_0: if (!label_1_0(state) || state.node != node_t::LOOP_1_1) break; __attribute__ ((fallthrough));
            case node_t::LOOP_1_1: loop_1_1(state); break;
            case node_t::RANGE_2_0: range_2_0(state); break;
            case node_t::RANGE_3_0: if (!range_3_0(state) || state.node != node_t::FUNC_3_1) break; __attribute__ ((fallthrough));
            case node_t::FUNC_3_1: if (!func_3_1(state) || state.node != node_t::NOTIFY_3_2) break; __attribute__ ((fallthrough));
            case node_t::NOTIFY_3_2: if (!notify_3_2(state) || state.node != node_t::FUNC_3_3) break; __attribute__ ((fallthrough));
            case node_t::FUNC_3_3: func_3_3(state); break;
            case node_t::RANGE_4_0: if (!range_4_0(state) || state.node != node_t::FUNC_4_1) break; __attribute__ ((fallthrough));
            case node_t::FUNC_4_1: if (!func_4_1(state) || state.node != node_t::NOTIFY_4_2) break; __attribute__ ((fallthrough));
            case node_t::NOTIFY_4_2: notify_4_2(state); break;
            case node_t::TEXT_5_0: if (!text_5_0(state) || state.node != node_t::GOTO_5_1) break; __attribute__ ((fallthrough));
            case node_t::GOTO_5_1: if (!goto_5_1(state) || state.node != node_t::FUNC_5_2) break; __attribute__ ((fallthrough));
            case node_t::FUNC_5_2: func_5_2(state); break;
            case node_t::LOOP_7_0: loop_7_0(state); break;
            case node_t::LABEL_7_0: if (!label_7_0(state) || state.node != node_t::LOOP_7_1) break; __attribute__ ((fallthrough));
            case node_t::LOOP_7_1: loop_7_1(state); break;
            case node_t::STRING_8_0: if (!string_8_0(state) || state.node != node_t::RANGE_8_1) break; __attribute__ ((fallthrough));
            case node_t::RANGE_8_1: if (!range_8_1(state) || state.node != node_t::RANGE_8_2) break; __attribute__ ((fallthrough));
            case node_t::RANGE_8_2: if (!range_8_2(state) || state.node != node_t::CASES_8_3) break; __attribute__ ((fallthrough));
            case node_t::CASES_8_3: cases_8_3(state); break;
            case node_t::TEXT_9_0: if (!text_9_0(state) || state.node != node_t::RANGE_9_1) break; __attribute__ ((fallthrough));
            case node_t::RANGE_9_1: if (!range_9_1(state) || state.node != node_t::CASES_9_2) break; __attribute__ ((fallthrough));
            case node_t::CASES_9_2: cases_9_2(state); break;
            case node_t::TEXT_10_0: if (!text_10_0(state) || state.node != node_t::GOTO_10_1) break; __attribute__ ((fallthrough));
            case node_t::GOTO_10_1: if (!goto_10_1(state) || state.node != node_t::NOTIFY_10_2) break; __attribute__ ((fallthrough));
            case node_t::NOTIFY_10_2: if (!notify_10_2(state) || state.node != node_t::RET_10_3) break; __attribute__ ((fallthrough));
            case node_t::RET_10_3: ret_10_3(state); break;
            case node_t::TEXT_11_0: if (!text_11_0(state, false) || state.node != node_t::FUNC_11_1) break; __attribute__ ((fallthrough));
            case node_t::FUNC_11_1: if (!func_11_1(state) || state.node != node_t::NOTIFY_11_2) break; __attribute__ ((fallthrough));
            case node_t::NOTIFY_11_2: if (!notify_11_2(state) || state.node != node_t::RET_11_3) break; __attribute__ ((fallthrough));
            case node_t::RET_11_3: ret_11_3(state); break;
            case node_t::TEXT_12_0: if (!text_12_0(state, false) || state.node != node_t::FUNC_12_1) break; __attribute__ ((fallthrough));
            case node_t::FUNC_12_1: if (!func_12_1(state) || state.node != node_t::NOTIFY_12_2) break; __attribute__ ((fallthrough));
            case node_t::NOTIFY_12_2: if (!notify_12_2(state) || state.node != node_t::RET_12_3) break; __attribute__ ((fallthrough));
            case node_t::RET_12_3: ret_12_3(state); break;
            case node_t::TEXT_13_0: if (!text_13_0(state, false) || state.node != node_t::FUNC_13_1) break; __attribute__ ((fallthrough));
            case node_t::FUNC_13_1: if (!func_13_1(state) || state.node != node_t::NOTIFY_13_2) break; __attribute__ ((fallthrough));
            case node_t::NOTIFY_13_2: if (!notify_13_2(state) || state.node != node_t::RET_13_3) break; __attribute__ ((fallthrough));
            case node_t::RET_13_3: ret_13_3(state); break;
            case node_t::STRING_14_0: if (!string_14_0(state) || state.node != node_t::NOTIFY_14_1) break; __attribute__ ((fallthrough));
            case node_t::NOTIFY_14_1: if (!notify_14_1(state) || state.node != node_t::RET_14_2) break; __attribute__ ((fallthrough));
            case node_t::RET_14_2: ret_14_2(state); break;
            case node_t::FUNC_15_0: if (!func_15_0(state) || state.node != node_t::RET_15_1) break; __attribute__ ((fallthrough));
            case node_t::RET_15_1: ret_15_1(state); break;
            case node_t::TEXT_16_0: if (!text_16_0(state) || state.node != node_t::FUNC_16_1) break; __attribute__ ((fallthrough));
            case node_t::FUNC_16_1: if (!func_16_1(state) || state.node != node_t::NOTIFY_16_2) break; __attribute__ ((fallthrough));
            case node_t::NOTIFY_16_2: if (!notify_16_2(state) || state.node != node_t::RET_16_3) break; __attribute__ ((fallthrough));
            case node_t::RET_16_3: ret_16_3(state); break;
            case node_t::FUNC_17_0: if (!func_17_0(state) || state.node != node_t::NOTIFY_17_1) break; __attribute__ ((fallthrough));
            case node_t::NOTIFY_17_1: if (!notify_17_1(state) || state.node != node_t::RET_17_2) break; __attribute__ ((fallthrough));
            case node_t::RET_17_2: ret_17_2(state); break;
            case node_t::LOOP_19_0: loop_19_0(state); break;
            case node_t::LABEL_19_0: if (!label_19_0(state) || state.node != node_t::FUNC_19_1) break; __attribute__ ((fallthrough));
            case node_t::FUNC_19_1: if (!func_19_1(state) || state.node != node_t::LOOP_19_2) break; __attribute__ ((fallthrough));
            case node_t::LOOP_19_2: loop_19_2(state); break;
            case node_t::STRING_20_0: if (!string_20_0(state) || state.node != node_t::FUNC_20_1) break; __attribute__ ((fallthrough));
            case node_t::FUNC_20_1: func_20_1(state); break;
            case node_t::TEXT_21_0: if (!text_21_0(state) || state.node != node_t::RET_21_1) break; __attribute__ ((fallthrough));
            case node_t::RET_21_1: ret_21_1(state); break;
            case node_t::TEXT_22_0: if (!text_22_0(state) || state.node != node_t::CASES_22_1) break; __attribute__ ((fallthrough));
            case node_t::CASES_22_1: cases_22_1(state); break;
            case node_t::TEXT_23_0: if (!text_23_0(state) || state.node != node_t::FUNC_23_1) break; __attribute__ ((fallthrough));
            case node_t::FUNC_23_1: func_23_1(state); break;
            case node_t::TEXT_24_0: if (!text_24_0(state) || state.node != node_t::FUNC_24_1) break; __attribute__ ((fallthrough));
            case node_t::FUNC_24_1: func_24_1(state); break;
            case node_t::TEXT_25_0: if (!text_25_0(state) || state.node != node_t::FUNC_25_1) break; __attribute__ ((fallthrough));
            case node_t::FUNC_25_1: func_25_1(state); break;
            case node_t::TEXT_26_0: if (!text_26_0(state) || state.node != node_t::FUNC_26_1) break; __attribute__ ((fallthrough));
            case node_t::FUNC_26_1: func_26_1(state); break;
            case node_t::TEXT_27_0: if (!text_27_0(state) || state.node != node_t::FUNC_27_1) break; __attribute__ ((fallthrough));
            case node_t::FUNC_27_1: func_27_1(state); break;
            case node_t::LOOP_29_0: loop_29_0(state); break;
            case node_t::UINT_29_0: if (!uint_29_0(state) || state.node != node_t::STRING_29_1) break; __attribute__ ((fallthrough));
            case node_t::STRING_29_1: string_29_1(state); break;
            case node_t::NO_STATE:
            default: return;
        }; // switch
        if (n == state.node && d == state.data)
            break;
    }
}

bool json::parse(const char * data, unsigned len)
{
    mainState.data = data;
    mainState.end = &data[len];
    parse(mainState);
    return mainState.node != node_t::NO_STATE;
}

inline bool json::loop_1_0(state_t & state)
{
    return label_1_0(state);
}

inline bool json::label_1_0(state_t & state)
{
    state.node = node_t::LOOP_1_1;
    return true;
}

inline bool json::loop_1_1(state_t & state)
{
    if (state.data == state.end)
        return true;
    state_t startState = state;
    if (range_2_0(state)) // case_1
        return true;
    state = startState;
    if (range_3_0(state)) // case_2
        return true;
    state = startState;
    if (range_4_0(state)) // case_3
        return true;
    state = startState;
    if (text_5_0(state)) // case_4
        return true;
    state = startState;
    state.node = node_t::NO_STATE;
    return true;
}

inline bool json::range_2_0(state_t & state)
{
    const static bool exitSym[256] = {
         true,  true,  true,  true,  true,  true,  true,  true,  true, false, false,  true,  true, false,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
        false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true, false,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0x9-0xa][0xd][0x20][0x2c][0x2e]
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        unsigned exitCount = 0;
        if(&state.data[8] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])])
                exitCount = 0;
            else if (exitSym[uint8_t(state.data[1])])
                exitCount = 1;
            else if (exitSym[uint8_t(state.data[2])])
                exitCount = 2;
            else if (exitSym[uint8_t(state.data[3])])
                exitCount = 3;
            else if (exitSym[uint8_t(state.data[4])])
                exitCount = 4;
            else if (exitSym[uint8_t(state.data[5])])
                exitCount = 5;
            else if (exitSym[uint8_t(state.data[6])])
                exitCount = 6;
            else if (exitSym[uint8_t(state.data[7])])
                exitCount = 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])])
        {
            state.data++;
            continue;
        }
        state.data += exitCount;
        state.consumed += unsigned(state.data - beginData);
        state.node = (state.consumed >= 1) ? node_t::LOOP_1_1 : node_t::NO_STATE;
        bool ret = (state.node == node_t::LOOP_1_1);
        state.consumed = 0;
        return ret;
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_2_0;
    return true;
}

inline bool json::range_3_0(state_t & state)
{
    const static bool exitSym[256] = {
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0x5b][0x7b]
    while(state.data < state.end)
    {
        unsigned stateDataCount = 1;
        for(unsigned i = 0; i < stateDataCount; i++)
            if (exitSym[uint8_t(state.data[i])])
            {
                state.data += i;
                state.consumed += i;
                state.node = (state.consumed >= 1) ? node_t::FUNC_3_1 : node_t::NO_STATE;
                bool ret = (state.node == node_t::FUNC_3_1);
                state.consumed = 0;
                return ret;
            }
        state.data += stateDataCount;
        state.node = node_t::FUNC_3_1;
        return true;
    }
    state.node = node_t::RANGE_3_0;
    return true;
}

inline bool json::_func_3_1()
{
     depth++; 
    return true;
}
inline bool json::func_3_1(state_t & state)
{
    bool ret = _func_3_1();
    state.node = ret ? node_t::NOTIFY_3_2 : node_t::NO_STATE;
    return ret;
}

inline bool json::notify_3_2(state_t & state)
{
    pushDepth();
    state.node = node_t::FUNC_3_3;
    return true;
}

inline bool json::_func_3_3()
{
     nameDepth.clear(); 
    return true;
}
inline bool json::func_3_3(state_t & state)
{
    bool ret = _func_3_3();
    state.node = ret ? node_t::LOOP_1_1 : node_t::NO_STATE;
    return ret;
}

inline bool json::range_4_0(state_t & state)
{
    const static bool exitSym[256] = {
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0x5d][0x7d]
    while(state.data < state.end)
    {
        unsigned stateDataCount = 1;
        for(unsigned i = 0; i < stateDataCount; i++)
            if (exitSym[uint8_t(state.data[i])])
            {
                state.data += i;
                state.consumed += i;
                state.node = (state.consumed >= 1) ? node_t::FUNC_4_1 : node_t::NO_STATE;
                bool ret = (state.node == node_t::FUNC_4_1);
                state.consumed = 0;
                return ret;
            }
        state.data += stateDataCount;
        state.node = node_t::FUNC_4_1;
        return true;
    }
    state.node = node_t::RANGE_4_0;
    return true;
}

inline bool json::_func_4_1()
{
     depth--; 
    return true;
}
inline bool json::func_4_1(state_t & state)
{
    bool ret = _func_4_1();
    state.node = ret ? node_t::NOTIFY_4_2 : node_t::NO_STATE;
    return ret;
}

inline bool json::notify_4_2(state_t & state)
{
    popDepth();
    state.node = node_t::LOOP_1_1;
    return true;
}

inline bool json::text_5_0(state_t & state)
{
    static uint8_t text[] = { 0x22 }; // "
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (text[state.consumed++] != sym)
        {
            state.node = node_t::NO_STATE;
            state.consumed = 0;
            return false;
        }
        else if (state.consumed >= sizeof(text))
        {
            state.data++;
            state.consumed = 0;
            state.node = node_t::GOTO_5_1;
            return true;
        }
    }
    state.node = node_t::TEXT_5_0;
    return true;
}

inline bool json::goto_5_1(state_t & state)
{
    state.node = node_t::LABEL_7_0;
    if (state.retStackCount < sizeof(state.retStack)/sizeof(state.retStack[0]))
        state.retStack[state.retStackCount++] = node_t::FUNC_5_2;
    else
    {
        for(unsigned i = 1; i < sizeof(state.retStack)/sizeof(state.retStack[0]); i++)
            state.retStack[i - 1] = state.retStack[i];
        state.retStack[sizeof(state.retStack)/sizeof(state.retStack[0]) - 1] = node_t::FUNC_5_2;
    }
    return true;
}

inline bool json::_func_5_2()
{
     key.clear(); value.clear(); 
    return true;
}
inline bool json::func_5_2(state_t & state)
{
    bool ret = _func_5_2();
    state.node = ret ? node_t::LOOP_1_1 : node_t::NO_STATE;
    return ret;
}

inline bool json::loop_7_0(state_t & state)
{
    return label_7_0(state);
}

inline bool json::label_7_0(state_t & state)
{
    state.node = node_t::LOOP_7_1;
    return true;
}

inline bool json::loop_7_1(state_t & state)
{
    return string_8_0(state);
}

inline void json::_string_8_0(const char * data, unsigned len, bool isFirst)
{
    if (isFirst)
        jsonResult::key.clear();
    else if ((jsonResult::key.length() + len) > 256)
        len = 256 - jsonResult::key.length();
    jsonResult::key.append(data, len);
}

inline bool json::string_8_0(state_t & state)
{
    const static bool exitSym[256] = {
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false,  true, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}; // ^[0x22]
    bool isFirstData = !state.consumed;
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        unsigned exitCount = 0;
        if(&state.data[8] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])])
                exitCount = 0;
            else if (exitSym[uint8_t(state.data[1])])
                exitCount = 1;
            else if (exitSym[uint8_t(state.data[2])])
                exitCount = 2;
            else if (exitSym[uint8_t(state.data[3])])
                exitCount = 3;
            else if (exitSym[uint8_t(state.data[4])])
                exitCount = 4;
            else if (exitSym[uint8_t(state.data[5])])
                exitCount = 5;
            else if (exitSym[uint8_t(state.data[6])])
                exitCount = 6;
            else if (exitSym[uint8_t(state.data[7])])
                exitCount = 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])])
        {
            state.data++;
            continue;
        }
        state.data += exitCount;
        _string_8_0(beginData, unsigned(state.data - beginData), isFirstData);
        state.consumed += unsigned(state.data - beginData);
        state.node = (state.consumed >= 1) ? node_t::RANGE_8_1 : node_t::NO_STATE;
        bool ret = (state.node == node_t::RANGE_8_1);
        state.consumed = 0;
        return ret;
    }
    state.consumed += unsigned(state.data - beginData);
    if (beginData < state.data)
        _string_8_0(beginData, unsigned(state.data - beginData), isFirstData);
    state.node = node_t::STRING_8_0;
    return true;
}

inline bool json::range_8_1(state_t & state)
{
    const static bool exitSym[256] = {
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true, false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0x22]
    while(state.data < state.end)
    {
        unsigned stateDataCount = 1;
        for(unsigned i = 0; i < stateDataCount; i++)
            if (exitSym[uint8_t(state.data[i])])
            {
                state.data += i;
                state.consumed += i;
                state.node = (state.consumed >= 1) ? node_t::RANGE_8_2 : node_t::NO_STATE;
                bool ret = (state.node == node_t::RANGE_8_2);
                state.consumed = 0;
                return ret;
            }
        state.data += stateDataCount;
        state.node = node_t::RANGE_8_2;
        return true;
    }
    state.node = node_t::RANGE_8_1;
    return true;
}

inline bool json::range_8_2(state_t & state)
{
    const static bool exitSym[256] = {
         true,  true,  true,  true,  true,  true,  true,  true,  true, false, false,  true,  true, false,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
        false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0x9-0xa][0xd][0x20]
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        unsigned exitCount = 0;
        if(&state.data[8] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])])
                exitCount = 0;
            else if (exitSym[uint8_t(state.data[1])])
                exitCount = 1;
            else if (exitSym[uint8_t(state.data[2])])
                exitCount = 2;
            else if (exitSym[uint8_t(state.data[3])])
                exitCount = 3;
            else if (exitSym[uint8_t(state.data[4])])
                exitCount = 4;
            else if (exitSym[uint8_t(state.data[5])])
                exitCount = 5;
            else if (exitSym[uint8_t(state.data[6])])
                exitCount = 6;
            else if (exitSym[uint8_t(state.data[7])])
                exitCount = 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])])
        {
            state.data++;
            continue;
        }
        state.data += exitCount;
        state.node = node_t::CASES_8_3;
        bool ret = (state.node == node_t::CASES_8_3);
        state.consumed = 0;
        return ret;
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_8_2;
    return true;
}

inline bool json::cases_8_3(state_t & state)
{
    if (state.data == state.end)
        return true;
    state_t startState = state;
    if (text_9_0(state)) // case_1
        return true;
    state = startState;
    if (text_16_0(state)) // case_2
        return true;
    state = startState;
    state.node = node_t::FUNC_17_0;
    return true;
}

inline bool json::text_9_0(state_t & state)
{
    static uint8_t text[] = { 0x3a }; // :
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (text[state.consumed++] != sym)
        {
            state.node = node_t::FUNC_17_0;
            state.consumed = 0;
            return false;
        }
        else if (state.consumed >= sizeof(text))
        {
            state.data++;
            state.consumed = 0;
            state.node = node_t::RANGE_9_1;
            return true;
        }
    }
    state.node = node_t::TEXT_9_0;
    return true;
}

inline bool json::range_9_1(state_t & state)
{
    const static bool exitSym[256] = {
         true,  true,  true,  true,  true,  true,  true,  true,  true, false, false,  true,  true, false,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
        false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0x9-0xa][0xd][0x20]
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        unsigned exitCount = 0;
        if(&state.data[8] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])])
                exitCount = 0;
            else if (exitSym[uint8_t(state.data[1])])
                exitCount = 1;
            else if (exitSym[uint8_t(state.data[2])])
                exitCount = 2;
            else if (exitSym[uint8_t(state.data[3])])
                exitCount = 3;
            else if (exitSym[uint8_t(state.data[4])])
                exitCount = 4;
            else if (exitSym[uint8_t(state.data[5])])
                exitCount = 5;
            else if (exitSym[uint8_t(state.data[6])])
                exitCount = 6;
            else if (exitSym[uint8_t(state.data[7])])
                exitCount = 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])])
        {
            state.data++;
            continue;
        }
        state.data += exitCount;
        state.node = node_t::CASES_9_2;
        bool ret = (state.node == node_t::CASES_9_2);
        state.consumed = 0;
        return ret;
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_9_1;
    return true;
}

inline bool json::cases_9_2(state_t & state)
{
    if (state.data == state.end)
        return true;
    state_t startState = state;
    if (text_10_0(state)) // case_1
        return true;
    state = startState;
    if (text_11_0(state, true)) // case_2
        return true;
    state = startState;
    if (text_12_0(state, true)) // case_3
        return true;
    state = startState;
    if (text_13_0(state, true)) // case_4
        return true;
    state = startState;
    if (string_14_0(state)) // case_5
        return true;
    state = startState;
    state.node = node_t::FUNC_15_0;
    return true;
}

inline bool json::text_10_0(state_t & state)
{
    static uint8_t text[] = { 0x22 }; // "
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (text[state.consumed++] != sym)
        {
            state.node = node_t::FUNC_15_0;
            state.consumed = 0;
            return false;
        }
        else if (state.consumed >= sizeof(text))
        {
            state.data++;
            state.consumed = 0;
            state.node = node_t::GOTO_10_1;
            return true;
        }
    }
    state.node = node_t::TEXT_10_0;
    return true;
}

inline bool json::goto_10_1(state_t & state)
{
    state.node = node_t::LABEL_19_0;
    if (state.retStackCount < sizeof(state.retStack)/sizeof(state.retStack[0]))
        state.retStack[state.retStackCount++] = node_t::NOTIFY_10_2;
    else
    {
        for(unsigned i = 1; i < sizeof(state.retStack)/sizeof(state.retStack[0]); i++)
            state.retStack[i - 1] = state.retStack[i];
        state.retStack[sizeof(state.retStack)/sizeof(state.retStack[0]) - 1] = node_t::NOTIFY_10_2;
    }
    return true;
}

inline bool json::notify_10_2(state_t & state)
{
    gotKV();
    state.node = node_t::RET_10_3;
    return true;
}

inline bool json::ret_10_3(state_t & state)
{
    state.node = state.retStackCount ? state.retStack[--state.retStackCount] : node_t::NO_STATE;
    return state.node != node_t::NO_STATE;
}

inline bool json::text_11_0(state_t & state, bool isCaseCall)
{
    static uint8_t text[] = { 0x74, 0x72, 0x75, 0x65 }; // true
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (sym >= 'A' && sym <= 'Z')
            sym |= 0x20;
        if (text[state.consumed++] != sym)
        {
            state.node = node_t::FUNC_15_0;
            bool ret = isCaseCall && state.consumed > 1;
            state.consumed = 0;
            return ret;
        }
        else if (state.consumed >= sizeof(text))
        {
            state.data++;
            state.consumed = 0;
            state.node = node_t::FUNC_11_1;
            return true;
        }
    }
    state.node = node_t::TEXT_11_0;
    return true;
}

inline bool json::_func_11_1()
{
     value = "true"; 
    return true;
}
inline bool json::func_11_1(state_t & state)
{
    bool ret = _func_11_1();
    state.node = ret ? node_t::NOTIFY_11_2 : node_t::FUNC_15_0;
    return ret;
}

inline bool json::notify_11_2(state_t & state)
{
    gotKV();
    state.node = node_t::RET_11_3;
    return true;
}

inline bool json::ret_11_3(state_t & state)
{
    state.node = state.retStackCount ? state.retStack[--state.retStackCount] : node_t::NO_STATE;
    return state.node != node_t::NO_STATE;
}

inline bool json::text_12_0(state_t & state, bool isCaseCall)
{
    static uint8_t text[] = { 0x66, 0x61, 0x6c, 0x73, 0x65 }; // false
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (sym >= 'A' && sym <= 'Z')
            sym |= 0x20;
        if (text[state.consumed++] != sym)
        {
            state.node = node_t::FUNC_15_0;
            bool ret = isCaseCall && state.consumed > 1;
            state.consumed = 0;
            return ret;
        }
        else if (state.consumed >= sizeof(text))
        {
            state.data++;
            state.consumed = 0;
            state.node = node_t::FUNC_12_1;
            return true;
        }
    }
    state.node = node_t::TEXT_12_0;
    return true;
}

inline bool json::_func_12_1()
{
     value = "false"; 
    return true;
}
inline bool json::func_12_1(state_t & state)
{
    bool ret = _func_12_1();
    state.node = ret ? node_t::NOTIFY_12_2 : node_t::FUNC_15_0;
    return ret;
}

inline bool json::notify_12_2(state_t & state)
{
    gotKV();
    state.node = node_t::RET_12_3;
    return true;
}

inline bool json::ret_12_3(state_t & state)
{
    state.node = state.retStackCount ? state.retStack[--state.retStackCount] : node_t::NO_STATE;
    return state.node != node_t::NO_STATE;
}

inline bool json::text_13_0(state_t & state, bool isCaseCall)
{
    static uint8_t text[] = { 0x6e, 0x75, 0x6c, 0x6c }; // null
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (sym >= 'A' && sym <= 'Z')
            sym |= 0x20;
        if (text[state.consumed++] != sym)
        {
            state.node = node_t::FUNC_15_0;
            bool ret = isCaseCall && state.consumed > 1;
            state.consumed = 0;
            return ret;
        }
        else if (state.consumed >= sizeof(text))
        {
            state.data++;
            state.consumed = 0;
            state.node = node_t::FUNC_13_1;
            return true;
        }
    }
    state.node = node_t::TEXT_13_0;
    return true;
}

inline bool json::_func_13_1()
{
     value = "null"; 
    return true;
}
inline bool json::func_13_1(state_t & state)
{
    bool ret = _func_13_1();
    state.node = ret ? node_t::NOTIFY_13_2 : node_t::FUNC_15_0;
    return ret;
}

inline bool json::notify_13_2(state_t & state)
{
    gotKV();
    state.node = node_t::RET_13_3;
    return true;
}

inline bool json::ret_13_3(state_t & state)
{
    state.node = state.retStackCount ? state.retStack[--state.retStackCount] : node_t::NO_STATE;
    return state.node != node_t::NO_STATE;
}

inline void json::_string_14_0(const char * data, unsigned len, bool isFirst)
{
    if (isFirst)
        jsonResult::value.clear();
    else if ((jsonResult::value.length() + len) > 256)
        len = 256 - jsonResult::value.length();
    jsonResult::value.append(data, len);
}

inline bool json::string_14_0(state_t & state)
{
    const static bool exitSym[256] = {
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false, false,  true, 
        false, false, false, false, false, false, false, false, false, false,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0x2d-0x2e][0-9]
    bool isFirstData = !state.consumed;
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        unsigned exitCount = 0;
        if(&state.data[8] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])])
                exitCount = 0;
            else if (exitSym[uint8_t(state.data[1])])
                exitCount = 1;
            else if (exitSym[uint8_t(state.data[2])])
                exitCount = 2;
            else if (exitSym[uint8_t(state.data[3])])
                exitCount = 3;
            else if (exitSym[uint8_t(state.data[4])])
                exitCount = 4;
            else if (exitSym[uint8_t(state.data[5])])
                exitCount = 5;
            else if (exitSym[uint8_t(state.data[6])])
                exitCount = 6;
            else if (exitSym[uint8_t(state.data[7])])
                exitCount = 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])])
        {
            state.data++;
            continue;
        }
        state.data += exitCount;
        _string_14_0(beginData, unsigned(state.data - beginData), isFirstData);
        state.consumed += unsigned(state.data - beginData);
        state.node = (state.consumed >= 1) ? node_t::NOTIFY_14_1 : node_t::FUNC_15_0;
        bool ret = (state.node == node_t::NOTIFY_14_1);
        state.consumed = 0;
        return ret;
    }
    state.consumed += unsigned(state.data - beginData);
    if (beginData < state.data)
        _string_14_0(beginData, unsigned(state.data - beginData), isFirstData);
    state.node = node_t::STRING_14_0;
    return true;
}

inline bool json::notify_14_1(state_t & state)
{
    gotKV();
    state.node = node_t::RET_14_2;
    return true;
}

inline bool json::ret_14_2(state_t & state)
{
    state.node = state.retStackCount ? state.retStack[--state.retStackCount] : node_t::NO_STATE;
    return state.node != node_t::NO_STATE;
}

inline bool json::_func_15_0()
{
     nameDepth = key; 
    return true;
}
inline bool json::func_15_0(state_t & state)
{
    bool ret = _func_15_0();
    state.node = ret ? node_t::RET_15_1 : node_t::FUNC_17_0;
    return ret;
}

inline bool json::ret_15_1(state_t & state)
{
    state.node = state.retStackCount ? state.retStack[--state.retStackCount] : node_t::NO_STATE;
    return state.node != node_t::NO_STATE;
}

inline bool json::text_16_0(state_t & state)
{
    static uint8_t text[] = { 0x2c }; // ,
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (text[state.consumed++] != sym)
        {
            state.node = node_t::FUNC_17_0;
            state.consumed = 0;
            return false;
        }
        else if (state.consumed >= sizeof(text))
        {
            state.data++;
            state.consumed = 0;
            state.node = node_t::FUNC_16_1;
            return true;
        }
    }
    state.node = node_t::TEXT_16_0;
    return true;
}

inline bool json::_func_16_1()
{
     key.swap(value); 
    return true;
}
inline bool json::func_16_1(state_t & state)
{
    bool ret = _func_16_1();
    state.node = ret ? node_t::NOTIFY_16_2 : node_t::FUNC_17_0;
    return ret;
}

inline bool json::notify_16_2(state_t & state)
{
    gotVal();
    state.node = node_t::RET_16_3;
    return true;
}

inline bool json::ret_16_3(state_t & state)
{
    state.node = state.retStackCount ? state.retStack[--state.retStackCount] : node_t::NO_STATE;
    return state.node != node_t::NO_STATE;
}

inline bool json::_func_17_0()
{
     key.swap(value); 
    return true;
}
inline bool json::func_17_0(state_t & state)
{
    bool ret = _func_17_0();
    state.node = ret ? node_t::NOTIFY_17_1 : node_t::NO_STATE;
    return ret;
}

inline bool json::notify_17_1(state_t & state)
{
    gotVal();
    state.node = node_t::RET_17_2;
    return true;
}

inline bool json::ret_17_2(state_t & state)
{
    state.node = state.retStackCount ? state.retStack[--state.retStackCount] : node_t::NO_STATE;
    return state.node != node_t::NO_STATE;
}

inline bool json::loop_19_0(state_t & state)
{
    return label_19_0(state);
}

inline bool json::label_19_0(state_t & state)
{
    state.node = node_t::FUNC_19_1;
    return true;
}

inline bool json::_func_19_1()
{
     value.clear(); 
    return true;
}
inline bool json::func_19_1(state_t & state)
{
    bool ret = _func_19_1();
    state.node = ret ? node_t::LOOP_19_2 : node_t::NO_STATE;
    return ret;
}

inline bool json::loop_19_2(state_t & state)
{
    if (state.data == state.end)
        return true;
    state_t startState = state;
    if (string_20_0(state)) // case_1
        return true;
    state = startState;
    if (text_21_0(state)) // case_2
        return true;
    state = startState;
    if (text_22_0(state)) // case_3
        return true;
    state = startState;
    state.node = node_t::NO_STATE;
    return true;
}

inline void json::_string_20_0(const char * data, unsigned len, bool isFirst)
{
    if (isFirst)
        jsonResult::tmpValue.clear();
    else if ((jsonResult::tmpValue.length() + len) > 256)
        len = 256 - jsonResult::tmpValue.length();
    jsonResult::tmpValue.append(data, len);
}

inline bool json::string_20_0(state_t & state)
{
    const static bool exitSym[256] = {
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false,  true, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false,  true, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}; // ^[0x22][0x5c]
    bool isFirstData = !state.consumed;
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        unsigned exitCount = 0;
        if(&state.data[8] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])])
                exitCount = 0;
            else if (exitSym[uint8_t(state.data[1])])
                exitCount = 1;
            else if (exitSym[uint8_t(state.data[2])])
                exitCount = 2;
            else if (exitSym[uint8_t(state.data[3])])
                exitCount = 3;
            else if (exitSym[uint8_t(state.data[4])])
                exitCount = 4;
            else if (exitSym[uint8_t(state.data[5])])
                exitCount = 5;
            else if (exitSym[uint8_t(state.data[6])])
                exitCount = 6;
            else if (exitSym[uint8_t(state.data[7])])
                exitCount = 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])])
        {
            state.data++;
            continue;
        }
        state.data += exitCount;
        _string_20_0(beginData, unsigned(state.data - beginData), isFirstData);
        state.consumed += unsigned(state.data - beginData);
        state.node = (state.consumed >= 1) ? node_t::FUNC_20_1 : node_t::NO_STATE;
        bool ret = (state.node == node_t::FUNC_20_1);
        state.consumed = 0;
        return ret;
    }
    state.consumed += unsigned(state.data - beginData);
    if (beginData < state.data)
        _string_20_0(beginData, unsigned(state.data - beginData), isFirstData);
    state.node = node_t::STRING_20_0;
    return true;
}

inline bool json::_func_20_1()
{
     value += tmpValue; 
    return true;
}
inline bool json::func_20_1(state_t & state)
{
    bool ret = _func_20_1();
    state.node = ret ? node_t::LOOP_19_2 : node_t::NO_STATE;
    return ret;
}

inline bool json::text_21_0(state_t & state)
{
    static uint8_t text[] = { 0x22 }; // "
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (text[state.consumed++] != sym)
        {
            state.node = node_t::NO_STATE;
            state.consumed = 0;
            return false;
        }
        else if (state.consumed >= sizeof(text))
        {
            state.data++;
            state.consumed = 0;
            state.node = node_t::RET_21_1;
            return true;
        }
    }
    state.node = node_t::TEXT_21_0;
    return true;
}

inline bool json::ret_21_1(state_t & state)
{
    state.node = state.retStackCount ? state.retStack[--state.retStackCount] : node_t::NO_STATE;
    return state.node != node_t::NO_STATE;
}

inline bool json::text_22_0(state_t & state)
{
    static uint8_t text[] = { 0x5c }; // \x5c
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (text[state.consumed++] != sym)
        {
            state.node = node_t::NO_STATE;
            state.consumed = 0;
            return false;
        }
        else if (state.consumed >= sizeof(text))
        {
            state.data++;
            state.consumed = 0;
            state.node = node_t::CASES_22_1;
            return true;
        }
    }
    state.node = node_t::TEXT_22_0;
    return true;
}

inline bool json::cases_22_1(state_t & state)
{
    if (state.data == state.end)
        return true;
    state_t startState = state;
    if (text_23_0(state)) // case_1
        return true;
    state = startState;
    if (text_24_0(state)) // case_2
        return true;
    state = startState;
    if (text_25_0(state)) // case_3
        return true;
    state = startState;
    if (text_26_0(state)) // case_4
        return true;
    state = startState;
    if (text_27_0(state)) // case_5
        return true;
    state = startState;
    state.node = node_t::NO_STATE;
    return true;
}

inline bool json::text_23_0(state_t & state)
{
    static uint8_t text[] = { 0x6e }; // n
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (text[state.consumed++] != sym)
        {
            state.node = node_t::NO_STATE;
            state.consumed = 0;
            return false;
        }
        else if (state.consumed >= sizeof(text))
        {
            state.data++;
            state.consumed = 0;
            state.node = node_t::FUNC_23_1;
            return true;
        }
    }
    state.node = node_t::TEXT_23_0;
    return true;
}

inline bool json::_func_23_1()
{
     value += "\n"; 
    return true;
}
inline bool json::func_23_1(state_t & state)
{
    bool ret = _func_23_1();
    state.node = ret ? node_t::LOOP_19_2 : node_t::NO_STATE;
    return ret;
}

inline bool json::text_24_0(state_t & state)
{
    static uint8_t text[] = { 0x72 }; // r
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (text[state.consumed++] != sym)
        {
            state.node = node_t::NO_STATE;
            state.consumed = 0;
            return false;
        }
        else if (state.consumed >= sizeof(text))
        {
            state.data++;
            state.consumed = 0;
            state.node = node_t::FUNC_24_1;
            return true;
        }
    }
    state.node = node_t::TEXT_24_0;
    return true;
}

inline bool json::_func_24_1()
{
     value += "\r"; 
    return true;
}
inline bool json::func_24_1(state_t & state)
{
    bool ret = _func_24_1();
    state.node = ret ? node_t::LOOP_19_2 : node_t::NO_STATE;
    return ret;
}

inline bool json::text_25_0(state_t & state)
{
    static uint8_t text[] = { 0x74 }; // t
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (text[state.consumed++] != sym)
        {
            state.node = node_t::NO_STATE;
            state.consumed = 0;
            return false;
        }
        else if (state.consumed >= sizeof(text))
        {
            state.data++;
            state.consumed = 0;
            state.node = node_t::FUNC_25_1;
            return true;
        }
    }
    state.node = node_t::TEXT_25_0;
    return true;
}

inline bool json::_func_25_1()
{
     value += "\t"; 
    return true;
}
inline bool json::func_25_1(state_t & state)
{
    bool ret = _func_25_1();
    state.node = ret ? node_t::LOOP_19_2 : node_t::NO_STATE;
    return ret;
}

inline bool json::text_26_0(state_t & state)
{
    static uint8_t text[] = { 0x22 }; // "
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (text[state.consumed++] != sym)
        {
            state.node = node_t::NO_STATE;
            state.consumed = 0;
            return false;
        }
        else if (state.consumed >= sizeof(text))
        {
            state.data++;
            state.consumed = 0;
            state.node = node_t::FUNC_26_1;
            return true;
        }
    }
    state.node = node_t::TEXT_26_0;
    return true;
}

inline bool json::_func_26_1()
{
     value += "\""; 
    return true;
}
inline bool json::func_26_1(state_t & state)
{
    bool ret = _func_26_1();
    state.node = ret ? node_t::LOOP_19_2 : node_t::NO_STATE;
    return ret;
}

inline bool json::text_27_0(state_t & state)
{
    static uint8_t text[] = { 0x2f }; // /
    for(; state.data < state.end; state.data++)
    {
        uint8_t sym = (uint8_t)state.data[0];
        if (text[state.consumed++] != sym)
        {
            state.node = node_t::NO_STATE;
            state.consumed = 0;
            return false;
        }
        else if (state.consumed >= sizeof(text))
        {
            state.data++;
            state.consumed = 0;
            state.node = node_t::FUNC_27_1;
            return true;
        }
    }
    state.node = node_t::TEXT_27_0;
    return true;
}

inline bool json::_func_27_1()
{
     value += "/"; 
    return true;
}
inline bool json::func_27_1(state_t & state)
{
    bool ret = _func_27_1();
    state.node = ret ? node_t::LOOP_19_2 : node_t::NO_STATE;
    return ret;
}

inline bool json::loop_29_0(state_t & state)
{
    return uint_29_0(state);
}

inline void json::_uint_29_0(const char * data, unsigned len, bool isFirst)
{
    if (isFirst)
        jsonResult::depth = 0;
    for(const char * end = &data[len]; data < end; data++)
        jsonResult::depth = jsonResult::depth*10 + *data - '0';
}

inline bool json::uint_29_0(state_t & state)
{
    const static bool exitSym[256] = {
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
        false, false, false, false, false, false, false, false, false, false,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0-9]
    bool isFirstData = !state.consumed;
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        unsigned exitCount = 0;
        if(&state.data[8] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])])
                exitCount = 0;
            else if (exitSym[uint8_t(state.data[1])])
                exitCount = 1;
            else if (exitSym[uint8_t(state.data[2])])
                exitCount = 2;
            else if (exitSym[uint8_t(state.data[3])])
                exitCount = 3;
            else if (exitSym[uint8_t(state.data[4])])
                exitCount = 4;
            else if (exitSym[uint8_t(state.data[5])])
                exitCount = 5;
            else if (exitSym[uint8_t(state.data[6])])
                exitCount = 6;
            else if (exitSym[uint8_t(state.data[7])])
                exitCount = 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])])
        {
            state.data++;
            continue;
        }
        state.data += exitCount;
        _uint_29_0(beginData, unsigned(state.data - beginData), isFirstData);
        state.consumed += unsigned(state.data - beginData);
        state.node = (state.consumed >= 1) ? node_t::STRING_29_1 : node_t::NO_STATE;
        bool ret = (state.node == node_t::STRING_29_1);
        state.consumed = 0;
        return ret;
    }
    state.consumed += unsigned(state.data - beginData);
    if (beginData < state.data)
        _uint_29_0(beginData, unsigned(state.data - beginData), isFirstData);
    state.node = node_t::UINT_29_0;
    return true;
}

inline void json::_string_29_1(const char * data, unsigned len, bool isFirst)
{
    if (isFirst)
        jsonResult::nameDepth.clear();
    else if ((jsonResult::nameDepth.length() + len) > 256)
        len = 256 - jsonResult::nameDepth.length();
    jsonResult::nameDepth.append(data, len);
}

inline bool json::string_29_1(state_t & state)
{
    bool isFirstData = !state.consumed;
    const char * beginData = state.data;
    if (!state.consumed)
        state.node = node_t::STRING_29_1;
    if (state.data == state.end)
        return true;
    state.consumed += state.remainDataLen();
    state.data = state.end;
    _string_29_1(beginData, unsigned(state.data - beginData), isFirstData);
    return true;
}

void json::reset()
{
    jsonResult::depth = 0;
    jsonResult::key.clear();
    jsonResult::nameDepth.clear();
    jsonResult::tmpValue.clear();
    jsonResult::value.clear();
    json::mainState = json::state_t();
}

const char * json::state_t::name() const
{
    switch(node)
    {
        case node_t::LOOP_1_0: return "LOOP_1_0";
        case node_t::LABEL_1_0: return "LABEL_1_0";
        case node_t::LOOP_1_1: return "LOOP_1_1";
        case node_t::RANGE_2_0: return "RANGE_2_0";
        case node_t::RANGE_3_0: return "RANGE_3_0";
        case node_t::FUNC_3_1: return "FUNC_3_1";
        case node_t::NOTIFY_3_2: return "NOTIFY_3_2";
        case node_t::FUNC_3_3: return "FUNC_3_3";
        case node_t::RANGE_4_0: return "RANGE_4_0";
        case node_t::FUNC_4_1: return "FUNC_4_1";
        case node_t::NOTIFY_4_2: return "NOTIFY_4_2";
        case node_t::TEXT_5_0: return "TEXT_5_0";
        case node_t::GOTO_5_1: return "GOTO_5_1";
        case node_t::FUNC_5_2: return "FUNC_5_2";
        case node_t::LOOP_7_0: return "LOOP_7_0";
        case node_t::LABEL_7_0: return "LABEL_7_0";
        case node_t::LOOP_7_1: return "LOOP_7_1";
        case node_t::STRING_8_0: return "STRING_8_0";
        case node_t::RANGE_8_1: return "RANGE_8_1";
        case node_t::RANGE_8_2: return "RANGE_8_2";
        case node_t::CASES_8_3: return "CASES_8_3";
        case node_t::TEXT_9_0: return "TEXT_9_0";
        case node_t::RANGE_9_1: return "RANGE_9_1";
        case node_t::CASES_9_2: return "CASES_9_2";
        case node_t::TEXT_10_0: return "TEXT_10_0";
        case node_t::GOTO_10_1: return "GOTO_10_1";
        case node_t::NOTIFY_10_2: return "NOTIFY_10_2";
        case node_t::RET_10_3: return "RET_10_3";
        case node_t::TEXT_11_0: return "TEXT_11_0";
        case node_t::FUNC_11_1: return "FUNC_11_1";
        case node_t::NOTIFY_11_2: return "NOTIFY_11_2";
        case node_t::RET_11_3: return "RET_11_3";
        case node_t::TEXT_12_0: return "TEXT_12_0";
        case node_t::FUNC_12_1: return "FUNC_12_1";
        case node_t::NOTIFY_12_2: return "NOTIFY_12_2";
        case node_t::RET_12_3: return "RET_12_3";
        case node_t::TEXT_13_0: return "TEXT_13_0";
        case node_t::FUNC_13_1: return "FUNC_13_1";
        case node_t::NOTIFY_13_2: return "NOTIFY_13_2";
        case node_t::RET_13_3: return "RET_13_3";
        case node_t::STRING_14_0: return "STRING_14_0";
        case node_t::NOTIFY_14_1: return "NOTIFY_14_1";
        case node_t::RET_14_2: return "RET_14_2";
        case node_t::FUNC_15_0: return "FUNC_15_0";
        case node_t::RET_15_1: return "RET_15_1";
        case node_t::TEXT_16_0: return "TEXT_16_0";
        case node_t::FUNC_16_1: return "FUNC_16_1";
        case node_t::NOTIFY_16_2: return "NOTIFY_16_2";
        case node_t::RET_16_3: return "RET_16_3";
        case node_t::FUNC_17_0: return "FUNC_17_0";
        case node_t::NOTIFY_17_1: return "NOTIFY_17_1";
        case node_t::RET_17_2: return "RET_17_2";
        case node_t::LOOP_19_0: return "LOOP_19_0";
        case node_t::LABEL_19_0: return "LABEL_19_0";
        case node_t::FUNC_19_1: return "FUNC_19_1";
        case node_t::LOOP_19_2: return "LOOP_19_2";
        case node_t::STRING_20_0: return "STRING_20_0";
        case node_t::FUNC_20_1: return "FUNC_20_1";
        case node_t::TEXT_21_0: return "TEXT_21_0";
        case node_t::RET_21_1: return "RET_21_1";
        case node_t::TEXT_22_0: return "TEXT_22_0";
        case node_t::CASES_22_1: return "CASES_22_1";
        case node_t::TEXT_23_0: return "TEXT_23_0";
        case node_t::FUNC_23_1: return "FUNC_23_1";
        case node_t::TEXT_24_0: return "TEXT_24_0";
        case node_t::FUNC_24_1: return "FUNC_24_1";
        case node_t::TEXT_25_0: return "TEXT_25_0";
        case node_t::FUNC_25_1: return "FUNC_25_1";
        case node_t::TEXT_26_0: return "TEXT_26_0";
        case node_t::FUNC_26_1: return "FUNC_26_1";
        case node_t::TEXT_27_0: return "TEXT_27_0";
        case node_t::FUNC_27_1: return "FUNC_27_1";
        case node_t::LOOP_29_0: return "LOOP_29_0";
        case node_t::UINT_29_0: return "UINT_29_0";
        case node_t::STRING_29_1: return "STRING_29_1";
        case node_t::NO_STATE: return "NO_STATE";
        default: return "unknown";
    };
}

