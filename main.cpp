#include <iostream>
#include <cstring>
#include <new>
#include <Allocator.h>

struct Chunk {
    size_t size;
    bool free;
};

class Arena {
private:
    char maxMemory[300];
    char* current;

public:
    Arena();
};



char* my_malloc(size_t size) { 
    if (data.current + sizeof(Chunk) + size <= data.maxMemory + sizeof(data.maxMemory)) {        
        Chunk* dataChunk = reinterpret_cast<Chunk*>(data.current);
        dataChunk->size = size;
        char* dataPtr = reinterpret_cast<char*>(dataChunk + 1);
        data.current += sizeof(Chunk) + size;    
        dataChunk->free = false;

        return dataPtr;

    } else {
        throw std::bad_alloc();
    }
}

bool my_isspace(const char* str) {
    if (*str == ' '  ||
        *str == '\t' ||
        *str == '\n' ||
        *str == '\r' ||
        *str == '\v' ||
        *str == '\f') 
        {
        return true;
    } else { 
        return false;
    }
}

int parsePtr(const char* str) {
    int result = 0;

    while (*str != '\0') {
        if (my_isspace(str)) { 
            str++;
        }
        else { 
            if (*str < '0' || *str > '9') {
                throw std::invalid_argument("Invalid number");
            } else { 
                int digit = *str - '0';
                result = result * 10 + digit;
                str++;
            }
        }
    }

    return result;
}

void my_free(char* ptr)
{
    if (ptr == nullptr)
        return;

    Chunk* chunk = reinterpret_cast<Chunk*>(ptr) - 1;

    char* begin = reinterpret_cast<char*>(chunk + 1);
    char* end = begin + chunk->size;

    while (begin < end) {
        *begin = 0;
        ++begin;
    }

    chunk->free = true;
}

#include "Allocator.h"
#include <iostream>

int main()
{
    Allocator allocator;

    char* ptr = allocator.malloc(50);

    allocator.free(ptr);

    return 0;
}