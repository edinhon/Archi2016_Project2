#ifndef LAB2_MEMORY_H
#define LAB2_MEMORY_H

#include<iostream>
#include<cstdio>
#include<cstdlib>

class memory{

public:

    memory();

    void readMemory(int *$sp);

    char D_memory[1024];
    //unsigned int $sp = 0x400;
    int times = 0;
};


#endif // LAB2_MEMORY_H