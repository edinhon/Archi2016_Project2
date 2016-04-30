#ifndef LAB2_DM&WB_BUFFER_H
#define LAB2_DM&WB_BUFFER_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include "DM_stage.h"

class DM&WB_buffer{

public:

    DM&WB_buffer();
	
	void getFromDMStage(DM_stage dms);

	unsigned int PC;
	unsigned int Reg_value, Reg_address;
	unsigned int op;
	bool isNOP = true, isHalt = false;
};

#endif LAB2_DM&WB_buffer_H