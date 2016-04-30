#ifndef LAB2_IF&ID_BUFFER_H
#define LAB2_IF&ID_BUFFER_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include "IF_stage.h"

class IF&ID_buffer{

public:

    IF&ID_buffer();
	
	void getFromIFStage(IF_stage ifs);

	unsigned int instructionBuffer, PC;
	bool isNOP = true;
	bool isHalt = false;
};

#endif LAB2_IF&ID_BUFFER_H