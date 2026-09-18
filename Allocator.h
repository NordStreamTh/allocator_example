#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <cstddef>
#include <Arena.h>

struct Chunk { 
    size_t size;
    Chunk* next;
    bool free;
};

class Allocator { 
    private:
        Arena arena;
        Chunk* first;
    public: 
        Allocator();
        ~Allocator();

        char* malloc(size_t size);
        void free(char* ptr);
};


#endif