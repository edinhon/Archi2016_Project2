#ifndef LAB2_ID&EX_BUFFER_H
#define LAB2_ID&EX_BUFFER_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include "ID_stage.h"

class ID&EX_buffer{

public:

    ID&EX_buffer();
	
	void getFromIDStage(ID_stage ids);

	unsigned int op, rs, rt, rd, shamt, funct, address;
	int immediate;
	int Rs, Rt, Rd;
	unsigned int PC;
	bool isBranch = false;
	bool isNOP = true, isHalt = false;
};

#endif LAB2_ID&EX_BUFFER_H