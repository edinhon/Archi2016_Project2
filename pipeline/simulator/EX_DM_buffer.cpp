#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <String>
#include "EX_DM_buffer.h"
#include "EX_stage.h"

using namespace std;

EX_DM_buffer::EX_DM_buffer(){
	Reg_value = 0;
	Reg_address = 0;
	Data_value = {0};
	Data_address = 0;
	op = 0;
}

void EX_DM_buffer::getFromEXStage(EX_stage exs){
	this.isNOP = exs.isNOP;
	this.isHalt = exs.isHalt;
	if(!isNOP){
		this.Reg_value = exs.Reg_value;
		this.Reg_address = exs.Reg_address;
		for(int i = 0 ; i < 4 ; i++){
			this.Data_value[i] = exs.Data_value[i]
		}
		this.Data_address = exs.Data_address;
		this.op = exs.op;
		this.inststr = exs.inststr;
		this.PC = exs.PC;
	}
}