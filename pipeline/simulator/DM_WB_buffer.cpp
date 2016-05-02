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
	isNOP = dms.isNOP;
	isHalt = dms.isHalt;
	if(!isNOP){
		Reg_value = dms.Reg_value;
		Reg_address = dms.Reg_address;
		op = dms.op;
		PC = dms.PC;
		inststr = dms.inststr;
	}
	else{
		Reg_value = 0;
		Reg_address = 0;
		op = 0;
		PC = 0;
		inststr = 0;
	}
	
}
