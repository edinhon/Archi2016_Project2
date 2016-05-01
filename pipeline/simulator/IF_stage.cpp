#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "IF_stage.h"
#include "IF&ID_buffer.h"
#include "ID&EX_buffer.h"

using namespace std;

unsigned int IF_stage::readInstruction(unsigned int *PC, unsigned int I_memory[], IF&ID_buffer iib, ID&EX_buffer ieb){
	
	unsigned int op, rs, rt;
	unsigned int oldPC = *PC;
	
	if(isStall == true){
		*PC = *PC;
		isStall = false;
	}
	else if(iib.isBranch == true){
		*PC = iib.PC;
	}
	else{
		*PC += 1;
	}
	
	instruction = I_memory[*PC];
	op = instruction >> 26;
	//if this instruction need to stall, hold PC in next cycle
	if(ieb.op == 0x23 || ieb.op == 0x21 || ieb.op == 0x25 || ieb.op == 0x20 || ieb.op == 0x24){
		rs = (instruction << 6);
		rs = (rs >> 27);
		rt = (instruction << 11);
		rt = (rt >> 27); 
		if(rs == ieb.rt || rt == ieb.rt){
			isStall = true;
		}
	}
	
	if(instruction == 0x00000000) isNOP = true;
	else isNOP = false;
	
	if(op == 0x3F) isHalt = true;
	
	return instruction;
}
