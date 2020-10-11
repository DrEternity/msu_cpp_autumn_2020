#include<iostream>
#include<fstream>
#include<cassert>
std::ifstream fin("test.txt");
class Allocator
{
private:
    char * pointer_to_beginning = nullptr;
    size_t size_memory = 0;
    int offset = 0;
public:
    void makeAllocator(size_t maxSize)
    {
        if(pointer_to_beginning != nullptr)
        {
            std::cout << "Error! This object already has allocated memory\n";
            return;
        }
        pointer_to_beginning = new char[maxSize];
        if(pointer_to_beginning == nullptr)
        {
            std::cout << "Error! OS doesn't have enough memory\n";
            return;
        }
        size_memory = maxSize;
    }
    char* alloc(size_t size)
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
    void reset()
    {
        offset = 0;
    }
    ~Allocator()
    {
        delete[] pointer_to_beginning;
    }
};
void test_class(Allocator &test)
{
    short q;
    fin >> q;
    // 0 - makeAllocator
    // 1 - alloc
    // 2 - reset
    while(q--)
    {
        short num_of_req;
        fin >> num_of_req;
        if(num_of_req == 0)
        {
            size_t maxSize;
            fin >> maxSize;
            test.makeAllocator(maxSize);
        }
        if(num_of_req == 1)
        {
            size_t size;
            fin >> size;
            char *p = test.alloc(size);
            if(p == nullptr)
            {
                std::cout << "memory overflow\n";
            }else
            {
                std::cout << "memory was allocated\n";
            }
        }
        if(num_of_req == 2)
        {
            test.reset();
            std::cout << "the memory was released\n";
        }
    }
}
int main()
{
    Allocator test;
    test_class(test);
    fin.close();
    return 0;
}
