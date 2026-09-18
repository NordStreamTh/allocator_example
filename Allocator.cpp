#include "Allocator.h"

Allocator::Allocator()
    : first(nullptr)
{
}

Allocator::~Allocator()
{
}

char* Allocator::malloc(size_t size)
{
    if (arena)
    return nullptr;
}

void Allocator::free(char* ptr)
{
    // TODO
}