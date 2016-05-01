#ifndef LAB2_ID_EX_BUFFER_H
#define LAB2_ID_EX_BUFFER_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <String>
#include "ID_stage.h"

using namespace std;

class ID_EX_buffer{

public:

    ID_EX_buffer();
	
	void getFromIDStage(ID_stage ids);

	unsigned int op, rs, rt, rd, shamt, funct, address;
	int immediate;
	int Rs, Rt, Rd;
	unsigned int Reg_address;
	unsigned int PC;
	String inststr;
	bool isBranch = false;
	bool isStall = false;
	bool isNOP = true, isHalt = false;
};

#endif LAB2_ID_EX_BUFFER_H