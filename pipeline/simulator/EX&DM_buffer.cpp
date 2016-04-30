#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "EX&DM_buffer.h"
#include "EX_stage.h"

using namespace std;

ID&EX_buffer::EX&DM_buffer(){
	Reg_value = 0;
	Reg_address = 0;
	Data_value = {0};
	Data_address = 0;
	op = 0;
}

void getFromEXStage(EX_stage exs){
	this.Reg_value = exs.Reg_value;
	this.Reg_address = exs.Reg_address;
	for(int i = 0 ; i < 4 ; i++){
		this.Data_value[i] = exs.Data_value[i]
	}
	this.Data_address = exs.Data_address;
	this.op = exs.op;
	this.PC = exs.PC;
	this.isNOP = exs.isNOP;
	this.isHalt = exs.isHalt;
}