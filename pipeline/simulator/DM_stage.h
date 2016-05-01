#ifndef LAB2_DM_STAGE_H
#define LAB2_DM_STAGE_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include "EX&DM_buffer.h"

class DM_stage{

public:

    DM_stage();
	
	void writeToData(EX&DM_buffer edb, char Memory[]);

	unsigned int PC;
	int Reg_value, Data_value[4]
	unsigned int Reg_address, Data_address;
	unsigned int op;
	bool isNOP = true, isHalt = false;
};

#endif LAB2_DM_STAGE_H