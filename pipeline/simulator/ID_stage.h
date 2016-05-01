#ifndef LAB2_ID_STAGE_H
#define LAB2_ID_STAGE_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <String>
#include "IF&ID_buffer.h"
#include "ID&EX_buffer.h"
#include "EX&DM_buffer.h"
#include "DM&WB_buffer.h"

using namespace std;

class ID_stage{

public:

    ID_stage();
	
	void decode(int Register[], IF&ID_buffer iib, ID&EX_buffer ieb, EX&DM_buffer edb, DM&WB_buffer dwb);

	unsigned int op, rs, rt, rd, shamt, funct, address;
	int immediate;
	int Rs, Rt, Rd;
	unsigned int Reg_address;
	unsigned int PC;
	String inststr;
	bool isBranch = false;
	bool isNOP = true;
	bool isNextNOP = true;
	bool isStall = false;
	bool isHalt = false;
	bool isrsForwarding = false, isrtForwarding = false;
};

#endif LAB2_ID_STAGE_H