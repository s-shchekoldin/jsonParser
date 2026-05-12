// ==============================================================
// Date: 2026-05-12 19:57:21 GMT
// Generated using vProto(2026.05.12)        https://www.cgen.dev
// Author: Sergey Shchekoldin        Email: shchekoldin@gmail.com
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
#if !defined(ALWAYS_INLINE)
    #if defined(_MSC_VER)
        #define ALWAYS_INLINE __forceinline
    #elif defined(__clang__)
        #define ALWAYS_INLINE [[clang::always_inline]]
    #else
        #define ALWAYS_INLINE inline
    #endif
#endif

#if defined(_MSC_VER)
#include <intrin.h>
ALWAYS_INLINE unsigned __ctz32(uint32_t x) { return _tzcnt_u32(x); }
#else
ALWAYS_INLINE unsigned __ctz32(uint32_t x) { return __builtin_ctz(x); }
#endif

void json::parse(StateT & state)
{
    while(true)
    {
#ifdef DEBUG_MODE
        printf("State%s: %s data: [%x, %x, %x, %x, %x]=%.*s\n", &state == &mstate ? "" : "*", state.name(),
            uint8_t(&state.data[0] < state.end ? state.data[0] : 0),
            uint8_t(&state.data[1] < state.end ? state.data[1] : 0),
            uint8_t(&state.data[2] < state.end ? state.data[2] : 0),
            uint8_t(&state.data[3] < state.end ? state.data[3] : 0),
            uint8_t(&state.data[4] < state.end ? state.data[4] : 0),
            10, state.data);
#endif
        NodeT n = state.node;
        const char * d = state.data;
        switch(state.node)
        {
            case NodeT::Loop1_0: loop1_0(state); break;
            case NodeT::Range1_0: range1_0(state); break;
            case NodeT::Range2_0: if (!range2_0(state) || state.node != NodeT::Func2_1) break; [[fallthrough]];
            case NodeT::Func2_1: if (!func2_1(state) || state.node != NodeT::Notify2_2) break; [[fallthrough]];
            case NodeT::Notify2_2: notify2_2(state); break;
            case NodeT::Range3_0: if (!range3_0(state) || state.node != NodeT::Func3_1) break; [[fallthrough]];
            case NodeT::Func3_1: if (!func3_1(state) || state.node != NodeT::Notify3_2) break; [[fallthrough]];
            case NodeT::Notify3_2: notify3_2(state); break;
            case NodeT::Text4_0: if (!text4_0(state) || state.node != NodeT::String4_1) break; [[fallthrough]];
            case NodeT::String4_1: if (!string4_1(state) || state.node != NodeT::Text4_2) break; [[fallthrough]];
            case NodeT::Text4_2: if (!text4_2(state) || state.node != NodeT::Range4_3) break; [[fallthrough]];
            case NodeT::Range4_3: if (!range4_3(state) || state.node != NodeT::Cases4_4) break; [[fallthrough]];
            case NodeT::Cases4_4: cases4_4(state); break;
            case NodeT::Text5_0: if (!text5_0(state) || state.node != NodeT::Range5_1) break; [[fallthrough]];
            case NodeT::Range5_1: if (!range5_1(state) || state.node != NodeT::Cases5_2) break; [[fallthrough]];
            case NodeT::Cases5_2: cases5_2(state); break;
            case NodeT::Text6_0: if (!text6_0(state) || state.node != NodeT::String6_1) break; [[fallthrough]];
            case NodeT::String6_1: if (!string6_1(state) || state.node != NodeT::Text6_2) break; [[fallthrough]];
            case NodeT::Text6_2: if (!text6_2(state) || state.node != NodeT::Notify6_3) break; [[fallthrough]];
            case NodeT::Notify6_3: notify6_3(state); break;
            case NodeT::String7_0: if (!string7_0(state) || state.node != NodeT::Notify7_1) break; [[fallthrough]];
            case NodeT::Notify7_1: notify7_1(state); break;
            case NodeT::Range8_0: if (!range8_0(state) || state.node != NodeT::Func8_1) break; [[fallthrough]];
            case NodeT::Func8_1: if (!func8_1(state) || state.node != NodeT::Notify8_2) break; [[fallthrough]];
            case NodeT::Notify8_2: notify8_2(state); break;
            case NodeT::Text9_0: if (!text9_0(state) || state.node != NodeT::Func9_1) break; [[fallthrough]];
            case NodeT::Func9_1: if (!func9_1(state) || state.node != NodeT::Notify9_2) break; [[fallthrough]];
            case NodeT::Notify9_2: notify9_2(state); break;
            case NodeT::Range10_0: if (!range10_0(state) || state.node != NodeT::Func10_1) break; [[fallthrough]];
            case NodeT::Func10_1: if (!func10_1(state) || state.node != NodeT::Notify10_2) break; [[fallthrough]];
            case NodeT::Notify10_2: if (!notify10_2(state) || state.node != NodeT::Cases10_3) break; [[fallthrough]];
            case NodeT::Cases10_3: cases10_3(state); break;
            case NodeT::Func11_0: if (!func11_0(state) || state.node != NodeT::Notify11_1) break; [[fallthrough]];
            case NodeT::Notify11_1: notify11_1(state); break;
            case NodeT::String12_0: if (!string12_0(state) || state.node != NodeT::Notify12_1) break; [[fallthrough]];
            case NodeT::Notify12_1: notify12_1(state); break;
            case NodeT::Loop14_0: loop14_0(state); break;
            case NodeT::Uint14_0: uint14_0(state); break;
            case NodeT::Loop16_0: loop16_0(state); break;
            case NodeT::NoState:
            default: return;
        }; // switch
        if (d == state.data && n == state.node) [[unlikely]]
            break;
    }
}

bool json::parse(const char * data, unsigned len)
{
    mstate.data = data;
    mstate.end = &data[len];
    parse(mstate);
    return !empty();
}

ALWAYS_INLINE bool json::loop1_0(StateT & state)
{
    if (state.data == state.end)
        return true;
    if (range1_0(state)) // case_1
        return true;
    if (range2_0(state)) // case_2
        return true;
    if (range3_0(state)) // case_3
        return true;
    if (text4_0(state)) // case_4
        return true;
    if (string12_0(state)) // case_5
        return true;
    state.node = NodeT::NoState;
    return true;
}

ALWAYS_INLINE bool json::range1_0(StateT & state) const
{
    const static std::array<bool, 256> terminator = {
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
    const char * datastart = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[8] <= state.end)
        {
            if (terminator[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (terminator[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (terminator[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (terminator[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (terminator[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (terminator[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (terminator[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (terminator[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!(terminator[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        uint64_t total = state.consumed + unsigned(state.data - datastart);
        state.consumed = 0;
        if (total >= 1)
        {
            state.node = NodeT::Loop1_0;
            return true;
        }
        state.node = NodeT::NoState;
        return false;
    }
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Range1_0;
    return true;
}

ALWAYS_INLINE bool json::range2_0(StateT & state) const
{
    const char * datastart = state.data;
    while(state.data < state.end)
    {
        if (uint8_t(state.data[0]) != uint8_t(0x5b) && uint8_t(state.data[0]) != uint8_t(0x7b)) [[unlikely]]
        {
            state.consumed += unsigned(state.data - datastart);
            state.node = (state.consumed >= 1) ? NodeT::Func2_1 : NodeT::NoState;
            bool ret = (state.node == NodeT::Func2_1);
            state.consumed = 0;
            return ret;
        }
        state.data++;
        state.node = NodeT::Func2_1;
        return true;
    }
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Range2_0;
    return true;
}

ALWAYS_INLINE bool json::func2_1()
{
     depth++; key = ""; 
    return true;
}
ALWAYS_INLINE bool json::func2_1(StateT & state)
{
    if (func2_1())
    {
        state.node = NodeT::Notify2_2;
        return true;
    }
    state.node = NodeT::NoState;
    return false;
}

ALWAYS_INLINE bool json::notify2_2(StateT & state)
{
    pushDepth();
    state.node = NodeT::Loop1_0;
    return true;
}

ALWAYS_INLINE bool json::range3_0(StateT & state) const
{
    const char * datastart = state.data;
    while(state.data < state.end)
    {
        if (uint8_t(state.data[0]) != uint8_t(0x5d) && uint8_t(state.data[0]) != uint8_t(0x7d)) [[unlikely]]
        {
            state.consumed += unsigned(state.data - datastart);
            state.node = (state.consumed >= 1) ? NodeT::Func3_1 : NodeT::NoState;
            bool ret = (state.node == NodeT::Func3_1);
            state.consumed = 0;
            return ret;
        }
        state.data++;
        state.node = NodeT::Func3_1;
        return true;
    }
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Range3_0;
    return true;
}

ALWAYS_INLINE bool json::func3_1()
{
     return depth--; 
    return true;
}
ALWAYS_INLINE bool json::func3_1(StateT & state)
{
    if (func3_1())
    {
        state.node = NodeT::Notify3_2;
        return true;
    }
    state.node = NodeT::NoState;
    return false;
}

ALWAYS_INLINE bool json::notify3_2(StateT & state)
{
    popDepth();
    state.node = NodeT::Loop1_0;
    return true;
}

ALWAYS_INLINE bool json::text4_0(StateT & state) const
{
    if(state.data < state.end)
    {
        if (uint8_t(0x22) != uint8_t(state.data[0]))
        {
            state.node = NodeT::NoState;
            return false;
        } else {
            state.data++;
            state.node = NodeT::String4_1;
            return true;
        }
    }
    state.node = NodeT::Text4_0;
    return true;
}

void json::string4_1(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        jsonResult::key.clear();
    if ((jsonResult::key.length() + len) > 256)
        len = 256 - jsonResult::key.length();
    jsonResult::key.append(data, len);
}

ALWAYS_INLINE bool json::string4_1(StateT & state)
{
    const char * datastart = state.data;
#if defined(__AVX2__)
    while(&state.data[32] <= state.end) [[likely]]
    {
        const __m256i d = _mm256_lddqu_si256((const __m256i *)state.data);
        __m256i m = _mm256_cmpeq_epi8(_mm256_set1_epi8(0x22), d);
        uint32_t r = _mm256_movemask_epi8(m);
        if (r) [[unlikely]]
        {
            state.data += __ctz32(r);
            string4_1(datastart, unsigned(state.data - datastart), state.consumed);
            state.consumed = 0;
            state.node = NodeT::Text4_2;
            return true;
        } else
            state.data += 32;
    }
#endif
#if defined(__SSE2__)
    while(&state.data[16] <= state.end) [[likely]]
    {
        const __m128i d = _mm_loadu_si128((const __m128i *)state.data);
        __m128i m = _mm_cmpeq_epi8(_mm_set1_epi8(0x22), d);
        uint16_t r = _mm_movemask_epi8(m);
        if (r) [[unlikely]]
        {
            state.data += __ctz32(r);
            string4_1(datastart, unsigned(state.data - datastart), state.consumed);
            state.consumed = 0;
            state.node = NodeT::Text4_2;
            return true;
        } else
            state.data += 16;
    }
#endif
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[8] <= state.end)
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
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!(uint8_t(state.data[0]) == uint8_t(0x22))) [[unlikely]]
        {
            state.data++;
            continue;
        }
        string4_1(datastart, unsigned(state.data - datastart), state.consumed);
        state.consumed = 0;
        state.node = NodeT::Text4_2;
        return true;
    }
    if (datastart < state.data)
        string4_1(datastart, unsigned(state.data - datastart), state.consumed);
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::String4_1;
    return true;
}

ALWAYS_INLINE bool json::text4_2(StateT & state) const
{
    if(state.data < state.end)
    {
        if (uint8_t(0x22) != uint8_t(state.data[0]))
        {
            state.node = NodeT::NoState;
            return false;
        } else {
            state.data++;
            state.node = NodeT::Range4_3;
            return true;
        }
    }
    state.node = NodeT::Text4_2;
    return true;
}

ALWAYS_INLINE bool json::range4_3(StateT & state) const
{
    const static std::array<bool, 256> terminator = {
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
    const char * datastart = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[8] <= state.end)
        {
            if (terminator[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (terminator[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (terminator[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (terminator[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (terminator[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (terminator[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (terminator[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (terminator[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!(terminator[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        state.consumed = 0;
        state.node = NodeT::Cases4_4;
        return true;
    }
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Range4_3;
    return true;
}

ALWAYS_INLINE bool json::cases4_4(StateT & state) const
{
    if (state.data == state.end)
        return true;
    if (text5_0(state)) // case_1
        return true;
    if (text9_0(state)) // case_2
        return true;
    if (range10_0(state)) // case_3
        return true;
    state.node = NodeT::NoState;
    return true;
}

ALWAYS_INLINE bool json::text5_0(StateT & state) const
{
    if(state.data < state.end)
    {
        if (uint8_t(0x3A) != uint8_t(state.data[0]))
        {
            state.node = NodeT::NoState;
            return false;
        } else {
            state.data++;
            state.node = NodeT::Range5_1;
            return true;
        }
    }
    state.node = NodeT::Text5_0;
    return true;
}

ALWAYS_INLINE bool json::range5_1(StateT & state) const
{
    const static std::array<bool, 256> terminator = {
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
    const char * datastart = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[8] <= state.end)
        {
            if (terminator[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (terminator[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (terminator[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (terminator[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (terminator[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (terminator[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (terminator[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (terminator[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!(terminator[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        state.consumed = 0;
        state.node = NodeT::Cases5_2;
        return true;
    }
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Range5_1;
    return true;
}

ALWAYS_INLINE bool json::cases5_2(StateT & state)
{
    if (state.data == state.end)
        return true;
    if (text6_0(state)) // case_1
        return true;
    if (string7_0(state)) // case_2
        return true;
    if (range8_0(state)) // case_3
        return true;
    state.node = NodeT::NoState;
    return true;
}

ALWAYS_INLINE bool json::text6_0(StateT & state) const
{
    if(state.data < state.end)
    {
        if (uint8_t(0x22) != uint8_t(state.data[0]))
        {
            state.node = NodeT::NoState;
            return false;
        } else {
            state.data++;
            state.node = NodeT::String6_1;
            return true;
        }
    }
    state.node = NodeT::Text6_0;
    return true;
}

void json::string6_1(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        jsonResult::value.clear();
    if ((jsonResult::value.length() + len) > 256)
        len = 256 - jsonResult::value.length();
    jsonResult::value.append(data, len);
}

ALWAYS_INLINE bool json::string6_1(StateT & state)
{
    const char * datastart = state.data;
#if defined(__AVX2__)
    while(&state.data[32] <= state.end) [[likely]]
    {
        const __m256i d = _mm256_lddqu_si256((const __m256i *)state.data);
        __m256i m = _mm256_cmpeq_epi8(_mm256_set1_epi8(0x22), d);
        uint32_t r = _mm256_movemask_epi8(m);
        if (r) [[unlikely]]
        {
            state.data += __ctz32(r);
            string6_1(datastart, unsigned(state.data - datastart), state.consumed);
            state.consumed = 0;
            state.node = NodeT::Text6_2;
            return true;
        } else
            state.data += 32;
    }
#endif
#if defined(__SSE2__)
    while(&state.data[16] <= state.end) [[likely]]
    {
        const __m128i d = _mm_loadu_si128((const __m128i *)state.data);
        __m128i m = _mm_cmpeq_epi8(_mm_set1_epi8(0x22), d);
        uint16_t r = _mm_movemask_epi8(m);
        if (r) [[unlikely]]
        {
            state.data += __ctz32(r);
            string6_1(datastart, unsigned(state.data - datastart), state.consumed);
            state.consumed = 0;
            state.node = NodeT::Text6_2;
            return true;
        } else
            state.data += 16;
    }
#endif
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[8] <= state.end)
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
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!(uint8_t(state.data[0]) == uint8_t(0x22))) [[unlikely]]
        {
            state.data++;
            continue;
        }
        string6_1(datastart, unsigned(state.data - datastart), state.consumed);
        state.consumed = 0;
        state.node = NodeT::Text6_2;
        return true;
    }
    if (datastart < state.data)
        string6_1(datastart, unsigned(state.data - datastart), state.consumed);
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::String6_1;
    return true;
}

ALWAYS_INLINE bool json::text6_2(StateT & state) const
{
    if(state.data < state.end)
    {
        if (uint8_t(0x22) != uint8_t(state.data[0]))
        {
            state.node = NodeT::NoState;
            return false;
        } else {
            state.data++;
            state.node = NodeT::Notify6_3;
            return true;
        }
    }
    state.node = NodeT::Text6_2;
    return true;
}

ALWAYS_INLINE bool json::notify6_3(StateT & state)
{
    gotKV();
    state.node = NodeT::Loop1_0;
    return true;
}

void json::string7_0(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        jsonResult::value.clear();
    if ((jsonResult::value.length() + len) > 256)
        len = 256 - jsonResult::value.length();
    jsonResult::value.append(data, len);
}

ALWAYS_INLINE bool json::string7_0(StateT & state)
{
    const static std::array<bool, 256> terminator = {
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
    const char * datastart = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[8] <= state.end)
        {
            if (terminator[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (terminator[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (terminator[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (terminator[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (terminator[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (terminator[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (terminator[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (terminator[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!(terminator[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        string7_0(datastart, unsigned(state.data - datastart), state.consumed);
        uint64_t total = state.consumed + unsigned(state.data - datastart);
        state.consumed = 0;
        if (total >= 1)
        {
            state.node = NodeT::Notify7_1;
            return true;
        }
        state.node = NodeT::NoState;
        return false;
    }
    if (datastart < state.data)
        string7_0(datastart, unsigned(state.data - datastart), state.consumed);
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::String7_0;
    return true;
}

ALWAYS_INLINE bool json::notify7_1(StateT & state)
{
    gotKV();
    state.node = NodeT::Loop1_0;
    return true;
}

ALWAYS_INLINE bool json::range8_0(StateT & state) const
{
    const char * datastart = state.data;
    while(state.data < state.end)
    {
        if (uint8_t(state.data[0]) != uint8_t(0x5b) && uint8_t(state.data[0]) != uint8_t(0x7b)) [[unlikely]]
        {
            state.consumed += unsigned(state.data - datastart);
            state.node = (state.consumed >= 1) ? NodeT::Func8_1 : NodeT::NoState;
            bool ret = (state.node == NodeT::Func8_1);
            state.consumed = 0;
            return ret;
        }
        state.data++;
        state.node = NodeT::Func8_1;
        return true;
    }
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Range8_0;
    return true;
}

ALWAYS_INLINE bool json::func8_1()
{
     depth++; 
    return true;
}
ALWAYS_INLINE bool json::func8_1(StateT & state)
{
    if (func8_1())
    {
        state.node = NodeT::Notify8_2;
        return true;
    }
    state.node = NodeT::NoState;
    return false;
}

ALWAYS_INLINE bool json::notify8_2(StateT & state)
{
    pushDepth();
    state.node = NodeT::Loop1_0;
    return true;
}

ALWAYS_INLINE bool json::text9_0(StateT & state) const
{
    if(state.data < state.end)
    {
        if (uint8_t(0x2C) != uint8_t(state.data[0]))
        {
            state.node = NodeT::NoState;
            return false;
        } else {
            state.data++;
            state.node = NodeT::Func9_1;
            return true;
        }
    }
    state.node = NodeT::Text9_0;
    return true;
}

ALWAYS_INLINE bool json::func9_1()
{
     value.swap(key); 
    return true;
}
ALWAYS_INLINE bool json::func9_1(StateT & state)
{
    if (func9_1())
    {
        state.node = NodeT::Notify9_2;
        return true;
    }
    state.node = NodeT::NoState;
    return false;
}

ALWAYS_INLINE bool json::notify9_2(StateT & state)
{
    gotVal();
    state.node = NodeT::Loop1_0;
    return true;
}

ALWAYS_INLINE bool json::range10_0(StateT & state) const
{
    const char * datastart = state.data;
    while(state.data < state.end)
    {
        if (uint8_t(state.data[0]) != uint8_t(0x5d) && uint8_t(state.data[0]) != uint8_t(0x7d)) [[unlikely]]
        {
            state.consumed += unsigned(state.data - datastart);
            state.node = (state.consumed >= 1) ? NodeT::Func10_1 : NodeT::NoState;
            bool ret = (state.node == NodeT::Func10_1);
            state.consumed = 0;
            return ret;
        }
        state.data++;
        state.node = NodeT::Func10_1;
        return true;
    }
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Range10_0;
    return true;
}

ALWAYS_INLINE bool json::func10_1()
{
     value.swap(key); 
    return true;
}
ALWAYS_INLINE bool json::func10_1(StateT & state)
{
    if (func10_1())
    {
        state.node = NodeT::Notify10_2;
        return true;
    }
    state.node = NodeT::NoState;
    return false;
}

ALWAYS_INLINE bool json::notify10_2(StateT & state)
{
    gotVal();
    state.node = NodeT::Cases10_3;
    return true;
}

ALWAYS_INLINE bool json::cases10_3(StateT & state)
{
    return func11_0(state);
}

ALWAYS_INLINE bool json::func11_0()
{
     return depth--; 
    return true;
}
ALWAYS_INLINE bool json::func11_0(StateT & state)
{
    if (func11_0())
    {
        state.node = NodeT::Notify11_1;
        return true;
    }
    state.node = NodeT::NoState;
    return false;
}

ALWAYS_INLINE bool json::notify11_1(StateT & state)
{
    popDepth();
    state.node = NodeT::Loop1_0;
    return true;
}

void json::string12_0(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        jsonResult::value.clear();
    if ((jsonResult::value.length() + len) > 256)
        len = 256 - jsonResult::value.length();
    jsonResult::value.append(data, len);
}

ALWAYS_INLINE bool json::string12_0(StateT & state)
{
    const static std::array<bool, 256> terminator = {
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
    const char * datastart = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[8] <= state.end)
        {
            if (terminator[uint8_t(state.data[0])]) [[unlikely]]
                state.data += 0;
            else if (terminator[uint8_t(state.data[1])]) [[unlikely]]
                state.data += 1;
            else if (terminator[uint8_t(state.data[2])]) [[unlikely]]
                state.data += 2;
            else if (terminator[uint8_t(state.data[3])]) [[unlikely]]
                state.data += 3;
            else if (terminator[uint8_t(state.data[4])]) [[unlikely]]
                state.data += 4;
            else if (terminator[uint8_t(state.data[5])]) [[unlikely]]
                state.data += 5;
            else if (terminator[uint8_t(state.data[6])]) [[unlikely]]
                state.data += 6;
            else if (terminator[uint8_t(state.data[7])]) [[unlikely]]
                state.data += 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!(terminator[uint8_t(state.data[0])])) [[unlikely]]
        {
            state.data++;
            continue;
        }
        string12_0(datastart, unsigned(state.data - datastart), state.consumed);
        uint64_t total = state.consumed + unsigned(state.data - datastart);
        state.consumed = 0;
        if (total >= 1)
        {
            state.node = NodeT::Notify12_1;
            return true;
        }
        state.node = NodeT::NoState;
        return false;
    }
    if (datastart < state.data)
        string12_0(datastart, unsigned(state.data - datastart), state.consumed);
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::String12_0;
    return true;
}

ALWAYS_INLINE bool json::notify12_1(StateT & state)
{
    gotVal();
    state.node = NodeT::Loop1_0;
    return true;
}

ALWAYS_INLINE bool json::loop14_0(StateT & state)
{
    return uint14_0(state);
}

void json::uint14_0(const char * data, unsigned len, uint64_t consumed)
{
    if (!consumed)
        jsonResult::depth = 0;
    for(const char * end = &data[len]; data < end; data++)
        jsonResult::depth = jsonResult::depth*10 + *data - '0';
}

ALWAYS_INLINE bool json::uint14_0(StateT & state)
{
    const char * datastart = state.data;
    while(state.data < state.end) [[likely]]
    {
        if(&state.data[8] <= state.end)
        {
            if (!((uint8_t(state.data[0]) >= uint8_t(0x30) && uint8_t(state.data[0]) < uint8_t(0x3a)))) [[unlikely]]
                state.data += 0;
            else if (!((uint8_t(state.data[1]) >= uint8_t(0x30) && uint8_t(state.data[1]) < uint8_t(0x3a)))) [[unlikely]]
                state.data += 1;
            else if (!((uint8_t(state.data[2]) >= uint8_t(0x30) && uint8_t(state.data[2]) < uint8_t(0x3a)))) [[unlikely]]
                state.data += 2;
            else if (!((uint8_t(state.data[3]) >= uint8_t(0x30) && uint8_t(state.data[3]) < uint8_t(0x3a)))) [[unlikely]]
                state.data += 3;
            else if (!((uint8_t(state.data[4]) >= uint8_t(0x30) && uint8_t(state.data[4]) < uint8_t(0x3a)))) [[unlikely]]
                state.data += 4;
            else if (!((uint8_t(state.data[5]) >= uint8_t(0x30) && uint8_t(state.data[5]) < uint8_t(0x3a)))) [[unlikely]]
                state.data += 5;
            else if (!((uint8_t(state.data[6]) >= uint8_t(0x30) && uint8_t(state.data[6]) < uint8_t(0x3a)))) [[unlikely]]
                state.data += 6;
            else if (!((uint8_t(state.data[7]) >= uint8_t(0x30) && uint8_t(state.data[7]) < uint8_t(0x3a)))) [[unlikely]]
                state.data += 7;
            else
            {
                state.data += 8;
                continue;
            }
        }
        else if (!(!((uint8_t(state.data[0]) >= uint8_t(0x30) && uint8_t(state.data[0]) < uint8_t(0x3a))))) [[unlikely]]
        {
            state.data++;
            continue;
        }
        uint14_0(datastart, unsigned(state.data - datastart), state.consumed);
        uint64_t total = state.consumed + unsigned(state.data - datastart);
        state.consumed = 0;
        if (total >= 1)
        {
            state.node = NodeT::Loop14_0;
            return true;
        }
        state.node = NodeT::NoState;
        return false;
    }
    if (datastart < state.data)
        uint14_0(datastart, unsigned(state.data - datastart), state.consumed);
    state.consumed += unsigned(state.data - datastart);
    state.node = NodeT::Uint14_0;
    return true;
}

ALWAYS_INLINE bool json::loop16_0(StateT & state) const
{
    state.node = NodeT::NoState;
    return true;
}

void json::reset()
{
    jsonResult::depth = 0;
    jsonResult::key.clear();
    jsonResult::value.clear();
    json::mstate = json::StateT();
}

const char * json::StateT::name() const
{
    switch(node)
    {
        case NodeT::Loop1_0: return "Loop1_0";
        case NodeT::Range1_0: return "Range1_0";
        case NodeT::Range2_0: return "Range2_0";
        case NodeT::Func2_1: return "Func2_1";
        case NodeT::Notify2_2: return "Notify2_2";
        case NodeT::Range3_0: return "Range3_0";
        case NodeT::Func3_1: return "Func3_1";
        case NodeT::Notify3_2: return "Notify3_2";
        case NodeT::Text4_0: return "Text4_0";
        case NodeT::String4_1: return "String4_1";
        case NodeT::Text4_2: return "Text4_2";
        case NodeT::Range4_3: return "Range4_3";
        case NodeT::Cases4_4: return "Cases4_4";
        case NodeT::Text5_0: return "Text5_0";
        case NodeT::Range5_1: return "Range5_1";
        case NodeT::Cases5_2: return "Cases5_2";
        case NodeT::Text6_0: return "Text6_0";
        case NodeT::String6_1: return "String6_1";
        case NodeT::Text6_2: return "Text6_2";
        case NodeT::Notify6_3: return "Notify6_3";
        case NodeT::String7_0: return "String7_0";
        case NodeT::Notify7_1: return "Notify7_1";
        case NodeT::Range8_0: return "Range8_0";
        case NodeT::Func8_1: return "Func8_1";
        case NodeT::Notify8_2: return "Notify8_2";
        case NodeT::Text9_0: return "Text9_0";
        case NodeT::Func9_1: return "Func9_1";
        case NodeT::Notify9_2: return "Notify9_2";
        case NodeT::Range10_0: return "Range10_0";
        case NodeT::Func10_1: return "Func10_1";
        case NodeT::Notify10_2: return "Notify10_2";
        case NodeT::Cases10_3: return "Cases10_3";
        case NodeT::Func11_0: return "Func11_0";
        case NodeT::Notify11_1: return "Notify11_1";
        case NodeT::String12_0: return "String12_0";
        case NodeT::Notify12_1: return "Notify12_1";
        case NodeT::Loop14_0: return "Loop14_0";
        case NodeT::Uint14_0: return "Uint14_0";
        case NodeT::Loop16_0: return "Loop16_0";
        case NodeT::NoState: return "NoState";
        default: return "unknown";
    };
}

