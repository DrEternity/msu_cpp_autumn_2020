#include <iostream>
#include <cassert>
#include "Allocator.h"


void Allocator::makeAllocator(size_t maxSize)
{
    if(pointer_to_beginning != nullptr)
    {
        result_of_last_request = 1;
        return;
    }
    pointer_to_beginning = new char[maxSize];
    size_memory = maxSize;
    result_of_last_request = 0;
    return;
}


char* Allocator::alloc(size_t size)
{
    if(offset + size > size_memory)
    {
        result_of_last_request = 1;
        return nullptr;
    }else
    {
        result_of_last_request = 0;
        offset += size;
        return pointer_to_beginning + (offset - size);
    }
}


void Allocator::reset()
{
    result_of_last_request = 0;
    offset = 0;
    return;
}


Allocator::~Allocator()
{
    delete[] pointer_to_beginning;
}

