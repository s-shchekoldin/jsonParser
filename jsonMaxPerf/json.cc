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
            case node_t::FUNC_3_1: if (!func_3_1(state) || state.node != node_t::FUNC_3_2) break; __attribute__ ((fallthrough));
            case node_t::FUNC_3_2: if (!func_3_2(state) || state.node != node_t::NOTIFY_3_3) break; __attribute__ ((fallthrough));
            case node_t::NOTIFY_3_3: notify_3_3(state); break;
            case node_t::RANGE_4_0: if (!range_4_0(state) || state.node != node_t::FUNC_4_1) break; __attribute__ ((fallthrough));
            case node_t::FUNC_4_1: if (!func_4_1(state) || state.node != node_t::NOTIFY_4_2) break; __attribute__ ((fallthrough));
            case node_t::NOTIFY_4_2: notify_4_2(state); break;
            case node_t::TEXT_5_0: if (!text_5_0(state) || state.node != node_t::STR_VIEW_5_1) break; __attribute__ ((fallthrough));
            case node_t::STR_VIEW_5_1: if (!str_view_5_1(state) || state.node != node_t::TEXT_5_2) break; __attribute__ ((fallthrough));
            case node_t::TEXT_5_2: if (!text_5_2(state) || state.node != node_t::RANGE_5_3) break; __attribute__ ((fallthrough));
            case node_t::RANGE_5_3: if (!range_5_3(state) || state.node != node_t::CASES_5_4) break; __attribute__ ((fallthrough));
            case node_t::CASES_5_4: cases_5_4(state); break;
            case node_t::TEXT_6_0: if (!text_6_0(state) || state.node != node_t::RANGE_6_1) break; __attribute__ ((fallthrough));
            case node_t::RANGE_6_1: if (!range_6_1(state) || state.node != node_t::CASES_6_2) break; __attribute__ ((fallthrough));
            case node_t::CASES_6_2: cases_6_2(state); break;
            case node_t::TEXT_7_0: if (!text_7_0(state) || state.node != node_t::STR_VIEW_7_1) break; __attribute__ ((fallthrough));
            case node_t::STR_VIEW_7_1: if (!str_view_7_1(state) || state.node != node_t::TEXT_7_2) break; __attribute__ ((fallthrough));
            case node_t::TEXT_7_2: if (!text_7_2(state) || state.node != node_t::NOTIFY_7_3) break; __attribute__ ((fallthrough));
            case node_t::NOTIFY_7_3: notify_7_3(state); break;
            case node_t::STR_VIEW_8_0: if (!str_view_8_0(state) || state.node != node_t::NOTIFY_8_1) break; __attribute__ ((fallthrough));
            case node_t::NOTIFY_8_1: notify_8_1(state); break;
            case node_t::RANGE_9_0: if (!range_9_0(state) || state.node != node_t::FUNC_9_1) break; __attribute__ ((fallthrough));
            case node_t::FUNC_9_1: if (!func_9_1(state) || state.node != node_t::NOTIFY_9_2) break; __attribute__ ((fallthrough));
            case node_t::NOTIFY_9_2: notify_9_2(state); break;
            case node_t::TEXT_10_0: if (!text_10_0(state) || state.node != node_t::FUNC_10_1) break; __attribute__ ((fallthrough));
            case node_t::FUNC_10_1: if (!func_10_1(state) || state.node != node_t::NOTIFY_10_2) break; __attribute__ ((fallthrough));
            case node_t::NOTIFY_10_2: notify_10_2(state); break;
            case node_t::RANGE_11_0: if (!range_11_0(state) || state.node != node_t::FUNC_11_1) break; __attribute__ ((fallthrough));
            case node_t::FUNC_11_1: if (!func_11_1(state) || state.node != node_t::NOTIFY_11_2) break; __attribute__ ((fallthrough));
            case node_t::NOTIFY_11_2: if (!notify_11_2(state) || state.node != node_t::FUNC_11_3) break; __attribute__ ((fallthrough));
            case node_t::FUNC_11_3: if (!func_11_3(state) || state.node != node_t::NOTIFY_11_4) break; __attribute__ ((fallthrough));
            case node_t::NOTIFY_11_4: notify_11_4(state); break;
            case node_t::STR_VIEW_12_0: if (!str_view_12_0(state) || state.node != node_t::NOTIFY_12_1) break; __attribute__ ((fallthrough));
            case node_t::NOTIFY_12_1: notify_12_1(state); break;
            case node_t::LOOP_14_0: loop_14_0(state); break;
            case node_t::UINT_14_0: uint_14_0(state); break;
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
    if (str_view_12_0(state)) // case_5
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
        false,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false,  true,  true,  true, 
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
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0x9-0xa][0xd][0x20][0x2c]
    const char * beginData = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (exitSym[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (exitSym[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (exitSym[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (exitSym[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (exitSym[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (exitSym[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (exitSym[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (exitSym[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (exitSym[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (exitSym[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (exitSym[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (exitSym[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (exitSym[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (exitSym[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (exitSym[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])]) [[unlikely]]
        {
            state.data++;
            continue;
        }
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
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
        {
            state.consumed += unsigned(state.data - beginData);
            state.node = (state.consumed >= 1) ? node_t::FUNC_3_1 : node_t::NO_STATE;
            bool ret = (state.node == node_t::FUNC_3_1);
            state.consumed = 0;
            return ret;
        }
        state.data++;
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
    state.node = ret ? node_t::FUNC_3_2 : node_t::NO_STATE;
    return ret;
}

inline bool json::_func_3_2()
{
     key = std::string_view(); 
    return true;
}
inline bool json::func_3_2(state_t & state)
{
    bool ret = _func_3_2();
    state.node = ret ? node_t::NOTIFY_3_3 : node_t::NO_STATE;
    return ret;
}

inline bool json::notify_3_3(state_t & state)
{
    pushDepth();
    state.node = node_t::LOOP_1_1;
    return true;
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
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
        {
            state.consumed += unsigned(state.data - beginData);
            state.node = (state.consumed >= 1) ? node_t::FUNC_4_1 : node_t::NO_STATE;
            bool ret = (state.node == node_t::FUNC_4_1);
            state.consumed = 0;
            return ret;
        }
        state.data++;
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
    if(state.data < state.end)
    {
        if (uint8_t(0x22) != uint8_t(state.data[0]))
        {
            state.node = node_t::NO_STATE;
            return false;
        } else {
            state.data++;
            state.node = node_t::STR_VIEW_5_1;
            return true;
        }
    }
    state.node = node_t::TEXT_5_0;
    return true;
}

inline void json::_str_view_5_1(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        jsonResult::key = std::string_view();
    jsonResult::key = std::string_view(data, len);
}

inline bool json::str_view_5_1(state_t & state)
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
    const char * beginData = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (exitSym[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (exitSym[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (exitSym[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (exitSym[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (exitSym[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (exitSym[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (exitSym[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (exitSym[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (exitSym[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (exitSym[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (exitSym[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (exitSym[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (exitSym[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (exitSym[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (exitSym[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])]) [[unlikely]]
        {
            state.data++;
            continue;
        }
        _str_view_5_1(beginData, unsigned(state.data - beginData), state.consumed);
        state.consumed += unsigned(state.data - beginData);
        state.node = (state.consumed >= 1) ? node_t::TEXT_5_2 : node_t::NO_STATE;
        bool ret = (state.node == node_t::TEXT_5_2);
        state.consumed = 0;
        return ret;
    }
    if (beginData < state.data)
        _str_view_5_1(beginData, unsigned(state.data - beginData), state.consumed);
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::STR_VIEW_5_1;
    return true;
}

inline bool json::text_5_2(state_t & state)
{
    if(state.data < state.end)
    {
        if (uint8_t(0x22) != uint8_t(state.data[0]))
        {
            state.node = node_t::NO_STATE;
            return false;
        } else {
            state.data++;
            state.node = node_t::RANGE_5_3;
            return true;
        }
    }
    state.node = node_t::TEXT_5_2;
    return true;
}

inline bool json::range_5_3(state_t & state)
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
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (exitSym[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (exitSym[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (exitSym[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (exitSym[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (exitSym[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (exitSym[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (exitSym[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (exitSym[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (exitSym[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (exitSym[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (exitSym[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (exitSym[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (exitSym[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (exitSym[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (exitSym[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])]) [[unlikely]]
        {
            state.data++;
            continue;
        }
        state.node = node_t::CASES_5_4;
        bool ret = (state.node == node_t::CASES_5_4);
        state.consumed = 0;
        return ret;
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_5_3;
    return true;
}

inline bool json::cases_5_4(state_t & state)
{
    if (state.data == state.end)
        return true;
    state_t startState = state;
    if (text_6_0(state)) // case_1
        return true;
    state = startState;
    if (text_10_0(state)) // case_2
        return true;
    state = startState;
    if (range_11_0(state)) // case_3
        return true;
    state = startState;
    state.node = node_t::NO_STATE;
    return true;
}

inline bool json::text_6_0(state_t & state)
{
    if(state.data < state.end)
    {
        if (uint8_t(0x3A) != uint8_t(state.data[0]))
        {
            state.node = node_t::NO_STATE;
            return false;
        } else {
            state.data++;
            state.node = node_t::RANGE_6_1;
            return true;
        }
    }
    state.node = node_t::TEXT_6_0;
    return true;
}

inline bool json::range_6_1(state_t & state)
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
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (exitSym[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (exitSym[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (exitSym[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (exitSym[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (exitSym[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (exitSym[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (exitSym[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (exitSym[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (exitSym[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (exitSym[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (exitSym[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (exitSym[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (exitSym[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (exitSym[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (exitSym[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])]) [[unlikely]]
        {
            state.data++;
            continue;
        }
        state.node = node_t::CASES_6_2;
        bool ret = (state.node == node_t::CASES_6_2);
        state.consumed = 0;
        return ret;
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_6_1;
    return true;
}

inline bool json::cases_6_2(state_t & state)
{
    if (state.data == state.end)
        return true;
    state_t startState = state;
    if (text_7_0(state)) // case_1
        return true;
    state = startState;
    if (str_view_8_0(state)) // case_2
        return true;
    state = startState;
    if (range_9_0(state)) // case_3
        return true;
    state = startState;
    state.node = node_t::NO_STATE;
    return true;
}

inline bool json::text_7_0(state_t & state)
{
    if(state.data < state.end)
    {
        if (uint8_t(0x22) != uint8_t(state.data[0]))
        {
            state.node = node_t::NO_STATE;
            return false;
        } else {
            state.data++;
            state.node = node_t::STR_VIEW_7_1;
            return true;
        }
    }
    state.node = node_t::TEXT_7_0;
    return true;
}

inline void json::_str_view_7_1(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        jsonResult::value = std::string_view();
    jsonResult::value = std::string_view(data, len);
}

inline bool json::str_view_7_1(state_t & state)
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
    const char * beginData = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (exitSym[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (exitSym[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (exitSym[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (exitSym[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (exitSym[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (exitSym[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (exitSym[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (exitSym[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (exitSym[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (exitSym[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (exitSym[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (exitSym[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (exitSym[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (exitSym[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (exitSym[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])]) [[unlikely]]
        {
            state.data++;
            continue;
        }
        _str_view_7_1(beginData, unsigned(state.data - beginData), state.consumed);
        state.node = node_t::TEXT_7_2;
        bool ret = (state.node == node_t::TEXT_7_2);
        state.consumed = 0;
        return ret;
    }
    if (beginData < state.data)
        _str_view_7_1(beginData, unsigned(state.data - beginData), state.consumed);
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::STR_VIEW_7_1;
    return true;
}

inline bool json::text_7_2(state_t & state)
{
    if(state.data < state.end)
    {
        if (uint8_t(0x22) != uint8_t(state.data[0]))
        {
            state.node = node_t::NO_STATE;
            return false;
        } else {
            state.data++;
            state.node = node_t::NOTIFY_7_3;
            return true;
        }
    }
    state.node = node_t::TEXT_7_2;
    return true;
}

inline bool json::notify_7_3(state_t & state)
{
    gotKV();
    state.node = node_t::LOOP_1_1;
    return true;
}

inline void json::_str_view_8_0(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        jsonResult::value = std::string_view();
    jsonResult::value = std::string_view(data, len);
}

inline bool json::str_view_8_0(state_t & state)
{
    const static bool exitSym[256] = {
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false, false,  true, 
        false, false, false, false, false, false, false, false, false, false,  true,  true,  true,  true,  true,  true, 
         true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false,  true,  true,  true,  true,  true, 
         true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0x2d-0x2e][0-9][A-Z][a-z]
    const char * beginData = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (exitSym[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (exitSym[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (exitSym[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (exitSym[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (exitSym[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (exitSym[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (exitSym[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (exitSym[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (exitSym[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (exitSym[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (exitSym[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (exitSym[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (exitSym[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (exitSym[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (exitSym[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])]) [[unlikely]]
        {
            state.data++;
            continue;
        }
        _str_view_8_0(beginData, unsigned(state.data - beginData), state.consumed);
        state.consumed += unsigned(state.data - beginData);
        state.node = (state.consumed >= 1) ? node_t::NOTIFY_8_1 : node_t::NO_STATE;
        bool ret = (state.node == node_t::NOTIFY_8_1);
        state.consumed = 0;
        return ret;
    }
    if (beginData < state.data)
        _str_view_8_0(beginData, unsigned(state.data - beginData), state.consumed);
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::STR_VIEW_8_0;
    return true;
}

inline bool json::notify_8_1(state_t & state)
{
    gotKV();
    state.node = node_t::LOOP_1_1;
    return true;
}

inline bool json::range_9_0(state_t & state)
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
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
        {
            state.consumed += unsigned(state.data - beginData);
            state.node = (state.consumed >= 1) ? node_t::FUNC_9_1 : node_t::NO_STATE;
            bool ret = (state.node == node_t::FUNC_9_1);
            state.consumed = 0;
            return ret;
        }
        state.data++;
        state.node = node_t::FUNC_9_1;
        return true;
    }
    state.node = node_t::RANGE_9_0;
    return true;
}

inline bool json::_func_9_1()
{
     depth++; 
    return true;
}
inline bool json::func_9_1(state_t & state)
{
    bool ret = _func_9_1();
    state.node = ret ? node_t::NOTIFY_9_2 : node_t::NO_STATE;
    return ret;
}

inline bool json::notify_9_2(state_t & state)
{
    pushDepth();
    state.node = node_t::LOOP_1_1;
    return true;
}

inline bool json::text_10_0(state_t & state)
{
    if(state.data < state.end)
    {
        if (uint8_t(0x2C) != uint8_t(state.data[0]))
        {
            state.node = node_t::NO_STATE;
            return false;
        } else {
            state.data++;
            state.node = node_t::FUNC_10_1;
            return true;
        }
    }
    state.node = node_t::TEXT_10_0;
    return true;
}

inline bool json::_func_10_1()
{
     value = std::move(key); 
    return true;
}
inline bool json::func_10_1(state_t & state)
{
    bool ret = _func_10_1();
    state.node = ret ? node_t::NOTIFY_10_2 : node_t::NO_STATE;
    return ret;
}

inline bool json::notify_10_2(state_t & state)
{
    gotVal();
    state.node = node_t::LOOP_1_1;
    return true;
}

inline bool json::range_11_0(state_t & state)
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
    const char * beginData = state.data;
    while(state.data < state.end)
    {
        if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
        {
            state.consumed += unsigned(state.data - beginData);
            state.node = (state.consumed >= 1) ? node_t::FUNC_11_1 : node_t::NO_STATE;
            bool ret = (state.node == node_t::FUNC_11_1);
            state.consumed = 0;
            return ret;
        }
        state.data++;
        state.node = node_t::FUNC_11_1;
        return true;
    }
    state.node = node_t::RANGE_11_0;
    return true;
}

inline bool json::_func_11_1()
{
     value = std::move(key); 
    return true;
}
inline bool json::func_11_1(state_t & state)
{
    bool ret = _func_11_1();
    state.node = ret ? node_t::NOTIFY_11_2 : node_t::NO_STATE;
    return ret;
}

inline bool json::notify_11_2(state_t & state)
{
    gotVal();
    state.node = node_t::FUNC_11_3;
    return true;
}

inline bool json::_func_11_3()
{
     depth--; 
    return true;
}
inline bool json::func_11_3(state_t & state)
{
    bool ret = _func_11_3();
    state.node = ret ? node_t::NOTIFY_11_4 : node_t::NO_STATE;
    return ret;
}

inline bool json::notify_11_4(state_t & state)
{
    popDepth();
    state.node = node_t::LOOP_1_1;
    return true;
}

inline void json::_str_view_12_0(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        jsonResult::value = std::string_view();
    jsonResult::value = std::string_view(data, len);
}

inline bool json::str_view_12_0(state_t & state)
{
    const static bool exitSym[256] = {
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, false, false,  true, 
        false, false, false, false, false, false, false, false, false, false,  true,  true,  true,  true,  true,  true, 
         true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false,  true,  true,  true,  true, false, 
         true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
        false, false, false, false, false, false, false, false, false, false, false,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true, 
         true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // [0x2d-0x2e][0-9][A-Z][_][a-z]
    const char * beginData = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (exitSym[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (exitSym[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (exitSym[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (exitSym[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (exitSym[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (exitSym[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (exitSym[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (exitSym[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (exitSym[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (exitSym[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (exitSym[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (exitSym[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (exitSym[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (exitSym[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (exitSym[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])]) [[unlikely]]
        {
            state.data++;
            continue;
        }
        _str_view_12_0(beginData, unsigned(state.data - beginData), state.consumed);
        state.consumed += unsigned(state.data - beginData);
        state.node = (state.consumed >= 1) ? node_t::NOTIFY_12_1 : node_t::NO_STATE;
        bool ret = (state.node == node_t::NOTIFY_12_1);
        state.consumed = 0;
        return ret;
    }
    if (beginData < state.data)
        _str_view_12_0(beginData, unsigned(state.data - beginData), state.consumed);
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::STR_VIEW_12_0;
    return true;
}

inline bool json::notify_12_1(state_t & state)
{
    gotVal();
    state.node = node_t::LOOP_1_1;
    return true;
}

inline bool json::loop_14_0(state_t & state)
{
    return uint_14_0(state);
}

inline void json::_uint_14_0(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        jsonResult::depth = 0;
    for(const char * end = &data[len]; data < end; data++)
        jsonResult::depth = jsonResult::depth*10 + *data - '0';
}

inline bool json::uint_14_0(state_t & state)
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
    const char * beginData = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[16] <= state.end)
        {
            if (exitSym[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (exitSym[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (exitSym[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (exitSym[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (exitSym[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (exitSym[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (exitSym[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (exitSym[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else if (exitSym[uint8_t(state.data[8])]) [[unlikely]]
                state.data += 8;
            else if (exitSym[uint8_t(state.data[9])]) [[unlikely]]
                state.data += 9;
            else if (exitSym[uint8_t(state.data[10])]) [[unlikely]]
                state.data += 10;
            else if (exitSym[uint8_t(state.data[11])]) [[unlikely]]
                state.data += 11;
            else if (exitSym[uint8_t(state.data[12])]) [[unlikely]]
                state.data += 12;
            else if (exitSym[uint8_t(state.data[13])]) [[unlikely]]
                state.data += 13;
            else if (exitSym[uint8_t(state.data[14])]) [[unlikely]]
                state.data += 14;
            else if (exitSym[uint8_t(state.data[15])]) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
        else if (!exitSym[uint8_t(state.data[0])]) [[unlikely]]
        {
            state.data++;
            continue;
        }
        _uint_14_0(beginData, unsigned(state.data - beginData), state.consumed);
        state.consumed += unsigned(state.data - beginData);
        state.node = (state.consumed >= 1) ? node_t::LOOP_14_0 : node_t::NO_STATE;
        bool ret = (state.node == node_t::LOOP_14_0);
        state.consumed = 0;
        return ret;
    }
    if (beginData < state.data)
        _uint_14_0(beginData, unsigned(state.data - beginData), state.consumed);
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::UINT_14_0;
    return true;
}

void json::reset()
{
    jsonResult::depth = 0;
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
        case node_t::FUNC_3_2: return "FUNC_3_2";
        case node_t::NOTIFY_3_3: return "NOTIFY_3_3";
        case node_t::RANGE_4_0: return "RANGE_4_0";
        case node_t::FUNC_4_1: return "FUNC_4_1";
        case node_t::NOTIFY_4_2: return "NOTIFY_4_2";
        case node_t::TEXT_5_0: return "TEXT_5_0";
        case node_t::STR_VIEW_5_1: return "STR_VIEW_5_1";
        case node_t::TEXT_5_2: return "TEXT_5_2";
        case node_t::RANGE_5_3: return "RANGE_5_3";
        case node_t::CASES_5_4: return "CASES_5_4";
        case node_t::TEXT_6_0: return "TEXT_6_0";
        case node_t::RANGE_6_1: return "RANGE_6_1";
        case node_t::CASES_6_2: return "CASES_6_2";
        case node_t::TEXT_7_0: return "TEXT_7_0";
        case node_t::STR_VIEW_7_1: return "STR_VIEW_7_1";
        case node_t::TEXT_7_2: return "TEXT_7_2";
        case node_t::NOTIFY_7_3: return "NOTIFY_7_3";
        case node_t::STR_VIEW_8_0: return "STR_VIEW_8_0";
        case node_t::NOTIFY_8_1: return "NOTIFY_8_1";
        case node_t::RANGE_9_0: return "RANGE_9_0";
        case node_t::FUNC_9_1: return "FUNC_9_1";
        case node_t::NOTIFY_9_2: return "NOTIFY_9_2";
        case node_t::TEXT_10_0: return "TEXT_10_0";
        case node_t::FUNC_10_1: return "FUNC_10_1";
        case node_t::NOTIFY_10_2: return "NOTIFY_10_2";
        case node_t::RANGE_11_0: return "RANGE_11_0";
        case node_t::FUNC_11_1: return "FUNC_11_1";
        case node_t::NOTIFY_11_2: return "NOTIFY_11_2";
        case node_t::FUNC_11_3: return "FUNC_11_3";
        case node_t::NOTIFY_11_4: return "NOTIFY_11_4";
        case node_t::STR_VIEW_12_0: return "STR_VIEW_12_0";
        case node_t::NOTIFY_12_1: return "NOTIFY_12_1";
        case node_t::LOOP_14_0: return "LOOP_14_0";
        case node_t::UINT_14_0: return "UINT_14_0";
        case node_t::NO_STATE: return "NO_STATE";
        default: return "unknown";
    };
}

