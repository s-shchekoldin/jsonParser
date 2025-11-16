// ==============================================================
// Date: 2025-11-16 07:23:44 GMT
// Generated using vProto(2025.11.16)        https://www.cgen.dev
// Author: Sergey V. Shchekoldin     Email: shchekoldin@gmail.com
// autoSSE: 1 cpp98: 0 (SSE4.2: 0 AVX2: 1 SSE2: 1)
// ==============================================================

// To enable AVX2 use: -mavx2
// To enable SSE2 use: -msse2
// Or: -march=native (may break compatibility)
#include "json.h"
#if defined(__SSE4_2__) || defined(__AVX2__)
#include <immintrin.h>
#endif
#if defined(__SSE2__)
#include <emmintrin.h>
#endif

#if defined(_MSC_VER)
#include <intrin.h>
inline unsigned __ctz32(uint32_t x) { return _tzcnt_u32(x); }
#else
inline unsigned __ctz32(uint32_t x) { return __builtin_ctz(x); }
#endif

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
            case node_t::RANGE_1_0: range_1_0(state); break;
            case node_t::RANGE_2_0: if (!range_2_0(state) || state.node != node_t::FUNC_2_1) break; [[fallthrough]];
            case node_t::FUNC_2_1: if (!func_2_1(state) || state.node != node_t::FUNC_2_2) break; [[fallthrough]];
            case node_t::FUNC_2_2: if (!func_2_2(state) || state.node != node_t::NOTIFY_2_3) break; [[fallthrough]];
            case node_t::NOTIFY_2_3: notify_2_3(state); break;
            case node_t::RANGE_3_0: if (!range_3_0(state) || state.node != node_t::FUNC_3_1) break; [[fallthrough]];
            case node_t::FUNC_3_1: if (!func_3_1(state) || state.node != node_t::NOTIFY_3_2) break; [[fallthrough]];
            case node_t::NOTIFY_3_2: notify_3_2(state); break;
            case node_t::TEXT_4_0: if (!text_4_0(state) || state.node != node_t::STRING_4_1) break; [[fallthrough]];
            case node_t::STRING_4_1: if (!string_4_1(state) || state.node != node_t::TEXT_4_2) break; [[fallthrough]];
            case node_t::TEXT_4_2: if (!text_4_2(state) || state.node != node_t::RANGE_4_3) break; [[fallthrough]];
            case node_t::RANGE_4_3: if (!range_4_3(state) || state.node != node_t::CASES_4_4) break; [[fallthrough]];
            case node_t::CASES_4_4: cases_4_4(state); break;
            case node_t::TEXT_5_0: if (!text_5_0(state) || state.node != node_t::RANGE_5_1) break; [[fallthrough]];
            case node_t::RANGE_5_1: if (!range_5_1(state) || state.node != node_t::CASES_5_2) break; [[fallthrough]];
            case node_t::CASES_5_2: cases_5_2(state); break;
            case node_t::TEXT_6_0: if (!text_6_0(state) || state.node != node_t::STRING_6_1) break; [[fallthrough]];
            case node_t::STRING_6_1: if (!string_6_1(state) || state.node != node_t::TEXT_6_2) break; [[fallthrough]];
            case node_t::TEXT_6_2: if (!text_6_2(state) || state.node != node_t::NOTIFY_6_3) break; [[fallthrough]];
            case node_t::NOTIFY_6_3: notify_6_3(state); break;
            case node_t::STRING_7_0: if (!string_7_0(state) || state.node != node_t::NOTIFY_7_1) break; [[fallthrough]];
            case node_t::NOTIFY_7_1: notify_7_1(state); break;
            case node_t::RANGE_8_0: if (!range_8_0(state) || state.node != node_t::FUNC_8_1) break; [[fallthrough]];
            case node_t::FUNC_8_1: if (!func_8_1(state) || state.node != node_t::NOTIFY_8_2) break; [[fallthrough]];
            case node_t::NOTIFY_8_2: notify_8_2(state); break;
            case node_t::TEXT_9_0: if (!text_9_0(state) || state.node != node_t::FUNC_9_1) break; [[fallthrough]];
            case node_t::FUNC_9_1: if (!func_9_1(state) || state.node != node_t::NOTIFY_9_2) break; [[fallthrough]];
            case node_t::NOTIFY_9_2: notify_9_2(state); break;
            case node_t::RANGE_10_0: if (!range_10_0(state) || state.node != node_t::FUNC_10_1) break; [[fallthrough]];
            case node_t::FUNC_10_1: if (!func_10_1(state) || state.node != node_t::NOTIFY_10_2) break; [[fallthrough]];
            case node_t::NOTIFY_10_2: if (!notify_10_2(state) || state.node != node_t::FUNC_10_3) break; [[fallthrough]];
            case node_t::FUNC_10_3: if (!func_10_3(state) || state.node != node_t::NOTIFY_10_4) break; [[fallthrough]];
            case node_t::NOTIFY_10_4: notify_10_4(state); break;
            case node_t::STRING_11_0: if (!string_11_0(state) || state.node != node_t::NOTIFY_11_1) break; [[fallthrough]];
            case node_t::NOTIFY_11_1: notify_11_1(state); break;
            case node_t::LOOP_13_0: loop_13_0(state); break;
            case node_t::UINT_13_0: uint_13_0(state); break;
            case node_t::NO_STATE:
            default: return;
        }; // switch
        if (d == state.data && n == state.node) [[unlikely]]
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
    if (state.data == state.end)
        return true;
    if (range_1_0(state)) // case_1
        return true;
    if (range_2_0(state)) // case_2
        return true;
    if (range_3_0(state)) // case_3
        return true;
    if (text_4_0(state)) // case_4
        return true;
    if (string_11_0(state)) // case_5
        return true;
    state.node = node_t::NO_STATE;
    return true;
}

inline bool json::range_1_0(state_t & state) const
{
    const static std::array<bool, 256> exitSym = {
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
        else if (!(exitSym[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        uint64_t totalConsumed = state.consumed + unsigned(state.data - beginData);
        state.consumed = 0;
        if (totalConsumed >= 1)
        {
            state.node = node_t::LOOP_1_0;
            return true;
        } else {
            state.node = node_t::NO_STATE;
            return false;
        }
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_1_0;
    return true;
}

inline bool json::range_2_0(state_t & state) const
{
    const static std::array<bool, 256> exitSym = {
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
            state.node = (state.consumed >= 1) ? node_t::FUNC_2_1 : node_t::NO_STATE;
            bool ret = (state.node == node_t::FUNC_2_1);
            state.consumed = 0;
            return ret;
        }
        state.data++;
        state.node = node_t::FUNC_2_1;
        return true;
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_2_0;
    return true;
}

inline bool json::_func_2_1()
{
     depth++; 
    return true;
}
inline bool json::func_2_1(state_t & state)
{
    if (_func_2_1())
    {
        state.node = node_t::FUNC_2_2;
        return true;
    }
    state.node = node_t::NO_STATE;
    return false;
}

inline bool json::_func_2_2()
{
     key.clear(); 
    return true;
}
inline bool json::func_2_2(state_t & state)
{
    if (_func_2_2())
    {
        state.node = node_t::NOTIFY_2_3;
        return true;
    }
    state.node = node_t::NO_STATE;
    return false;
}

inline bool json::notify_2_3(state_t & state)
{
    pushDepth();
    state.node = node_t::LOOP_1_0;
    return true;
}

inline bool json::range_3_0(state_t & state) const
{
    const static std::array<bool, 256> exitSym = {
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
            state.node = (state.consumed >= 1) ? node_t::FUNC_3_1 : node_t::NO_STATE;
            bool ret = (state.node == node_t::FUNC_3_1);
            state.consumed = 0;
            return ret;
        }
        state.data++;
        state.node = node_t::FUNC_3_1;
        return true;
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_3_0;
    return true;
}

inline bool json::_func_3_1()
{
     depth--; 
    return true;
}
inline bool json::func_3_1(state_t & state)
{
    if (_func_3_1())
    {
        state.node = node_t::NOTIFY_3_2;
        return true;
    }
    state.node = node_t::NO_STATE;
    return false;
}

inline bool json::notify_3_2(state_t & state)
{
    popDepth();
    state.node = node_t::LOOP_1_0;
    return true;
}

inline bool json::text_4_0(state_t & state) const
{
    if(state.data < state.end)
    {
        if (uint8_t(0x22) != uint8_t(state.data[0]))
        {
            state.node = node_t::NO_STATE;
            return false;
        } else {
            state.data++;
            state.node = node_t::STRING_4_1;
            return true;
        }
    }
    state.node = node_t::TEXT_4_0;
    return true;
}

void json::_string_4_1(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        jsonResult::key.clear();
    if ((jsonResult::key.length() + len) > 256)
        len = 256 - jsonResult::key.length();
    jsonResult::key.append(data, len);
}

inline bool json::string_4_1(state_t & state)
{
    const char * beginData = state.data;
    while(state.data < state.end) [[likely]]
    {
#if defined(__AVX2__)
        if(&state.data[32] <= state.end)
        {
            const __m256i d = _mm256_lddqu_si256((const __m256i *)state.data);
            __m256i m = _mm256_cmpeq_epi8(_mm256_set1_epi8(0x22), d);
            uint32_t r = _mm256_movemask_epi8(m);
            if (r)
                state.data += __ctz32(r);
            else
            {
                state.data += 32;
                continue;
            }
        }
#elif defined(__SSE2__)
        if(&state.data[16] <= state.end)
        {
            const __m128i d = _mm_loadu_si128((const __m128i *)state.data);
            __m128i m = _mm_cmpeq_epi8(_mm_set1_epi8(0x22), d);
            uint16_t r = _mm_movemask_epi8(m);
            if (r)
                state.data += __ctz32(r);
            else
            {
                state.data += 16;
                continue;
            }
        }
#else
        if(&state.data[16] <= state.end)
        {
            if (uint8_t(state.data[0]) == uint8_t(0x22)) [[unlikely]]
                state.data += 0;
            else if (uint8_t(state.data[1]) == uint8_t(0x22)) [[unlikely]]
                state.data += 1;
            else if (uint8_t(state.data[2]) == uint8_t(0x22)) [[unlikely]]
                state.data += 2;
            else if (uint8_t(state.data[3]) == uint8_t(0x22)) [[unlikely]]
                state.data += 3;
            else if (uint8_t(state.data[4]) == uint8_t(0x22)) [[unlikely]]
                state.data += 4;
            else if (uint8_t(state.data[5]) == uint8_t(0x22)) [[unlikely]]
                state.data += 5;
            else if (uint8_t(state.data[6]) == uint8_t(0x22)) [[unlikely]]
                state.data += 6;
            else if (uint8_t(state.data[7]) == uint8_t(0x22)) [[unlikely]]
                state.data += 7;
            else if (uint8_t(state.data[8]) == uint8_t(0x22)) [[unlikely]]
                state.data += 8;
            else if (uint8_t(state.data[9]) == uint8_t(0x22)) [[unlikely]]
                state.data += 9;
            else if (uint8_t(state.data[10]) == uint8_t(0x22)) [[unlikely]]
                state.data += 10;
            else if (uint8_t(state.data[11]) == uint8_t(0x22)) [[unlikely]]
                state.data += 11;
            else if (uint8_t(state.data[12]) == uint8_t(0x22)) [[unlikely]]
                state.data += 12;
            else if (uint8_t(state.data[13]) == uint8_t(0x22)) [[unlikely]]
                state.data += 13;
            else if (uint8_t(state.data[14]) == uint8_t(0x22)) [[unlikely]]
                state.data += 14;
            else if (uint8_t(state.data[15]) == uint8_t(0x22)) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
#endif
        else if (!(uint8_t(state.data[0]) == uint8_t(0x22))) [[unlikely]]
        {
            state.data++;
            continue;
        }
        _string_4_1(beginData, unsigned(state.data - beginData), state.consumed);
        uint64_t totalConsumed = state.consumed + unsigned(state.data - beginData);
        state.consumed = 0;
        if (totalConsumed >= 1)
        {
            state.node = node_t::TEXT_4_2;
            return true;
        } else {
            state.node = node_t::NO_STATE;
            return false;
        }
    }
    if (beginData < state.data)
        _string_4_1(beginData, unsigned(state.data - beginData), state.consumed);
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::STRING_4_1;
    return true;
}

inline bool json::text_4_2(state_t & state) const
{
    if(state.data < state.end)
    {
        if (uint8_t(0x22) != uint8_t(state.data[0]))
        {
            state.node = node_t::NO_STATE;
            return false;
        } else {
            state.data++;
            state.node = node_t::RANGE_4_3;
            return true;
        }
    }
    state.node = node_t::TEXT_4_2;
    return true;
}

inline bool json::range_4_3(state_t & state) const
{
    const static std::array<bool, 256> exitSym = {
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
        else if (!(exitSym[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        state.consumed = 0;
        state.node = node_t::CASES_4_4;
        return true;
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_4_3;
    return true;
}

inline bool json::cases_4_4(state_t & state) const
{
    if (state.data == state.end)
        return true;
    if (text_5_0(state)) // case_1
        return true;
    if (text_9_0(state)) // case_2
        return true;
    if (range_10_0(state)) // case_3
        return true;
    state.node = node_t::NO_STATE;
    return true;
}

inline bool json::text_5_0(state_t & state) const
{
    if(state.data < state.end)
    {
        if (uint8_t(0x3A) != uint8_t(state.data[0]))
        {
            state.node = node_t::NO_STATE;
            return false;
        } else {
            state.data++;
            state.node = node_t::RANGE_5_1;
            return true;
        }
    }
    state.node = node_t::TEXT_5_0;
    return true;
}

inline bool json::range_5_1(state_t & state) const
{
    const static std::array<bool, 256> exitSym = {
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
        else if (!(exitSym[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        state.consumed = 0;
        state.node = node_t::CASES_5_2;
        return true;
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_5_1;
    return true;
}

inline bool json::cases_5_2(state_t & state)
{
    if (state.data == state.end)
        return true;
    if (text_6_0(state)) // case_1
        return true;
    if (string_7_0(state)) // case_2
        return true;
    if (range_8_0(state)) // case_3
        return true;
    state.node = node_t::NO_STATE;
    return true;
}

inline bool json::text_6_0(state_t & state) const
{
    if(state.data < state.end)
    {
        if (uint8_t(0x22) != uint8_t(state.data[0]))
        {
            state.node = node_t::NO_STATE;
            return false;
        } else {
            state.data++;
            state.node = node_t::STRING_6_1;
            return true;
        }
    }
    state.node = node_t::TEXT_6_0;
    return true;
}

void json::_string_6_1(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        jsonResult::value.clear();
    if ((jsonResult::value.length() + len) > 256)
        len = 256 - jsonResult::value.length();
    jsonResult::value.append(data, len);
}

inline bool json::string_6_1(state_t & state)
{
    const char * beginData = state.data;
    while(state.data < state.end) [[likely]]
    {
#if defined(__AVX2__)
        if(&state.data[32] <= state.end)
        {
            const __m256i d = _mm256_lddqu_si256((const __m256i *)state.data);
            __m256i m = _mm256_cmpeq_epi8(_mm256_set1_epi8(0x22), d);
            uint32_t r = _mm256_movemask_epi8(m);
            if (r)
                state.data += __ctz32(r);
            else
            {
                state.data += 32;
                continue;
            }
        }
#elif defined(__SSE2__)
        if(&state.data[16] <= state.end)
        {
            const __m128i d = _mm_loadu_si128((const __m128i *)state.data);
            __m128i m = _mm_cmpeq_epi8(_mm_set1_epi8(0x22), d);
            uint16_t r = _mm_movemask_epi8(m);
            if (r)
                state.data += __ctz32(r);
            else
            {
                state.data += 16;
                continue;
            }
        }
#else
        if(&state.data[16] <= state.end)
        {
            if (uint8_t(state.data[0]) == uint8_t(0x22)) [[unlikely]]
                state.data += 0;
            else if (uint8_t(state.data[1]) == uint8_t(0x22)) [[unlikely]]
                state.data += 1;
            else if (uint8_t(state.data[2]) == uint8_t(0x22)) [[unlikely]]
                state.data += 2;
            else if (uint8_t(state.data[3]) == uint8_t(0x22)) [[unlikely]]
                state.data += 3;
            else if (uint8_t(state.data[4]) == uint8_t(0x22)) [[unlikely]]
                state.data += 4;
            else if (uint8_t(state.data[5]) == uint8_t(0x22)) [[unlikely]]
                state.data += 5;
            else if (uint8_t(state.data[6]) == uint8_t(0x22)) [[unlikely]]
                state.data += 6;
            else if (uint8_t(state.data[7]) == uint8_t(0x22)) [[unlikely]]
                state.data += 7;
            else if (uint8_t(state.data[8]) == uint8_t(0x22)) [[unlikely]]
                state.data += 8;
            else if (uint8_t(state.data[9]) == uint8_t(0x22)) [[unlikely]]
                state.data += 9;
            else if (uint8_t(state.data[10]) == uint8_t(0x22)) [[unlikely]]
                state.data += 10;
            else if (uint8_t(state.data[11]) == uint8_t(0x22)) [[unlikely]]
                state.data += 11;
            else if (uint8_t(state.data[12]) == uint8_t(0x22)) [[unlikely]]
                state.data += 12;
            else if (uint8_t(state.data[13]) == uint8_t(0x22)) [[unlikely]]
                state.data += 13;
            else if (uint8_t(state.data[14]) == uint8_t(0x22)) [[unlikely]]
                state.data += 14;
            else if (uint8_t(state.data[15]) == uint8_t(0x22)) [[unlikely]]
                state.data += 15;
            else
            {
                state.data += 16;
                continue;
            }
        }
#endif
        else if (!(uint8_t(state.data[0]) == uint8_t(0x22))) [[unlikely]]
        {
            state.data++;
            continue;
        }
        _string_6_1(beginData, unsigned(state.data - beginData), state.consumed);
        state.consumed = 0;
        state.node = node_t::TEXT_6_2;
        return true;
    }
    if (beginData < state.data)
        _string_6_1(beginData, unsigned(state.data - beginData), state.consumed);
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::STRING_6_1;
    return true;
}

inline bool json::text_6_2(state_t & state) const
{
    if(state.data < state.end)
    {
        if (uint8_t(0x22) != uint8_t(state.data[0]))
        {
            state.node = node_t::NO_STATE;
            return false;
        } else {
            state.data++;
            state.node = node_t::NOTIFY_6_3;
            return true;
        }
    }
    state.node = node_t::TEXT_6_2;
    return true;
}

inline bool json::notify_6_3(state_t & state)
{
    gotKV();
    state.node = node_t::LOOP_1_0;
    return true;
}

void json::_string_7_0(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        jsonResult::value.clear();
    if ((jsonResult::value.length() + len) > 256)
        len = 256 - jsonResult::value.length();
    jsonResult::value.append(data, len);
}

inline bool json::string_7_0(state_t & state)
{
    const static std::array<bool, 256> exitSym = {
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
        else if (!(exitSym[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        _string_7_0(beginData, unsigned(state.data - beginData), state.consumed);
        uint64_t totalConsumed = state.consumed + unsigned(state.data - beginData);
        state.consumed = 0;
        if (totalConsumed >= 1)
        {
            state.node = node_t::NOTIFY_7_1;
            return true;
        } else {
            state.node = node_t::NO_STATE;
            return false;
        }
    }
    if (beginData < state.data)
        _string_7_0(beginData, unsigned(state.data - beginData), state.consumed);
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::STRING_7_0;
    return true;
}

inline bool json::notify_7_1(state_t & state)
{
    gotKV();
    state.node = node_t::LOOP_1_0;
    return true;
}

inline bool json::range_8_0(state_t & state) const
{
    const static std::array<bool, 256> exitSym = {
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
            state.node = (state.consumed >= 1) ? node_t::FUNC_8_1 : node_t::NO_STATE;
            bool ret = (state.node == node_t::FUNC_8_1);
            state.consumed = 0;
            return ret;
        }
        state.data++;
        state.node = node_t::FUNC_8_1;
        return true;
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_8_0;
    return true;
}

inline bool json::_func_8_1()
{
     depth++; 
    return true;
}
inline bool json::func_8_1(state_t & state)
{
    if (_func_8_1())
    {
        state.node = node_t::NOTIFY_8_2;
        return true;
    }
    state.node = node_t::NO_STATE;
    return false;
}

inline bool json::notify_8_2(state_t & state)
{
    pushDepth();
    state.node = node_t::LOOP_1_0;
    return true;
}

inline bool json::text_9_0(state_t & state) const
{
    if(state.data < state.end)
    {
        if (uint8_t(0x2C) != uint8_t(state.data[0]))
        {
            state.node = node_t::NO_STATE;
            return false;
        } else {
            state.data++;
            state.node = node_t::FUNC_9_1;
            return true;
        }
    }
    state.node = node_t::TEXT_9_0;
    return true;
}

inline bool json::_func_9_1()
{
     value.swap(key); 
    return true;
}
inline bool json::func_9_1(state_t & state)
{
    if (_func_9_1())
    {
        state.node = node_t::NOTIFY_9_2;
        return true;
    }
    state.node = node_t::NO_STATE;
    return false;
}

inline bool json::notify_9_2(state_t & state)
{
    gotVal();
    state.node = node_t::LOOP_1_0;
    return true;
}

inline bool json::range_10_0(state_t & state) const
{
    const static std::array<bool, 256> exitSym = {
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
            state.node = (state.consumed >= 1) ? node_t::FUNC_10_1 : node_t::NO_STATE;
            bool ret = (state.node == node_t::FUNC_10_1);
            state.consumed = 0;
            return ret;
        }
        state.data++;
        state.node = node_t::FUNC_10_1;
        return true;
    }
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::RANGE_10_0;
    return true;
}

inline bool json::_func_10_1()
{
     value.swap(key); 
    return true;
}
inline bool json::func_10_1(state_t & state)
{
    if (_func_10_1())
    {
        state.node = node_t::NOTIFY_10_2;
        return true;
    }
    state.node = node_t::NO_STATE;
    return false;
}

inline bool json::notify_10_2(state_t & state)
{
    gotVal();
    state.node = node_t::FUNC_10_3;
    return true;
}

inline bool json::_func_10_3()
{
     depth--; 
    return true;
}
inline bool json::func_10_3(state_t & state)
{
    if (_func_10_3())
    {
        state.node = node_t::NOTIFY_10_4;
        return true;
    }
    state.node = node_t::NO_STATE;
    return false;
}

inline bool json::notify_10_4(state_t & state)
{
    popDepth();
    state.node = node_t::LOOP_1_0;
    return true;
}

void json::_string_11_0(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        jsonResult::value.clear();
    if ((jsonResult::value.length() + len) > 256)
        len = 256 - jsonResult::value.length();
    jsonResult::value.append(data, len);
}

inline bool json::string_11_0(state_t & state)
{
    const static std::array<bool, 256> exitSym = {
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
        else if (!(exitSym[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        _string_11_0(beginData, unsigned(state.data - beginData), state.consumed);
        uint64_t totalConsumed = state.consumed + unsigned(state.data - beginData);
        state.consumed = 0;
        if (totalConsumed >= 1)
        {
            state.node = node_t::NOTIFY_11_1;
            return true;
        } else {
            state.node = node_t::NO_STATE;
            return false;
        }
    }
    if (beginData < state.data)
        _string_11_0(beginData, unsigned(state.data - beginData), state.consumed);
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::STRING_11_0;
    return true;
}

inline bool json::notify_11_1(state_t & state)
{
    gotVal();
    state.node = node_t::LOOP_1_0;
    return true;
}

inline bool json::loop_13_0(state_t & state)
{
    return uint_13_0(state);
}

void json::_uint_13_0(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        jsonResult::depth = 0;
    for(const char * end = &data[len]; data < end; data++)
        jsonResult::depth = jsonResult::depth*10 + *data - '0';
}

inline bool json::uint_13_0(state_t & state)
{
    const static std::array<bool, 256> exitSym = {
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
        else if (!(exitSym[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        _uint_13_0(beginData, unsigned(state.data - beginData), state.consumed);
        uint64_t totalConsumed = state.consumed + unsigned(state.data - beginData);
        state.consumed = 0;
        if (totalConsumed >= 1)
        {
            state.node = node_t::LOOP_13_0;
            return true;
        } else {
            state.node = node_t::NO_STATE;
            return false;
        }
    }
    if (beginData < state.data)
        _uint_13_0(beginData, unsigned(state.data - beginData), state.consumed);
    state.consumed += unsigned(state.data - beginData);
    state.node = node_t::UINT_13_0;
    return true;
}

void json::reset()
{
    jsonResult::depth = 0;
    jsonResult::key.clear();
    jsonResult::value.clear();
    json::mainState = json::state_t();
}

const char * json::state_t::name() const
{
    switch(node)
    {
        case node_t::LOOP_1_0: return "LOOP_1_0";
        case node_t::RANGE_1_0: return "RANGE_1_0";
        case node_t::RANGE_2_0: return "RANGE_2_0";
        case node_t::FUNC_2_1: return "FUNC_2_1";
        case node_t::FUNC_2_2: return "FUNC_2_2";
        case node_t::NOTIFY_2_3: return "NOTIFY_2_3";
        case node_t::RANGE_3_0: return "RANGE_3_0";
        case node_t::FUNC_3_1: return "FUNC_3_1";
        case node_t::NOTIFY_3_2: return "NOTIFY_3_2";
        case node_t::TEXT_4_0: return "TEXT_4_0";
        case node_t::STRING_4_1: return "STRING_4_1";
        case node_t::TEXT_4_2: return "TEXT_4_2";
        case node_t::RANGE_4_3: return "RANGE_4_3";
        case node_t::CASES_4_4: return "CASES_4_4";
        case node_t::TEXT_5_0: return "TEXT_5_0";
        case node_t::RANGE_5_1: return "RANGE_5_1";
        case node_t::CASES_5_2: return "CASES_5_2";
        case node_t::TEXT_6_0: return "TEXT_6_0";
        case node_t::STRING_6_1: return "STRING_6_1";
        case node_t::TEXT_6_2: return "TEXT_6_2";
        case node_t::NOTIFY_6_3: return "NOTIFY_6_3";
        case node_t::STRING_7_0: return "STRING_7_0";
        case node_t::NOTIFY_7_1: return "NOTIFY_7_1";
        case node_t::RANGE_8_0: return "RANGE_8_0";
        case node_t::FUNC_8_1: return "FUNC_8_1";
        case node_t::NOTIFY_8_2: return "NOTIFY_8_2";
        case node_t::TEXT_9_0: return "TEXT_9_0";
        case node_t::FUNC_9_1: return "FUNC_9_1";
        case node_t::NOTIFY_9_2: return "NOTIFY_9_2";
        case node_t::RANGE_10_0: return "RANGE_10_0";
        case node_t::FUNC_10_1: return "FUNC_10_1";
        case node_t::NOTIFY_10_2: return "NOTIFY_10_2";
        case node_t::FUNC_10_3: return "FUNC_10_3";
        case node_t::NOTIFY_10_4: return "NOTIFY_10_4";
        case node_t::STRING_11_0: return "STRING_11_0";
        case node_t::NOTIFY_11_1: return "NOTIFY_11_1";
        case node_t::LOOP_13_0: return "LOOP_13_0";
        case node_t::UINT_13_0: return "UINT_13_0";
        case node_t::NO_STATE: return "NO_STATE";
        default: return "unknown";
    };
}

