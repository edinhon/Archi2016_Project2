#ifndef LAB2_IF_STAGE_H
#define LAB2_IF_STAGE_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include "ID_EX_buffer.h"

using namespace std;

class ID_EX_buffer;

class IF_stage{

public:

	unsigned int readInstruction(unsigned int *PC, unsigned int I_memory[], ID_EX_buffer ieb);

	unsigned int instruction;
	unsigned int newPC;
	bool isNOP = true;
	bool isNextNOP = true;
	bool isStall = false;
	bool isFlush = false;
	bool isHalt = false;
};

#endif //LAB2_IF_STAGE_H
