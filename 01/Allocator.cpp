#include <iostream>
#include "Allocator.h"


void Allocator::makeAllocator(size_t maxSize)
{
    pointer_to_beginning = new char[maxSize];
    size_memory = maxSize;
}


char* Allocator::alloc(size_t size)
{
    if(offset + size > size_memory)
    {
        return nullptr;
    }else
    {
        offset += size;
        return pointer_to_beginning + (offset - size);
    }
}


void Allocator::reset()
{
    offset = 0;
}


Allocator::~Allocator()
{
    delete[] pointer_to_beginning;
}
