#include "kernel.h"
#include <stdint.h>
#include <stddef.h>

uint16_t* video_mem = 0;
uint16_t row = 0;
uint16_t col = 0;

uint16_t make_char(char c, char color){
    return (color << 8) | c;
}

void putchar( int x, int y, char c, char color ){
    video_mem[ (y * VGA_WIDTH) + x ] = make_char(c, color);

}

void write_char(char c, char color){

    if(c == '\n'){
        col = 0;
        row++;
        return;
    
    }

    putchar(col, row, c, color);
    col++;
    if(col >= VGA_WIDTH){
        col = 0;
        row++;
    }

}


void initialize_vga(){

    video_mem = (uint16_t*)(0xB8000);
    row = 0; col = 0;
    for(int y=0; y < VGA_HEIGHT; y++){

        for(int x=0; x < VGA_WIDTH; x++){

            putchar(x, y, ' ', 0);
        
        }
    }
}

size_t strlen( const char* str){
    size_t len=0;
    while(str[len]){
        len++;
    
    }

    return len;
        
}




void kernel_main()
{
    char msg[] = "\n Hello and Welcome to my OS!\n\n This is a simple VGA driver";
    initialize_vga();
    for(int i=0; i< sizeof(msg)/sizeof(msg[0]) ; i++){

        write_char(msg[i], 4);

    }


}