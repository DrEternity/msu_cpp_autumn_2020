#ifndef ALLOCATOR_H_
#define ALLOCATOR_H_


class Allocator
{
private:
    char * pointer_to_beginning = nullptr;
    size_t size_memory = 0;
    int offset = 0;
public:
    void makeAllocator(size_t maxSize);
    char* alloc(size_t size);
    void reset();
    ~Allocator();
};


#endif /* ALLOCATOR_H_ */
