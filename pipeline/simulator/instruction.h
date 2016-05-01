#ifndef LAB2_INSTRUCTION_H
#define LAB2_INSTRUCTION_H

#include<iostream>
#include<cstdio>
#include<cstdlib>

class instruction{

public:

    instruction();

	void readInputData(unsigned int *PC);

	unsigned int I_memory[256] = {0};
	int times = 0;
};

#endif//LAB2_INSTRUCTION_H
