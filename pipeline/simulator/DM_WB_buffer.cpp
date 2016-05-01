#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "DM_WB_buffer.h"
#include "DM_stage.h"

using namespace std;

DM_WB_buffer::DM_WB_buffer(){
	Reg_value = 0;
	Reg_address = 0;
	op = 0;
}
	
void DM_WB_buffer::getFromDMStage(DM_stage dms){
	this.Reg_value = dms.Reg_value;
	this.Reg_address = dms.Reg_address;
	this.op = dms.op;
	this.PC = dms.PC;
	this.inststr = dms.inststrl
	this.isNOP = dms.isNOP;
	this.isHalt = dms.isHalt;
}