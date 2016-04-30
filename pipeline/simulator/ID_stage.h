#ifndef LAB2_ID_STAGE_H
#define LAB2_ID_STAGE_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include "IF&ID_buffer.h"

class ID_stage{

public:

    ID_stage();
	
	void decode(int Register[], IF&ID_buffer iib);

	unsigned int op, rs, rt, rd, shamt, funct, address;
	int immediate;
	int Rs, Rt, Rd;
	unsigned int PC;
	bool isBranch = false;
	bool isNOP = true;
	bool isHalt = false;
};

#endif LAB2_ID_STAGE_H