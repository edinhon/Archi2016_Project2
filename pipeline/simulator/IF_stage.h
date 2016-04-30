#ifndef LAB2_IF_STAGE_H
#define LAB2_IF_STAGE_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include "ID_stage.h"

class IF_stage{

public:

	unsigned int readInstruction(unsigned int *PC, unsigned int I_memory[], ID_stage ids);
	
	unsigned int instruction;
	bool isNOP = true;
	bool isHalt = false;
};

#endif LAB2_IF_STAGE_H