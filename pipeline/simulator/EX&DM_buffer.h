#ifndef LAB2_EX&DM_BUFFER_H
#define LAB2_EX&DM_BUFFER_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include "EX_stage.h"

class EX&DM_buffer{

public:

    EX&DM_buffer();
	
	void getFromEXStage(EX_stage exs);

	unsigned int PC;
	int Reg_value, Data_value[4];
	unsigned int Reg_address, Data_address;
	unsigned int op;
	bool isNOP = true, isHalt = false;
};

#endif LAB2_EX&DM_buffer_H