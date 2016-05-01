#ifndef LAB2_IF_ID_BUFFER_H
#define LAB2_IF_ID_BUFFER_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include "IF_stage.h"

class IF_stage;

class IF_ID_buffer{

public:

    IF_ID_buffer();

	void getFromIFStage(IF_stage ifs);

	unsigned int instructionBuffer, PC;
	bool isNOP = true;
	bool isHalt = false;
};

#endif //LAB2_IF_ID_BUFFER_H
