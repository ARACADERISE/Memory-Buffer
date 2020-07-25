/*
    Memory Buffer for malloc,calloc,realloc and free
    
    Memory Buffer:
        Buffer the memory to the best of it's ability.
        Buffering the memory means it cuts memory allocations down very strictly,
        if not nearly releasing all of it, to prevent memory leaks.
        This is done by storing pointers of which the user is using in an array of pointers
        being used, as well as storing each allocation of each pointer in another array.
        De-Allocations will take place as each pointer is used, and after so each memory block
        will have a strict memory allocations block(malloc) allocated to it.
        At the very end, each pointer will witness a buffer_destory method destroying each pointers
        allocation as well as releasing(destroying) the pointer itself.
*/
#include <stdio.h>
#include <stdlib.h> 
#include "buffer_.h"
#include "buffer_engine.h"

int main(int argc, char *args[]) {
    buffer_setup* buffer_block = setup_buffer_block();
    buffer_ptr_array* buffer_array = setup_buffer_ptr_array(buffer_block);
}