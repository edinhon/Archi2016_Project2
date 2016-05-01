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
	for(int i = 0 ; i < 4 ; i++){
        Data_value[i] = 0;
	}
	Data_address = 0;
	op = 0;
}

void EX_DM_buffer::getFromEXStage(EX_stage exs){
	isNOP = exs.isNOP;
	isHalt = exs.isHalt;
	if(!isNOP){
		Reg_value = exs.Reg_value;
		Reg_address = exs.Reg_address;
		for(int i = 0 ; i < 4 ; i++){
			Data_value[i] = exs.Data_value[i];
		}
		Data_address = exs.Data_address;
		op = exs.op;
		inststr = exs.inststr;
		PC = exs.PC;
	}
}
