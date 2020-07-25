#include "buffer_.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* free_buffer_block(void* ptr) {
    free(ptr);
    ptr = (void*)0;

    return ptr;
}

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

    /* buffer_setup struct will be used everytime we buffer a new block of memory(or a new ptr) */
    free_buffer_block(buffer_block);

    buffer_array->index++;

    return buffer_array;
}

buffer_ptr_array* add_buffer_block(buffer_setup* buffer_block, buffer_ptr_array* buffer_array) {

    buffer_array->ammount_of_elements = buffer_block->current_ammount_of_elements;
    buffer_array->ptrs = realloc(
        buffer_array->ptrs,
        buffer_array->ammount_of_elements
    );
    buffer_array->sizes = realloc(
        buffer_array->sizes,
        buffer_array->ammount_of_elements
    );

    buffer_array->ptrs[buffer_array->index] = buffer_block;
    buffer_array->sizes[buffer_array->index] = buffer_block->current_memory_buffer_size;

    free_buffer_block(buffer_block);

    return buffer_array;
}
buffer_ptr_array* CALLOC_buffer_new_block(void* ptr, buffer_ptr_array* buffer_array, int ammount_of_elements,size_t allocation_size) {
    buffer_setup* buffer_block = calloc(1,sizeof(struct BUFFER_SETUP_STRUCT));

    ptr = calloc(
        ammount_of_elements,
        allocation_size
    );

    buffer_block->current_memory_buffer_size = ammount_of_elements*allocation_size;
    buffer_block->current_ammount_of_elements = buffer_array->ammount_of_elements++;
    buffer_block->struct_ptr = ptr;

    return add_buffer_block(buffer_block,buffer_array);
}

buffer_ptr_array* setup_strict_allocations(buffer_ptr_array* buffer_array) {

    return buffer_array;
}