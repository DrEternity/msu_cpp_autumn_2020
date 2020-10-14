#include <iostream>
#include "Allocator.h"
#include <cassert>
void test_0()
{
    Allocator exp;
    exp.makeAllocator(50);
    assert(exp.result_of_last_request == 0);
    exp.makeAllocator(50);
    assert(exp.result_of_last_request == 1);
    exp.makeAllocator(1000);
    assert(exp.result_of_last_request == 1);

}
void test_1()
{
    char *p;
    Allocator exp;
    exp.makeAllocator(50);
    assert(exp.result_of_last_request == 0);
    p = exp.alloc(20);
    assert(p != nullptr);
    p = exp.alloc(20);
    assert(p != nullptr);
    p = exp.alloc(10);
    assert(p != nullptr);
    p = exp.alloc(1);
    assert(p == nullptr);
}
void test_2()
{
    char *p;
    Allocator exp;
    exp.makeAllocator(50);
    assert(exp.result_of_last_request == 0);
    p = exp.alloc(50);
    assert(p != nullptr);
    exp.reset();
    p = exp.alloc(20);
    assert(p != nullptr);
    p = exp.alloc(23);
    assert(p != nullptr);
    p = exp.alloc(8);
    assert(p == nullptr);
}
void test_3()
{
    char *p;
    Allocator exp;
    exp.makeAllocator(500);
    assert(exp.result_of_last_request == 0);
    p = exp.alloc(1);
    assert(p != nullptr);
    exp.reset();
    p = exp.alloc(370);
    assert(p != nullptr);
    p = exp.alloc(120);
    assert(p != nullptr);
    p = exp.alloc(10);
    assert(p != nullptr);
    p = exp.alloc(10);
    assert(p == nullptr);
}
void test_4()
{
    char *p;
    Allocator exp;
    exp.makeAllocator(1000);
    assert(exp.result_of_last_request == 0);
    p = exp.alloc(372);
    assert(p != nullptr);
    exp.reset();
    p = exp.alloc(999);
    assert(p != nullptr);
    exp.reset();
    p = exp.alloc(124);
    assert(p != nullptr);
    p = exp.alloc(100);
    assert(p != nullptr);
    p = exp.alloc(111);
    assert(p != nullptr);
}
int main()
{
    test_0();
    test_1();
    test_2();
    test_3();
    test_4();
    return 0;
}
