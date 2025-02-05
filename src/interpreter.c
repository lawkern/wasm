/* (c) copyright 2025 Lawrence D. Kern ////////////////////////////////////// */

#include "shared.h"

static void read_file(bytecode_stream *stream, char *path)
{
   FILE *file = fopen(path, "rb");
   if(file)
   {
      fseek(file, 0, SEEK_END);
      size_t size = ftell(file);
      fseek(file, 0, SEEK_SET);

      assert(size <= countof(stream->data));

      if(fread(stream->data, 1, size, file) == size)
      {
         stream->length = size;
      }
      else
      {
         fprintf(stderr, "ERROR: Failed to read %s\n", path);
      }

      fclose(file);
   }
   else
   {
      fprintf(stderr, "ERROR: Failed to find %s.\n", path);
   }
}

int main(void)
{
   bytecode_stream stream = {0};
   read_file(&stream, "./web/index.wasm");

   for(int index = 0; index < stream.length; ++index)
   {
      printf("0x%.2X ", stream.data[index]);
   }

   return(0);
}
