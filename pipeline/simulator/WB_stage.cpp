#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "DM_WB_buffer.h"
#include "WB_stage.h"

using namespace std;

WB_stage::WB_stage(){
	op = 0;
}

void WB_stage::writeToRegister(DM_WB_buffer dwb, int Register[]){
	op = dwb.op;
	inststr = dwb.inststr;
	isNOP = dwb.isNOP;
	isHalt = dwb.isHalt;

	if(!isNOP && !isHalt && dwb.Reg_address != 0x00){
		//R-TYPE
		if(op == 0x00){
			Register[dwb.Reg_address] = dwb.Reg_value;
		}
		//J-TYPE
		else if(op == 0x03){
			Register[dwb.Reg_address] = dwb.Reg_value;
		}
		//I-TYPE
		else{
			//addi
			if(op == 0x08){
				Register[dwb.Reg_address] = dwb.Reg_value;
			}
			//addiu
			else if(op == 0x09){
				Register[dwb.Reg_address] = dwb.Reg_value;
			}
			//lw
			else if(op == 0x23){
				Register[dwb.Reg_address] = dwb.Reg_value;
			}
			//lh
			else if(op == 0x21){
				Register[dwb.Reg_address] = dwb.Reg_value;
			}
			//lhu
			else if(op == 0x25){
				Register[dwb.Reg_address] = dwb.Reg_value;
			}
			//lb
			else if(op == 0x20){
				Register[dwb.Reg_address] = dwb.Reg_value;
			}
			//lbu
			else if(op == 0x24){
				Register[dwb.Reg_address] = dwb.Reg_value;
			}
			//lui
			else if(op == 0x0F){
				Register[dwb.Reg_address] = dwb.Reg_value;
			}
			//andi
			else if(op == 0x0C){
				Register[dwb.Reg_address] = dwb.Reg_value;
			}
			//ori
			else if(op == 0x0D){
				Register[dwb.Reg_address] = dwb.Reg_value;
			}
			//nori
			else if(op == 0x0E){
				Register[dwb.Reg_address] = dwb.Reg_value;
			}
			//slti
			else if(op == 0x0A){
				Register[dwb.Reg_address] = dwb.Reg_value;
			}
			//beq
			else if(op == 0x04){
				Register[dwb.Reg_address] = dwb.Reg_value;
			}
			//bne
			else if(op == 0x05){
				Register[dwb.Reg_address] = dwb.Reg_value;
			}
			//bgtz
			else if(op == 0x07){
				Register[dwb.Reg_address] = dwb.Reg_value;
			}
		}
	}

}
