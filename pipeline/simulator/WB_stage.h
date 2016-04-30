#ifndef LAB2_WB_STAGE_H
#define LAB2_WB_STAGE_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include "DM&WB_buffer.h"

class WB_stage{

public:

    WB_stage();
	
	void writeToRegister(DM&WB_buffer dwb, int Register[]);

	unsigned int PC;
	unsigned int op;
	bool isNOP = true, isHalt = false;
};

#endif LAB2_WB_STAGE_H