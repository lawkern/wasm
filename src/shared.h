/* (c) copyright 2025 Lawrence D. Kern ////////////////////////////////////// */

#include <assert.h>
#include <stdio.h>

#include <stdint.h>
typedef uint8_t u8;
typedef uint32_t u32;

typedef int8_t s8;
typedef int32_t s32;

#include <stddef.h>
typedef ptrdiff_t memindex;

#define countof(a) (sizeof(a) / sizeof((a)[0]))

u8 magic[] = {0x00, 'a', 's', 'm'};
u8 version[] = {0x01, 0x00, 0x00, 0x00};

typedef struct {
   memindex length;
   u8 data[1024];
} bytecode_stream;
