#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "IF_stage.h"
#include "ID&EX_buffer.h"

using namespace std;

unsigned int IF_stage::readInstruction(unsigned int *PC, unsigned int I_memory[], ID&EX_buffer ieb){
	
	unsigned int op, rs, rt;
	unsigned int oldPC = *PC;
	
	//if need to stall, hold PC value
	if(ieb.isNOP == true){
		*PC = *PC;
	}
	else if(ieb.isBranch == true){
		*PC = ieb.PC;
	}
	else{
		*PC += 1;
	}
	
	instruction = I_memory[*PC];
	op = instruction >> 26;
	
	if(instruction == 0x00000000) isNOP = true;
	else isNOP = false;
	
	if(op == 0x3F) isHalt = true;
	
	return instruction;
}
