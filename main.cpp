#include <iostream>
#include <cstring>
#include <new>

struct Allocator { 
    char maxMemory[4096];
    char* current = maxMemory;
};

struct Chunk {
    size_t size;
    Chunk* next;

};

Allocator data;

char* my_malloc(size_t size) { 
    if (data.current + sizeof(Chunk) + size <= data.maxMemory + sizeof(data.maxMemory)) {        
        Chunk* dataChunk = reinterpret_cast<Chunk*>(data.current);
        dataChunk->size = size;
        data.current += sizeof(Chunk) + size;

        return data.current;
    } else {
        throw std::bad_alloc();
    }
 }


int main(int argc, char** argv) {

    std::cout << my_malloc(100);
    return 0;
}