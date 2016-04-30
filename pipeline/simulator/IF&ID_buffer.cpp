#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "IF&ID_buffer.h"
#include "IF_stage.h"

using namespace std;

IF&ID_buffer::IF&ID_buffer(){
	
	this.instructionBuffer = 0;
}

void IF&ID_buffer::getFromIFStage(IF_stage ifs){
	
	this.isNOP = ifs.isNOP;
	this.isHalt = ifs.isHalt;
	this.instructionbuffer = ifs.readInstruction;
}
