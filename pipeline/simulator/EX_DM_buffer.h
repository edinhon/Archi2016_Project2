#ifndef LAB2_EX_DM_BUFFER_H
#define LAB2_EX_DM_BUFFER_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <string>
#include "EX_stage.h"

using namespace std;

class EX_DM_buffer{

public:

    EX_DM_buffer();

	void getFromEXStage(EX_stage exs);

	unsigned int PC;
	int Reg_value, Data_value[4];
	unsigned int Reg_address, Data_address;
	int oldReg_value;
	unsigned int oldReg_address;
	unsigned int op;
	unsigned int oldop;
	string inststr, oldinststr;
	bool isNOP = true, isHalt = false;
};

#endif //LAB2_EX_DM_buffer_H
