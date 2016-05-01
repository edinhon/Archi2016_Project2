#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "IF_stage.h"
#include "ID&EX_buffer.h"

using namespace std;

unsigned int IF_stage::readInstruction(unsigned int *PC, unsigned int I_memory[], ID&EX_buffer ieb){
	
	unsigned int op, rs, rt;
	isNOP = false;
	isNextNOP = false;
	isStall = false;
	isFlush = false;
	
	*PC = newPC;
	instruction = I_memory[*PC];
	op = instruction >> 26;
	
	if(instruction == 0x00000000) {
		isNOP = true;
		isNextNOP = true;
	}
	else isNOP = false;
	
	if(op == 0x3F) isHalt = true;
	
	if(ieb.isStall){
		newPC = *PC;
		isStall = true;
	}
	else if(ieb.Branch){
		newPC = ieb.PC;
		isNextNOP = true;
		isFlush = true;
	}
	else newPC += 1;
	
	return instruction;
}
