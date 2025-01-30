#ifndef memalloc
#define memalloc

typedef unsigned int size_t;  
typedef void* ptr;             
static char memory_pool[1024]; 
static size_t next_free = 0; 
void* my_malloc(size_t size) {
    if (next_free + size > sizeof(memory_pool)) {
        return (void*)0; 
    }
    void* allocated_memory = (void*)(memory_pool + next_free);
    next_free += size;
    return allocated_memory;
}
void my_free(void* ptr) {   
}
void* my_calloc(size_t num, size_t size) {
    size_t total_size = num * size;
    void* allocated_memory = my_malloc(total_size);
    if (allocated_memory) {
        for (size_t i = 0; i < total_size; i++) {
            ((char*)allocated_memory)[i] = 0;
        }
    }
    return allocated_memory;
}
void* my_realloc(void* ptr, size_t new_size) {
    if (!ptr) {
        return my_malloc(new_size); 
    }
    void* new_memory = my_malloc(new_size);
    if (new_memory) { 
        size_t old_size = next_free - (size_t)ptr; 
        for (size_t i = 0; i < old_size && i < new_size; i++) {
            ((char*)new_memory)[i] = ((char*)ptr)[i];
        }
        my_free(ptr);
    }
    return new_memory;
}
#endif
