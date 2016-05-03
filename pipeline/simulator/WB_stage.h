#ifndef LAB2_WB_STAGE_H
#define LAB2_WB_STAGE_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <string>
#include "DM_WB_buffer.h"

using namespace std;

class WB_stage{

public:

    WB_stage();

	void writeToRegister(DM_WB_buffer dwb, int Register[]);

	unsigned int PC;
	unsigned int op;
	string inststr;
	bool isNOP = true, isHalt = false;
	bool error1 = false;
};

#endif//LAB2_WB_STAGE_H
