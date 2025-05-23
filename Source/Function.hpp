#pragma once

#include "types.hpp"

#if _MSC_VER > 1200
    #include <stdio.h> // printf
#endif

// Pattern: 0x90, 0x90 0xB8 [addr bytes x4] 0xB8 [status bytes x4] 0x90 0x90
#define FUNC_MARKER_ASM(addr, status) __asm nop __asm nop __asm mov eax, addr __asm mov eax, status __asm nop __asm nop

#if defined(_MSC_VER)
    #define MATCH_FUNC(addr)                   \
        __declspec(naked) void Marker_##addr() \
        {                                      \
            FUNC_MARKER_ASM(addr, 1)           \
        }
    #define STUB_FUNC(addr)                    \
        __declspec(naked) void Marker_##addr() \
        {                                      \
            FUNC_MARKER_ASM(addr, 0)           \
        }

    #if defined(EXPORT_FUNCS)
        #define EXPORT __declspec(dllexport)
    #else
        #define EXPORT
    #endif

    #if defined(EXPORT_VARS) || defined(IMPORT_VARS)
        #if defined(EXPORT_VARS)
            #define EXPORT_VAR __declspec(dllexport)
        #elif defined(IMPORT_VARS)
            #define EXPORT_VAR __declspec(dllimport)
        #endif
    #else
        #define EXPORT_VAR
    #endif

    #if _MSC_VER > 1200
        #define NOT_IMPLEMENTED                               \
            static bool done___ = false;                      \
            if (!done___)                                     \
            {                                                 \
                done___ = true;                               \
                printf("NOT IMPLEMENTED %s\n", __FUNCTION__); \
            }
    #else
void __stdcall LogNotImplemented(u32 codeAddr);

        // Call the lable next: to get the ip
        #define GET_IP(var)   \
            __asm call $ + 5; \
            __asm pop var;
        #define NOT_IMPLEMENTED                                                                                                       \
            do                                                                                                                        \
            {                                                                                                                         \
                static bool logged = false;                                                                                           \
                if (!logged)                                                                                                          \
                {                                                                                                                     \
                    unsigned int ip;                                                                                                  \
                    __asm { _emit 0xE8 }                                                                                                \
                    __asm {_emit 0x00} __asm {_emit 0x00} __asm {_emit 0x00} __asm {_emit 0x00} __asm {pop ip} LogNotImplemented(ip); \
                    logged = true;                                                                                                    \
                }                                                                                                                     \
            } while (0)
    #endif
#else
    #define MATCH_FUNC(addr)
    #define STUB_FUNC(addr)
    #define EXPORT
    #define EXPORT_VAR
    #define NOT_IMPLEMENTED
    #define __stdcall
#endif

#if defined(_MSC_VER)
    #if _MSC_VER > 1200
        #define GTA2_ASSERT_SIZEOF_ALWAYS(structureName, expectedSize) \
            static_assert(sizeof(structureName) == expectedSize, "sizeof(" #structureName ") must be " #expectedSize);
    #else
        #define GTA2_ASSERT_SIZEOF_ALWAYS(structureName, expectedSize) \
            typedef int static_assert_##structureName[sizeof(structureName) == expectedSize ? 1 : -1];
    #endif
#else
    #define GTA2_ASSERT_SIZEOF_ALWAYS(structureName, expectedSize) \
        static_assert(sizeof(structureName) == expectedSize, "sizeof(" #structureName ") must be " #expectedSize);
#endif

#define GTA2_COUNTOF(x) (sizeof(x) / sizeof(*(x)))
#define GTA2_COUNTOF_S(x) ((s32)GTA2_COUNTOF(x))

#define GTA2_DELETE_AND_NULL(x) \
    delete x;                   \
    x = 0;
