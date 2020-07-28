#ifndef BUFFER_ENGINE
#define BUFFER_ENGINE
#include "buffer_.h"

typedef struct BUFFER_INFO {
    buffer_setup* current_buffer_block;
    buffer_ptr_array* current_buffer_array;
    size_t array_size; // ammount of elements
    size_t block_allocation_size; // size of current block
} buffer_info;

buffer_info* setup_buffer_info();
buffer_info* update_buffer_info(buffer_info* buffer_, buffer_ptr_array* buffer_array, buffer_setup* buffer_block);
buffer_info* buffer_calloc(buffer_info* buffer_info,buffer_setup* buffer_block, buffer_ptr_array* buffer_array);

#endif