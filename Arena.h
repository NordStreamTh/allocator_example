#ifndef ARENA_H
#define ARENA_H

class Arena {
private:
    char maxMemory[300];
    char* current;

public:
    Arena();
    ~Arena();
};

#endif