#include "memory.h"


void* memory_set(void *ptr, int c, size_t size){
    
    char* char_ptr = (char*) ptr;
    for(int i=0; i<size; i++) {
        char_ptr[i] = (char) c;
    };
    return ptr;

};
