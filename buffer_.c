#include "buffer_.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

buffer_setup* setup_buffer_block() {
    buffer_setup* buffer_block = calloc(1,sizeof(struct BUFFER_SETUP_STRUCT));

    buffer_block->current_memory_buffer_size = (
        sizeof(buffer_block)*3
    );
    buffer_block->current_ammount_of_elements = 1;
    buffer_block->struct_ptr = ((buffer_setup*)buffer_block);

    return buffer_block;
}

buffer_ptr_array* setup_buffer_ptr_array(buffer_setup* buffer_block) {
    buffer_ptr_array* buffer_array = calloc(1,sizeof(struct BUFFER_ARRAY));
    buffer_array->index = 0;

    buffer_array->ptrs = calloc(
        buffer_block->current_ammount_of_elements,
        sizeof(buffer_array->ptrs)
    );
    buffer_array->sizes = calloc(
        buffer_block->current_ammount_of_elements,
        sizeof(size_t)
    );
    buffer_array->ammount_of_elements = buffer_block->current_ammount_of_elements;
    buffer_array->BUFFER_ARRAY_SIZE = (
        sizeof(buffer_array)*4
    );

    /* The buffer_block struct is the first ptr */
    buffer_array->ptrs[buffer_array->index] = ((buffer_setup*)buffer_block);
    buffer_array->sizes[buffer_array->index] = buffer_block->current_memory_buffer_size;

    free(buffer_block);
    buffer_block = (void*)0;

    return buffer_array;
}