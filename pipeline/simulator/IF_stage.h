#ifndef LAB2_IF_STAGE_H
#define LAB2_IF_STAGE_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include "ID&EX_buffer.h"

class IF_stage{

public:

	unsigned int readInstruction(unsigned int *PC, unsigned int I_memory[], ID&EX_buffer ieb);
	
	unsigned int instruction;
	unsigned int newPC;
	bool isNOP = true;
	bool isNextNOP = true;
	bool isFlush = false;
	bool isHalt = false;
};

#endif LAB2_IF_STAGE_H