// ==============================================================
// Date: 2026-06-17 17:04:40 GMT
// Generated using vProto(2026.06.17)        https://www.cgen.dev
// Author: Sergey Shchekoldin        Email: shchekoldin@gmail.com
// autoSSE: 1 cpp98: 0 SIMD: 1
// ==============================================================

// To enable AVX2 use: -mavx2
// To enable SSE2 use: -msse2
// Or: -march=native (may break compatibility)
#include "json.h"
#if defined(__AVX2__)
    #include <immintrin.h>
#endif
#if defined(__SSE2__)
    #include <emmintrin.h>
#elif defined(__ARM_NEON) || defined(__ARM_NEON__)
    #include <arm_neon.h>
#elif defined(__powerpc__) || defined(__wasm_simd128__) || defined(__riscv) || defined (__mips) || defined(__VEC__) || defined(__S390_VX__)
    #if defined(__has_include) && __has_include(<simde/x86/sse2.h>)
        #define SIMDE_ENABLE_NATIVE_ALIASES
        #include <simde/x86/sse2.h>
    #elif defined(_MSC_VER)
        #pragma message("Notice: SIMDe library was not found. Add the path to the SIMDe include directory")
    #elif defined(__GNUC__) || defined(__clang__)
        #pragma message "Notice: SIMDe library was not found. Try installing them with: apt-get install libsimde-dev"
    #endif
#endif

#if defined(_MSC_VER)
    #include <intrin.h>
    inline unsigned __ctz32(uint32_t x) { return _tzcnt_u32(x); }
    inline unsigned __ctz64(uint64_t x) { return _tzcnt_u64(x); }
#else
    inline unsigned __ctz32(uint32_t x) { return __builtin_ctz(x); }
    inline unsigned __ctz64(uint64_t x) { return __builtin_ctzll(x); }
#endif

#ifdef DEBUG_MODE
    #define PRINT_DEBUG(name) \
        printf("State%s: %s data: [%x, %x, %x, %x, %x]=%.*s\n", &state == &mstate ? "" : "*", #name, \
        uint8_t(&data[0] < end ? data[0] : 0), \
        uint8_t(&data[1] < end ? data[1] : 0), \
        uint8_t(&data[2] < end ? data[2] : 0), \
        uint8_t(&data[3] < end ? data[3] : 0), \
        uint8_t(&data[4] < end ? data[4] : 0), \
        std::min(10, int(end - data)), data);
#else
    #define PRINT_DEBUG(name)
#endif

const char * json::parse(StateT & state, const char * data, const char * end)
{
    size_t consumed = state.consumed;
    state.consumed = 0;
    PRINT_DEBUG(PARSE)
    goto Switch;
    Switch:
    {
        switch(state.node)
        {
            case NodeT::Loop1_0: goto Loop1_0;
            case NodeT::Range1_0: goto Range1_0;
            case NodeT::Range2_0: goto Range2_0;
            case NodeT::Func2_1: goto Func2_1;
            case NodeT::Notify2_2: goto Notify2_2;
            case NodeT::Range3_0: goto Range3_0;
            case NodeT::Func3_1: goto Func3_1;
            case NodeT::Notify3_2: goto Notify3_2;
            case NodeT::Text4_0: goto Text4_0;
            case NodeT::StrView4_1: goto StrView4_1;
            case NodeT::Text4_2: goto Text4_2;
            case NodeT::Range4_3: goto Range4_3;
            case NodeT::Cases4_4: goto Cases4_4;
            case NodeT::Text5_0: goto Text5_0;
            case NodeT::Range5_1: goto Range5_1;
            case NodeT::Cases5_2: goto Cases5_2;
            case NodeT::Text6_0: goto Text6_0;
            case NodeT::StrView6_1: goto StrView6_1;
            case NodeT::Text6_2: goto Text6_2;
            case NodeT::Notify6_3: goto Notify6_3;
            case NodeT::StrView7_0: goto StrView7_0;
            case NodeT::Notify7_1: goto Notify7_1;
            case NodeT::Range8_0: goto Range8_0;
            case NodeT::Func8_1: goto Func8_1;
            case NodeT::Notify8_2: goto Notify8_2;
            case NodeT::Text9_0: goto Text9_0;
            case NodeT::Func9_1: goto Func9_1;
            case NodeT::Notify9_2: goto Notify9_2;
            case NodeT::Range10_0: goto Range10_0;
            case NodeT::Func10_1: goto Func10_1;
            case NodeT::Notify10_2: goto Notify10_2;
            case NodeT::Cases10_3: goto Cases10_3;
            case NodeT::Func11_0: goto Func11_0;
            case NodeT::Notify11_1: goto Notify11_1;
            case NodeT::StrView12_0: goto StrView12_0;
            case NodeT::Notify12_1: goto Notify12_1;
            case NodeT::Loop14_0: goto Loop14_0;
            case NodeT::Uint14_0: goto Uint14_0;
            case NodeT::Loop16_0: goto Loop16_0;
            case NodeT::NoState:
            default: return data;
        };
    }

    Loop1_0:
    {
        PRINT_DEBUG(Loop1_0)
        if (data == end)
        {
            state.node = NodeT::Loop1_0;
            return data;
        }
        if ((uint8_t(data[0]) >= uint8_t(0x09) && uint8_t(data[0]) <= uint8_t(0x0a)) || (uint8_t(data[0]) == uint8_t(0x0d)) || (uint8_t(data[0]) == uint8_t(0x20)) || (uint8_t(data[0]) == uint8_t(0x2c)))
        {
            data++;
            consumed = 1;
            goto Range1_0;
        }
        if (((uint8_t(data[0]) ^ uint8_t(0x5b)) & 0xDF) == 0)
        {
            goto Range2_0;
        }
        if (((uint8_t(data[0]) ^ uint8_t(0x5d)) & 0xDF) == 0)
        {
            goto Range3_0;
        }
        if (uint8_t(data[0]) == uint8_t(0x22))
        {
            goto Text4_0;
        }
        if (!((uint8_t(data[0]) <= uint8_t(0x2c)) || (uint8_t(data[0]) == uint8_t(0x2f)) || (uint8_t(data[0]) >= uint8_t(0x3a) && uint8_t(data[0]) <= uint8_t(0x40)) || (uint8_t(data[0]) >= uint8_t(0x5b) && uint8_t(data[0]) <= uint8_t(0x5e)) || (uint8_t(data[0]) == uint8_t(0x60)) || (uint8_t(data[0]) >= uint8_t(0x7b))))
        {
            goto StrView12_0;
        }
        goto NoState;
    }

    Range1_0:
    {
        PRINT_DEBUG(Range1_0)
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
        const char * datastart = data;
        const size_t min = 1;
        while(true)
        {
            if(data + 8 <= end)
            {
                if (terminator[uint8_t(data[0])]) [[unlikely]]
                    data += 0;
                else if (terminator[uint8_t(data[1])]) [[unlikely]]
                    data += 1;
                else if (terminator[uint8_t(data[2])]) [[unlikely]]
                    data += 2;
                else if (terminator[uint8_t(data[3])]) [[unlikely]]
                    data += 3;
                else if (terminator[uint8_t(data[4])]) [[unlikely]]
                    data += 4;
                else if (terminator[uint8_t(data[5])]) [[unlikely]]
                    data += 5;
                else if (terminator[uint8_t(data[6])]) [[unlikely]]
                    data += 6;
                else if (terminator[uint8_t(data[7])]) [[unlikely]]
                    data += 7;
                else
                {
                    data += 8;
                    continue;
                }
            }
            else if (data >= end)
                break;
            else if (!(terminator[uint8_t(data[0])]))
            {
                data++;
                continue;
            }
            size_t total = consumed + size_t(data - datastart);
            consumed = 0;
            if (total >= min)
            {
                goto Loop1_0;
            }
            goto NoState;
        }
        state.consumed = consumed + size_t(data - datastart);
        state.node = NodeT::Range1_0;
        return data;
    }

    Range2_0:
    {
        PRINT_DEBUG(Range2_0)
        const char * datastart = data;
        const size_t min = 1;
        if(data < end)
        {
            if (!(((uint8_t(data[0]) ^ uint8_t(0x5b)) & 0xDF) == 0)) [[unlikely]]
            {
                size_t total = consumed + size_t(data - datastart);
                consumed = 0;
                if (total >= min)
                {
                    goto Func2_1;
                }
                goto NoState;
            }
            data++;
            consumed = 0;
            goto Func2_1;
        }
        state.consumed = consumed + size_t(data - datastart);
        state.node = NodeT::Range2_0;
        return data;
    }

    Func2_1:
    {
        PRINT_DEBUG(Func2_1)
        if (func2_1())
        {
            goto Notify2_2;
        }
        goto NoState;
    }

    Notify2_2:
    {
        PRINT_DEBUG(Notify2_2)
        pushDepth();
        goto Loop1_0;
    }

    Range3_0:
    {
        PRINT_DEBUG(Range3_0)
        const char * datastart = data;
        const size_t min = 1;
        if(data < end)
        {
            if (!(((uint8_t(data[0]) ^ uint8_t(0x5d)) & 0xDF) == 0)) [[unlikely]]
            {
                size_t total = consumed + size_t(data - datastart);
                consumed = 0;
                if (total >= min)
                {
                    goto Func3_1;
                }
                goto NoState;
            }
            data++;
            consumed = 0;
            goto Func3_1;
        }
        state.consumed = consumed + size_t(data - datastart);
        state.node = NodeT::Range3_0;
        return data;
    }

    Func3_1:
    {
        PRINT_DEBUG(Func3_1)
        if (func3_1())
        {
            goto Notify3_2;
        }
        goto NoState;
    }

    Notify3_2:
    {
        PRINT_DEBUG(Notify3_2)
        popDepth();
        goto Loop1_0;
    }

    Text4_0:
    {
        PRINT_DEBUG(Text4_0)
        if(data < end)
        {
            if (uint8_t(0x22) != uint8_t(data[0]))
            {
                goto NoState;
            } else {
                data++;
                goto StrView4_1;
            }
        }
        state.node = NodeT::Text4_0;
        return data;
    }

    StrView4_1:
    {
        PRINT_DEBUG(StrView4_1)
        const char * datastart = data;
        #if defined(__AVX2__)
        while(data + 32 <= end) [[likely]]
        {
            const __m256i d = _mm256_lddqu_si256((const __m256i *)data);
            __m256i m = _mm256_cmpeq_epi8(_mm256_set1_epi8(char(0x22)), d);
            uint32_t r = _mm256_movemask_epi8(m);
            if(r) [[unlikely]]
            {
                data += __ctz32(r);
                strview4_1(datastart, size_t(data - datastart), consumed);
                consumed = 0;
                goto Text4_2;
            }
            else
                data += 32;
        }
        #endif
        #if defined(__SSE2__)
        while(data + 16 <= end) [[likely]]
        {
            const __m128i d = _mm_loadu_si128((const __m128i *)data);
            __m128i m = _mm_cmpeq_epi8(_mm_set1_epi8(char(0x22)), d);
            uint16_t r = _mm_movemask_epi8(m);
            if(r) [[unlikely]]
            {
                data += __ctz32(r);
                strview4_1(datastart, size_t(data - datastart), consumed);
                consumed = 0;
                goto Text4_2;
            }
            else
                data += 16;
        }
        #elif defined(__ARM_NEON) || defined(__ARM_NEON__)
        while(data + 16 <= end) [[likely]]
        {
            const uint8x16_t d = vld1q_u8((const uint8_t *)data);
            uint8x16_t m = vceqq_u8(d, vdupq_n_u8(0x22));
            if(vmaxvq_u8(m)) [[unlikely]]
            {
                uint64_t u64l = vgetq_lane_u64(vreinterpretq_u64_u8(m), 0);
                uint64_t u64h = vgetq_lane_u64(vreinterpretq_u64_u8(m), 1);
                data += (u64l ? __ctz64(u64l) : (64 + __ctz64(u64h))) >> 3;
                strview4_1(datastart, size_t(data - datastart), consumed);
                consumed = 0;
                goto Text4_2;
            }
            else
                data += 16;
        }
        #elif defined(SIMDE_ENABLE_NATIVE_ALIASES)
        while(data + 16 <= end) [[likely]]
        {
            const simde__m128i d = simde_mm_loadu_si128((const simde__m128i *)data);
            simde__m128i m = simde_mm_cmpeq_epi8(simde_mm_set1_epi8(char(0x22)), d);
            uint16_t r = simde_mm_movemask_epi8(m);
            if(r) [[unlikely]]
            {
                data += __ctz32(r);
                strview4_1(datastart, size_t(data - datastart), consumed);
                consumed = 0;
                goto Text4_2;
            }
            else
                data += 16;
        }
        #endif
        while(true)
        {
            if(data + 8 <= end)
            {
                if (uint8_t(data[0]) == uint8_t(0x22)) [[unlikely]]
                    data += 0;
                else if (uint8_t(data[1]) == uint8_t(0x22)) [[unlikely]]
                    data += 1;
                else if (uint8_t(data[2]) == uint8_t(0x22)) [[unlikely]]
                    data += 2;
                else if (uint8_t(data[3]) == uint8_t(0x22)) [[unlikely]]
                    data += 3;
                else if (uint8_t(data[4]) == uint8_t(0x22)) [[unlikely]]
                    data += 4;
                else if (uint8_t(data[5]) == uint8_t(0x22)) [[unlikely]]
                    data += 5;
                else if (uint8_t(data[6]) == uint8_t(0x22)) [[unlikely]]
                    data += 6;
                else if (uint8_t(data[7]) == uint8_t(0x22)) [[unlikely]]
                    data += 7;
                else
                {
                    data += 8;
                    continue;
                }
            }
            else if (data >= end)
                break;
            else if (!(uint8_t(data[0]) == uint8_t(0x22)))
            {
                data++;
                continue;
            }
            strview4_1(datastart, size_t(data - datastart), consumed);
            consumed = 0;
            goto Text4_2;
        }
        if (datastart < data)
            strview4_1(datastart, size_t(data - datastart), consumed);
        state.consumed = consumed + size_t(data - datastart);
        state.node = NodeT::StrView4_1;
        return data;
    }

    Text4_2:
    {
        PRINT_DEBUG(Text4_2)
        if(data < end)
        {
            if (uint8_t(0x22) != uint8_t(data[0]))
            {
                goto NoState;
            } else {
                data++;
                goto Range4_3;
            }
        }
        state.node = NodeT::Text4_2;
        return data;
    }

    Range4_3:
    {
        PRINT_DEBUG(Range4_3)
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
        const char * datastart = data;
        while(true)
        {
            if(data + 8 <= end)
            {
                if (terminator[uint8_t(data[0])]) [[unlikely]]
                    data += 0;
                else if (terminator[uint8_t(data[1])]) [[unlikely]]
                    data += 1;
                else if (terminator[uint8_t(data[2])]) [[unlikely]]
                    data += 2;
                else if (terminator[uint8_t(data[3])]) [[unlikely]]
                    data += 3;
                else if (terminator[uint8_t(data[4])]) [[unlikely]]
                    data += 4;
                else if (terminator[uint8_t(data[5])]) [[unlikely]]
                    data += 5;
                else if (terminator[uint8_t(data[6])]) [[unlikely]]
                    data += 6;
                else if (terminator[uint8_t(data[7])]) [[unlikely]]
                    data += 7;
                else
                {
                    data += 8;
                    continue;
                }
            }
            else if (data >= end)
                break;
            else if (!(terminator[uint8_t(data[0])]))
            {
                data++;
                continue;
            }
            consumed = 0;
            goto Cases4_4;
        }
        state.consumed = consumed + size_t(data - datastart);
        state.node = NodeT::Range4_3;
        return data;
    }

    Cases4_4:
    {
        PRINT_DEBUG(Cases4_4)
        if (data == end)
        {
            state.node = NodeT::Cases4_4;
            return data;
        }
        if (uint8_t(data[0]) == uint8_t(0x3a))
        {
            goto Text5_0;
        }
        if (uint8_t(data[0]) == uint8_t(0x2c))
        {
            goto Text9_0;
        }
        if (((uint8_t(data[0]) ^ uint8_t(0x5d)) & 0xDF) == 0)
        {
            goto Range10_0;
        }
        goto NoState;
    }

    Text5_0:
    {
        PRINT_DEBUG(Text5_0)
        if(data < end)
        {
            if (uint8_t(0x3A) != uint8_t(data[0]))
            {
                goto NoState;
            } else {
                data++;
                goto Range5_1;
            }
        }
        state.node = NodeT::Text5_0;
        return data;
    }

    Range5_1:
    {
        PRINT_DEBUG(Range5_1)
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
        const char * datastart = data;
        while(true)
        {
            if(data + 8 <= end)
            {
                if (terminator[uint8_t(data[0])]) [[unlikely]]
                    data += 0;
                else if (terminator[uint8_t(data[1])]) [[unlikely]]
                    data += 1;
                else if (terminator[uint8_t(data[2])]) [[unlikely]]
                    data += 2;
                else if (terminator[uint8_t(data[3])]) [[unlikely]]
                    data += 3;
                else if (terminator[uint8_t(data[4])]) [[unlikely]]
                    data += 4;
                else if (terminator[uint8_t(data[5])]) [[unlikely]]
                    data += 5;
                else if (terminator[uint8_t(data[6])]) [[unlikely]]
                    data += 6;
                else if (terminator[uint8_t(data[7])]) [[unlikely]]
                    data += 7;
                else
                {
                    data += 8;
                    continue;
                }
            }
            else if (data >= end)
                break;
            else if (!(terminator[uint8_t(data[0])]))
            {
                data++;
                continue;
            }
            consumed = 0;
            goto Cases5_2;
        }
        state.consumed = consumed + size_t(data - datastart);
        state.node = NodeT::Range5_1;
        return data;
    }

    Cases5_2:
    {
        PRINT_DEBUG(Cases5_2)
        if (data == end)
        {
            state.node = NodeT::Cases5_2;
            return data;
        }
        if (uint8_t(data[0]) == uint8_t(0x22))
        {
            goto Text6_0;
        }
        if (!((uint8_t(data[0]) <= uint8_t(0x2c)) || (uint8_t(data[0]) == uint8_t(0x2f)) || (uint8_t(data[0]) >= uint8_t(0x3a) && uint8_t(data[0]) <= uint8_t(0x40)) || (uint8_t(data[0]) >= uint8_t(0x5b) && uint8_t(data[0]) <= uint8_t(0x60)) || (uint8_t(data[0]) >= uint8_t(0x7b))))
        {
            goto StrView7_0;
        }
        if (((uint8_t(data[0]) ^ uint8_t(0x5b)) & 0xDF) == 0)
        {
            goto Range8_0;
        }
        goto NoState;
    }

    Text6_0:
    {
        PRINT_DEBUG(Text6_0)
        if(data < end)
        {
            if (uint8_t(0x22) != uint8_t(data[0]))
            {
                goto NoState;
            } else {
                data++;
                goto StrView6_1;
            }
        }
        state.node = NodeT::Text6_0;
        return data;
    }

    StrView6_1:
    {
        PRINT_DEBUG(StrView6_1)
        const char * datastart = data;
        #if defined(__AVX2__)
        while(data + 32 <= end) [[likely]]
        {
            const __m256i d = _mm256_lddqu_si256((const __m256i *)data);
            __m256i m = _mm256_cmpeq_epi8(_mm256_set1_epi8(char(0x22)), d);
            uint32_t r = _mm256_movemask_epi8(m);
            if(r) [[unlikely]]
            {
                data += __ctz32(r);
                strview6_1(datastart, size_t(data - datastart), consumed);
                consumed = 0;
                goto Text6_2;
            }
            else
                data += 32;
        }
        #endif
        #if defined(__SSE2__)
        while(data + 16 <= end) [[likely]]
        {
            const __m128i d = _mm_loadu_si128((const __m128i *)data);
            __m128i m = _mm_cmpeq_epi8(_mm_set1_epi8(char(0x22)), d);
            uint16_t r = _mm_movemask_epi8(m);
            if(r) [[unlikely]]
            {
                data += __ctz32(r);
                strview6_1(datastart, size_t(data - datastart), consumed);
                consumed = 0;
                goto Text6_2;
            }
            else
                data += 16;
        }
        #elif defined(__ARM_NEON) || defined(__ARM_NEON__)
        while(data + 16 <= end) [[likely]]
        {
            const uint8x16_t d = vld1q_u8((const uint8_t *)data);
            uint8x16_t m = vceqq_u8(d, vdupq_n_u8(0x22));
            if(vmaxvq_u8(m)) [[unlikely]]
            {
                uint64_t u64l = vgetq_lane_u64(vreinterpretq_u64_u8(m), 0);
                uint64_t u64h = vgetq_lane_u64(vreinterpretq_u64_u8(m), 1);
                data += (u64l ? __ctz64(u64l) : (64 + __ctz64(u64h))) >> 3;
                strview6_1(datastart, size_t(data - datastart), consumed);
                consumed = 0;
                goto Text6_2;
            }
            else
                data += 16;
        }
        #elif defined(SIMDE_ENABLE_NATIVE_ALIASES)
        while(data + 16 <= end) [[likely]]
        {
            const simde__m128i d = simde_mm_loadu_si128((const simde__m128i *)data);
            simde__m128i m = simde_mm_cmpeq_epi8(simde_mm_set1_epi8(char(0x22)), d);
            uint16_t r = simde_mm_movemask_epi8(m);
            if(r) [[unlikely]]
            {
                data += __ctz32(r);
                strview6_1(datastart, size_t(data - datastart), consumed);
                consumed = 0;
                goto Text6_2;
            }
            else
                data += 16;
        }
        #endif
        while(true)
        {
            if(data + 8 <= end)
            {
                if (uint8_t(data[0]) == uint8_t(0x22)) [[unlikely]]
                    data += 0;
                else if (uint8_t(data[1]) == uint8_t(0x22)) [[unlikely]]
                    data += 1;
                else if (uint8_t(data[2]) == uint8_t(0x22)) [[unlikely]]
                    data += 2;
                else if (uint8_t(data[3]) == uint8_t(0x22)) [[unlikely]]
                    data += 3;
                else if (uint8_t(data[4]) == uint8_t(0x22)) [[unlikely]]
                    data += 4;
                else if (uint8_t(data[5]) == uint8_t(0x22)) [[unlikely]]
                    data += 5;
                else if (uint8_t(data[6]) == uint8_t(0x22)) [[unlikely]]
                    data += 6;
                else if (uint8_t(data[7]) == uint8_t(0x22)) [[unlikely]]
                    data += 7;
                else
                {
                    data += 8;
                    continue;
                }
            }
            else if (data >= end)
                break;
            else if (!(uint8_t(data[0]) == uint8_t(0x22)))
            {
                data++;
                continue;
            }
            strview6_1(datastart, size_t(data - datastart), consumed);
            consumed = 0;
            goto Text6_2;
        }
        if (datastart < data)
            strview6_1(datastart, size_t(data - datastart), consumed);
        state.consumed = consumed + size_t(data - datastart);
        state.node = NodeT::StrView6_1;
        return data;
    }

    Text6_2:
    {
        PRINT_DEBUG(Text6_2)
        if(data < end)
        {
            if (uint8_t(0x22) != uint8_t(data[0]))
            {
                goto NoState;
            } else {
                data++;
                goto Notify6_3;
            }
        }
        state.node = NodeT::Text6_2;
        return data;
    }

    Notify6_3:
    {
        PRINT_DEBUG(Notify6_3)
        gotKV();
        goto Loop1_0;
    }

    StrView7_0:
    {
        PRINT_DEBUG(StrView7_0)
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
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // ^[0-0x2c][0x2f][0x3a-0x40][0x5b-0x60][0x7b-0xff]
        const char * datastart = data;
        const size_t min = 1;
        while(true)
        {
            if(data + 8 <= end)
            {
                if (terminator[uint8_t(data[0])]) [[unlikely]]
                    data += 0;
                else if (terminator[uint8_t(data[1])]) [[unlikely]]
                    data += 1;
                else if (terminator[uint8_t(data[2])]) [[unlikely]]
                    data += 2;
                else if (terminator[uint8_t(data[3])]) [[unlikely]]
                    data += 3;
                else if (terminator[uint8_t(data[4])]) [[unlikely]]
                    data += 4;
                else if (terminator[uint8_t(data[5])]) [[unlikely]]
                    data += 5;
                else if (terminator[uint8_t(data[6])]) [[unlikely]]
                    data += 6;
                else if (terminator[uint8_t(data[7])]) [[unlikely]]
                    data += 7;
                else
                {
                    data += 8;
                    continue;
                }
            }
            else if (data >= end)
                break;
            else if (!(terminator[uint8_t(data[0])]))
            {
                data++;
                continue;
            }
            strview7_0(datastart, size_t(data - datastart), consumed);
            size_t total = consumed + size_t(data - datastart);
            consumed = 0;
            if (total >= min)
            {
                goto Notify7_1;
            }
            goto NoState;
        }
        if (datastart < data)
            strview7_0(datastart, size_t(data - datastart), consumed);
        state.consumed = consumed + size_t(data - datastart);
        state.node = NodeT::StrView7_0;
        return data;
    }

    Notify7_1:
    {
        PRINT_DEBUG(Notify7_1)
        gotKV();
        goto Loop1_0;
    }

    Range8_0:
    {
        PRINT_DEBUG(Range8_0)
        const char * datastart = data;
        const size_t min = 1;
        if(data < end)
        {
            if (!(((uint8_t(data[0]) ^ uint8_t(0x5b)) & 0xDF) == 0)) [[unlikely]]
            {
                size_t total = consumed + size_t(data - datastart);
                consumed = 0;
                if (total >= min)
                {
                    goto Func8_1;
                }
                goto NoState;
            }
            data++;
            consumed = 0;
            goto Func8_1;
        }
        state.consumed = consumed + size_t(data - datastart);
        state.node = NodeT::Range8_0;
        return data;
    }

    Func8_1:
    {
        PRINT_DEBUG(Func8_1)
        if (func8_1())
        {
            goto Notify8_2;
        }
        goto NoState;
    }

    Notify8_2:
    {
        PRINT_DEBUG(Notify8_2)
        pushDepth();
        goto Loop1_0;
    }

    Text9_0:
    {
        PRINT_DEBUG(Text9_0)
        if(data < end)
        {
            if (uint8_t(0x2C) != uint8_t(data[0]))
            {
                goto NoState;
            } else {
                data++;
                goto Func9_1;
            }
        }
        state.node = NodeT::Text9_0;
        return data;
    }

    Func9_1:
    {
        PRINT_DEBUG(Func9_1)
        if (func9_1())
        {
            goto Notify9_2;
        }
        goto NoState;
    }

    Notify9_2:
    {
        PRINT_DEBUG(Notify9_2)
        gotVal();
        goto Loop1_0;
    }

    Range10_0:
    {
        PRINT_DEBUG(Range10_0)
        const char * datastart = data;
        const size_t min = 1;
        if(data < end)
        {
            if (!(((uint8_t(data[0]) ^ uint8_t(0x5d)) & 0xDF) == 0)) [[unlikely]]
            {
                size_t total = consumed + size_t(data - datastart);
                consumed = 0;
                if (total >= min)
                {
                    goto Func10_1;
                }
                goto NoState;
            }
            data++;
            consumed = 0;
            goto Func10_1;
        }
        state.consumed = consumed + size_t(data - datastart);
        state.node = NodeT::Range10_0;
        return data;
    }

    Func10_1:
    {
        PRINT_DEBUG(Func10_1)
        if (func10_1())
        {
            goto Notify10_2;
        }
        goto NoState;
    }

    Notify10_2:
    {
        PRINT_DEBUG(Notify10_2)
        gotVal();
        goto Cases10_3;
    }

    Cases10_3:
    {
        PRINT_DEBUG(Cases10_3)
        goto Func11_0;
    }

    Func11_0:
    {
        PRINT_DEBUG(Func11_0)
        if (func11_0())
        {
            goto Notify11_1;
        }
        goto NoState;
    }

    Notify11_1:
    {
        PRINT_DEBUG(Notify11_1)
        popDepth();
        goto Loop1_0;
    }

    StrView12_0:
    {
        PRINT_DEBUG(StrView12_0)
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
             true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true}; // ^[0-0x2c][0x2f][0x3a-0x40][0x5b-0x5e][0x60][0x7b-0xff]
        const char * datastart = data;
        const size_t min = 1;
        while(true)
        {
            if(data + 8 <= end)
            {
                if (terminator[uint8_t(data[0])]) [[unlikely]]
                    data += 0;
                else if (terminator[uint8_t(data[1])]) [[unlikely]]
                    data += 1;
                else if (terminator[uint8_t(data[2])]) [[unlikely]]
                    data += 2;
                else if (terminator[uint8_t(data[3])]) [[unlikely]]
                    data += 3;
                else if (terminator[uint8_t(data[4])]) [[unlikely]]
                    data += 4;
                else if (terminator[uint8_t(data[5])]) [[unlikely]]
                    data += 5;
                else if (terminator[uint8_t(data[6])]) [[unlikely]]
                    data += 6;
                else if (terminator[uint8_t(data[7])]) [[unlikely]]
                    data += 7;
                else
                {
                    data += 8;
                    continue;
                }
            }
            else if (data >= end)
                break;
            else if (!(terminator[uint8_t(data[0])]))
            {
                data++;
                continue;
            }
            strview12_0(datastart, size_t(data - datastart), consumed);
            size_t total = consumed + size_t(data - datastart);
            consumed = 0;
            if (total >= min)
            {
                goto Notify12_1;
            }
            goto NoState;
        }
        if (datastart < data)
            strview12_0(datastart, size_t(data - datastart), consumed);
        state.consumed = consumed + size_t(data - datastart);
        state.node = NodeT::StrView12_0;
        return data;
    }

    Notify12_1:
    {
        PRINT_DEBUG(Notify12_1)
        gotVal();
        goto Loop1_0;
    }

    Loop14_0:
    {
        PRINT_DEBUG(Loop14_0)
        goto Uint14_0;
    }

    Uint14_0:
    {
        PRINT_DEBUG(Uint14_0)
        const char * datastart = data;
        const size_t min = 1;
        while(true)
        {
            if(data + 8 <= end)
            {
                if ((uint8_t(data[0]) <= uint8_t(0x2f)) || (uint8_t(data[0]) >= uint8_t(0x3a))) [[unlikely]]
                    data += 0;
                else if ((uint8_t(data[1]) <= uint8_t(0x2f)) || (uint8_t(data[1]) >= uint8_t(0x3a))) [[unlikely]]
                    data += 1;
                else if ((uint8_t(data[2]) <= uint8_t(0x2f)) || (uint8_t(data[2]) >= uint8_t(0x3a))) [[unlikely]]
                    data += 2;
                else if ((uint8_t(data[3]) <= uint8_t(0x2f)) || (uint8_t(data[3]) >= uint8_t(0x3a))) [[unlikely]]
                    data += 3;
                else if ((uint8_t(data[4]) <= uint8_t(0x2f)) || (uint8_t(data[4]) >= uint8_t(0x3a))) [[unlikely]]
                    data += 4;
                else if ((uint8_t(data[5]) <= uint8_t(0x2f)) || (uint8_t(data[5]) >= uint8_t(0x3a))) [[unlikely]]
                    data += 5;
                else if ((uint8_t(data[6]) <= uint8_t(0x2f)) || (uint8_t(data[6]) >= uint8_t(0x3a))) [[unlikely]]
                    data += 6;
                else if ((uint8_t(data[7]) <= uint8_t(0x2f)) || (uint8_t(data[7]) >= uint8_t(0x3a))) [[unlikely]]
                    data += 7;
                else
                {
                    data += 8;
                    continue;
                }
            }
            else if (data >= end)
                break;
            else if (!((uint8_t(data[0]) <= uint8_t(0x2f)) || (uint8_t(data[0]) >= uint8_t(0x3a))))
            {
                data++;
                continue;
            }
            uint14_0(datastart, size_t(data - datastart), consumed);
            size_t total = consumed + size_t(data - datastart);
            consumed = 0;
            if (total >= min)
            {
                goto Loop14_0;
            }
            goto NoState;
        }
        if (datastart < data)
            uint14_0(datastart, size_t(data - datastart), consumed);
        state.consumed = consumed + size_t(data - datastart);
        state.node = NodeT::Uint14_0;
        return data;
    }

    Loop16_0:
    {
        PRINT_DEBUG(Loop16_0)
        goto NoState;
    }

    NoState:
    {
        state.node = NodeT::NoState;
        return data;
    }
}

inline bool json::func2_1()
{
     depth++; key = ""; 
    return true;
}

inline bool json::func3_1()
{
     return depth--; 
    return true;
}

inline void json::strview4_1(const char * data, size_t len, size_t consumed)
{
    if (!consumed)
        jsonResult::key = std::string_view();
    jsonResult::key = std::string_view(data, len);
}

inline void json::strview6_1(const char * data, size_t len, size_t consumed)
{
    if (!consumed)
        jsonResult::value = std::string_view();
    jsonResult::value = std::string_view(data, len);
}

inline void json::strview7_0(const char * data, size_t len, size_t consumed)
{
    if (!consumed)
        jsonResult::value = std::string_view();
    jsonResult::value = std::string_view(data, len);
}

inline bool json::func8_1()
{
     depth++; 
    return true;
}

inline bool json::func9_1()
{
     value.swap(key); 
    return true;
}

inline bool json::func10_1()
{
     value.swap(key); 
    return true;
}

inline bool json::func11_0()
{
     return depth--; 
    return true;
}

inline void json::strview12_0(const char * data, size_t len, size_t consumed)
{
    if (!consumed)
        jsonResult::value = std::string_view();
    jsonResult::value = std::string_view(data, len);
}

inline void json::uint14_0(const char * data, size_t len, size_t consumed)
{
    if (!consumed)
        jsonResult::depth = 0;
    for(const char * end = &data[len]; data < end; data++)
        jsonResult::depth = jsonResult::depth*10 + *data - '0';
}

bool json::parse(const char * data, const char * end)
{
    jsonResult::key = std::string_view();
    jsonResult::value = std::string_view();
    parse(mstate, data, end);
    return !empty();
}

void json::reset()
{
    jsonResult::depth = 0;
    jsonResult::key = std::string_view();
    jsonResult::value = std::string_view();
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
        case NodeT::StrView4_1: return "StrView4_1";
        case NodeT::Text4_2: return "Text4_2";
        case NodeT::Range4_3: return "Range4_3";
        case NodeT::Cases4_4: return "Cases4_4";
        case NodeT::Text5_0: return "Text5_0";
        case NodeT::Range5_1: return "Range5_1";
        case NodeT::Cases5_2: return "Cases5_2";
        case NodeT::Text6_0: return "Text6_0";
        case NodeT::StrView6_1: return "StrView6_1";
        case NodeT::Text6_2: return "Text6_2";
        case NodeT::Notify6_3: return "Notify6_3";
        case NodeT::StrView7_0: return "StrView7_0";
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
        case NodeT::StrView12_0: return "StrView12_0";
        case NodeT::Notify12_1: return "Notify12_1";
        case NodeT::Loop14_0: return "Loop14_0";
        case NodeT::Uint14_0: return "Uint14_0";
        case NodeT::Loop16_0: return "Loop16_0";
        case NodeT::NoState: return "NoState";
        default: return "unknown";
    };
}

