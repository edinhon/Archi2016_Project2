#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "IF_stage.h"
#include "ID_stage.h"

using namespace std;

unsigned int IF_stage::readInstruction(unsigned int *PC, unsigned int I_memory[], ID_stage ids){
	
	if(ids.isBranch == true){
		*PC = ids.PC;
	}
	else{
		*PC += 1;
	}
	
	instruction = I_memory[*PC];
	
	if(instruction == 0x00000000) isNOP = true;
	else isNOP = false;
	
	if((instructionBuffer >> 26) == 0x3F) isHalt = true;
	
	return instruction;
}
