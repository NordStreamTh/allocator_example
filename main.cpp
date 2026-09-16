#include <iostream>
#include <cstring>
#include <new>

struct Arena { 
    char maxMemory[300];
    char* current = maxMemory;
};

struct Chunk {
    size_t size;
    Chunk* next;
    bool free;
};

Arena data;

char* my_malloc(size_t size) { 
    if (data.current + sizeof(Chunk) + size <= data.maxMemory + sizeof(data.maxMemory)) {        
        Chunk* dataChunk = reinterpret_cast<Chunk*>(data.current);
        dataChunk->size = size;
        char* dataPtr = reinterpret_cast<char*>(dataChunk + 1);
        data.current += sizeof(Chunk) + size;    

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

char* my_free(char* str) {
    return 0;
}

int main(int argc, char** argv) {   
    std::cout << my_malloc(parsePtr(argv[1])) << std::endl;
    return 0;
}