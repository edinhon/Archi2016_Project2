#ifndef LAB2_DM_WB_BUFFER_H
#define LAB2_DM_WB_BUFFER_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <String>
#include "DM_stage.h"

using namespace std;

class DM_WB_buffer{

public:

    DM_WB_buffer();
	
	void getFromDMStage(DM_stage dms);

	unsigned int PC;
	unsigned int Reg_value, Reg_address;
	unsigned int op;
	String inststr;
	bool isNOP = true, isHalt = false;
};

#endif LAB2_DM_WB_buffer_H