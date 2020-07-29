/* 
    Key Concepts for buffering memory blocks
*/
#include "buffer_engine.h"
#include "buffer_.h"
#include <stdlib.h>
#include <stdio.h>

buffer_info* setup_buffer_info() {
    buffer_info* buffer_info = calloc(
        1,
        sizeof(struct BUFFER_INFO)
    );

    buffer_info->current_buffer_block = (void*)0;
    buffer_info->current_buffer_array = (void*)0;
    buffer_info->array_size = 0;
    buffer_info->current_buffer_block = 0;

    return buffer_info;
}

buffer_info* update_buffer_info(buffer_info* buffer_, buffer_ptr_array* buffer_array, buffer_setup* buffer_block) {

    buffer_->current_buffer_block = buffer_block;
    buffer_->current_buffer_array = buffer_array;
    buffer_->array_size = buffer_block->current_ammount_of_elements;
    buffer_->block_allocation_size = buffer_block->current_memory_buffer_size;

    /* buffer_setup struct will be used everytime we buffer a new block of memory(or a new ptr) */
    free_buffer_block(buffer_block);

    return buffer_;
}

buffer_info* buffer_calloc(void* ptr, int ammount_of_elements, size_t allocation_size, buffer_info* buffer_info, buffer_ptr_array* buffer_array) {

    CALLOC_buffer_new_block(ptr, buffer_array, ammount_of_elements, allocation_size);

    return buffer_info;
}