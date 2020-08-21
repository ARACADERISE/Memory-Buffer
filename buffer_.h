#ifndef BUFFER_
#define BUFFER_

#include <stddef.h>

typedef struct BUFFER_SETUP_STRUCT {
    size_t current_memory_buffer_size; // sizes of each, including the buffer_setup struct
    size_t current_amount_of_elements; // elements to be buffered
    void* struct_ptr;
} buffer_setup;

typedef struct BUFFER_ARRAY {
    int index;
    void** ptrs;
    size_t* sizes;
    size_t amount_of_elements;
    size_t BUFFER_ARRAY_SIZE; // keeping all sizes..including the recent struct in use
} buffer_ptr_array;

void* free_buffer_block(void* ptr);
buffer_setup* setup_buffer_block();
buffer_ptr_array* setup_strict_allocations(buffer_ptr_array* buffer_array);
buffer_ptr_array* setup_buffer_ptr_array(buffer_setup* buffer_block);
buffer_ptr_array* CALLOC_buffer_new_block(void* ptr, buffer_ptr_array* buffer_array, size_t amount_of_elements,size_t allocation_size);
//buffer_ptr_array* add_buffer_block(buffer_setup* buffer_block, buffer_ptr_array* buffer_array);

#endif