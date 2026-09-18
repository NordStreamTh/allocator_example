#ifndef ARENA_H
#define ARENA_H

class Arena {
private:
    char maxMemory[300];
    char* current;

public:
    Arena();

    bool hasSpace(size_t size) const;
    char* allocate (size_t size);
    ~Arena();
};

#endif