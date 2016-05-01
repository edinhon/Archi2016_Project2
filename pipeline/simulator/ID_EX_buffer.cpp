#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <String>
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
	this.op = ids.op;
	this.rs = ids.rs;
	this.rt = ids.rt;
	this.rd = ids.op;
	this.shamt = ids.op;
	this.funct = ids.op;
	this.address = ids.op;
	this.immediate = ids.op;
	this.Rs = ids.op;
	this.Rt = ids.op;
	this.Rd = ids.op;
	this.PC = ids.PC;
	this.Reg_address = ids.Reg_address;
	this.inststr = ids.inststr;
	isBranch = ids.isBranch;
	isNOP = ids.isNextNOP;
	isStall = ids.isStall;
	isHalt = ids.isHalt;
}