#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "IF_ID_buffer.h"
#include "IF_stage.h"

using namespace std;

IF_ID_buffer::IF_ID_buffer(){

	instructionBuffer = 0;
}

void IF_ID_buffer::getFromIFStage(IF_stage ifs){

	if(ifs.isStall == false){
		instructionBuffer = ifs.instruction;
	}
    isNOP = ifs.isNextNOP;
    isHalt = ifs.isHalt;
}
