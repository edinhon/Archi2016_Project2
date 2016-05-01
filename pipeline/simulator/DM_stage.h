#ifndef LAB2_DM_STAGE_H
#define LAB2_DM_STAGE_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <string>
#include "EX_DM_buffer.h"

using namespace std;

class EX_DM_buffer;

class DM_stage{

public:

    DM_stage();

	void writeToData(EX_DM_buffer edb, char Memory[]);

	unsigned int PC;
	int Reg_value, Data_value[4];
	unsigned int Reg_address, Data_address;
	unsigned int op;
	string inststr;
	bool isNOP = true, isHalt = false;
};

#endif //LAB2_DM_STAGE_H
