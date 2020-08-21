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
    buffer_->array_size = buffer_block->current_amount_of_elements;
    buffer_->block_allocation_size = buffer_block->current_memory_buffer_size;

    /* buffer_setup struct will be used everytime we buffer a new block of memory(or a new ptr) */
    free_buffer_block(buffer_block);

    return buffer_;
}

/*static buffer_setup* setup_new_buffer_info(size_t cur_mem_size, size_t cur_am_elem,void* strct_ptr) {
    buffer_setup* buffer_block = calloc(1,sizeof(buffer_setup));

    buffer_block->struct_ptr = strct_ptr;
    buffer_block->current_amount_of_elements = cur_am_elem;
    buffer_block->current_memory_buffer_size = cur_mem_size;

    return buffer_block;
}*/
static buffer_setup* setup_buffer_block_(size_t am_of_elem, size_t size, void* ptr) {
    buffer_setup* buffer_block = calloc(1,sizeof(buffer_block));

    buffer_block->current_amount_of_elements = am_of_elem;
    buffer_block->current_memory_buffer_size = size;
    buffer_block->struct_ptr = ptr;

    return buffer_block;
}

void* buffer_calloc(void* ptr, int amount_of_elements, size_t allocation_size, buffer_info* buffer_info, buffer_ptr_array* buffer_array) {

    // Allocating memory
    CALLOC_buffer_new_block(ptr, buffer_array, amount_of_elements, allocation_size);

    // We don't want to free the pointer, so we make a new buffer_block. This will be released in update_buffer_info
   buffer_setup* buffer_block = setup_buffer_block_(buffer_array->sizes[buffer_array->index-1], buffer_array->amount_of_elements, buffer_array->ptrs[buffer_array->index-1]);

    // Updating the buffer information
    update_buffer_info(buffer_info, buffer_array, buffer_block);

    return buffer_info;
}

/**/
void* remote_buffer_calloc(void* ptr,size_t amount_of_elements, size_t size) {
    buffer_info* buffer_info = calloc(1,sizeof(buffer_info));
    setup_buffer_block_(amount_of_elements, size, ptr);
    
    buffer_setup* buffer_block = calloc(1,sizeof(buffer_setup));
    setup_buffer_block_(amount_of_elements, size, ptr);
    buffer_ptr_array* buffer_array = calloc(1,sizeof(buffer_ptr_array*));

    buffer_block->current_amount_of_elements = amount_of_elements;
    buffer_block->struct_ptr = ptr;
    buffer_block->current_memory_buffer_size = size;

    CALLOC_buffer_new_block(ptr, buffer_array, amount_of_elements, size);

    buffer_info->REMOTE_ALLOCATION = calloc(1,sizeof(buffer_info->REMOTE_ALLOCATION));

    buffer_info->REMOTE_ALLOCATION->remote_buffer_block = buffer_block;
    buffer_info->REMOTE_ALLOCATION->remote_size = size;
    buffer_info->REMOTE_ALLOCATION->remote_ammount = buffer_info->REMOTE_ALLOCATION->remote_buffer_block->current_memory_buffer_size;

    return ptr;
}