#ifndef LAB2_IF_STAGE_H
#define LAB2_IF_STAGE_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include "IF&ID_buffer.h"
#include "ID&EX_buffer.h"

class IF_stage{

public:

	unsigned int readInstruction(unsigned int *PC, unsigned int I_memory[], IF&ID_buffer iib, ID&EX_buffer ieb);
	
	unsigned int instruction;
	bool isNOP = true;
	bool isHalt = false;
	bool isStall = false;
};

#endif LAB2_IF_STAGE_H