#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "ID_EX_buffer.h"
#include "ID_stage.h"

using namespace std;

ID_EX_buffer::ID_EX_buffer(){
	op = 0;
	rs = 0;
	rt = 0;
	rd = 0;
	shamt = 0;
	funct = 0;
	address = 0;
	immediate = 0;
	Rs = 0;
	Rt = 0;
	Rd = 0;
	Reg_address = 0;
}

void ID_EX_buffer::getFromIDStage(ID_stage ids){
	op = ids.op;
	rs = ids.rs;
	rt = ids.rt;
	rd = ids.op;
	shamt = ids.shamt;
	funct = ids.funct;
	address = ids.address;
	immediate = ids.immediate;
	Rs = ids.Rs;
	Rt = ids.Rt;
	Rd = ids.Rd;
	PC = ids.PC;
	Reg_address = ids.Reg_address;
	printf("REGADD = %d\n", Reg_address);
	inststr = ids.inststr;
	isBranch = ids.isBranch;
	isNOP = ids.isNextNOP;
	isStall = ids.isStall;
	isHalt = ids.isHalt;
}
