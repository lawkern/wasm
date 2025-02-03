/* (c) copyright 2025 Lawrence D. Kern ////////////////////////////////////// */

#include <stdio.h>

#include <stdint.h>
typedef uint8_t u8;

#include <stddef.h>
typedef ptrdiff_t memindex;

#define countof(a) (sizeof(a) / sizeof((a)[0]))

void output_wasm(u8 *bytecode, memindex length, char *name)
{
   FILE *file = fopen(name, "wb");
   if(file)
   {
      if(fwrite(bytecode, sizeof(*bytecode), length, file) != length)
      {
         fprintf(stderr, "ERROR: Failed to write the entirety of the bytecode.\n");
      }
      fclose(file);
   }
}

int main(void)
{
   u8 bytecode[] = {0, 'a', 's', 'm', 1, 0, 0, 0};
   output_wasm(bytecode, countof(bytecode), "index.wasm");

   return(0);
}
