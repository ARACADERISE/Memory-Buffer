#ifndef BUFFER_ENGINE
#define BUFFER_ENGINE
#include "buffer_.h"

typedef struct BUFFER_INFO {
    buffer_setup* current_buffer_block;
    buffer_ptr_array* current_buffer_array;
    size_t array_size; // ammount of elements
    size_t block_allocation_size; // size of current block
    struct REMOTE_ALLOCATE {
        buffer_setup* remote_buffer_block;
        size_t remote_size;
        size_t remote_ammount;
    } *REMOTE_ALLOCATION;
} buffer_info;

buffer_info* setup_buffer_info();
buffer_info* update_buffer_info(buffer_info* buffer_, buffer_ptr_array* buffer_array, buffer_setup* buffer_block);
void* buffer_calloc(void* ptr, int amount_of_elements, size_t allocation_size, buffer_info* buffer_info, buffer_ptr_array* buffer_array);
void* remote_buffer_calloc(void* ptr,size_t amount_of_elements, size_t size);

#define BUFFER_ASSERT(size, against) (((size & against) == size) ? 0 : 1)
#define BUFFER_ASSERT_AND_RECORRECT(from,to) ( (BUFFER_ASSERT(((to-from)+from), to)) ? to: (to-from)+from )

#endif