#include "kernel.h"

void kernel_main()
{
    char* video_mem = (char*)(0xB8000);
    char msg[12] = "Hello World!";

    for(int i=0; i<12; i++){

        video_mem[2*i] = msg[i];
        video_mem[2*i+1] = 2;

    }


}   