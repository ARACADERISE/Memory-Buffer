#ifndef BUFFER_ /* 
    BUFFERS_VOID is just a nickname for the applications beginning steps.
    With buffer_.h, BUFFERS_VOID is a symbol that there is no memory buffering going on yet,
    and that memory allocations for future buffering is happening with the structs/sturct arrays,
    so take no actions with memory buffering yet until BUFFERS_VOID is undefined and BUFFER is defined
*/
#define BUFFER_

#include <stddef.h>

typedef struct BUFFER_SETUP_STRUCT {
    size_t current_memory_buffer_size; // sizes of each, including the buffer_setup struct
    size_t current_ammount_of_elements; // elements to be buffered
    void* struct_ptr;
} buffer_setup;

typedef struct BUFFER_ARRAY {
    int index;
    void** ptrs;
    size_t* sizes;
    size_t ammount_of_elements;
    size_t BUFFER_ARRAY_SIZE; // keeping all sizes..including the recent struct in use
} buffer_ptr_array;

buffer_setup* setup_buffer_block();
buffer_ptr_array* setup_strict_allocations(buffer_ptr_array* buffer_array);
buffer_ptr_array* setup_buffer_ptr_array(buffer_setup* buffer_block);

#endif