#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "DM&WB_buffer.h"
#include "DM_stage.h"

using namespace std;

DM&WB_buffer::DM&WB_buffer(){
	Reg_value = 0;
	Reg_address = 0;
	op = 0;
}
	
void DM&WB_buffer::getFromDMStage(DM_stage dms){
	this.Reg_value = edb.Reg_value;
	this.Reg_address = edb.Reg_address;
	this.op = edb.op;
	this.PC = edb.PC;
	this.isNOP = dms.isNOP;
	this.isHalt = dms.isHalt;
}