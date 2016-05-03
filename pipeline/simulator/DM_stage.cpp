#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <String>
#include "EX_DM_buffer.h"
#include "DM_stage.h"

using namespace std;

DM_stage::DM_stage(){
	Reg_value = 0;
	Reg_address = 0;
	for(int i = 0 ; i < 4 ; i++){
        Data_value[i] = 0;
	}
	Data_address = 0;
	op = 0;
}

void DM_stage::writeToData(EX_DM_buffer edb, char Memory[]){

	Reg_value = edb.Reg_value;
	Reg_address = edb.Reg_address;
	for(int i = 0 ; i < 4 ; i++){
		Data_value[i] = edb.Data_value[i];
	}
	Data_address = edb.Data_address;
	op = edb.op;
	PC = edb.PC;
	inststr = edb.inststr;
	isNOP = edb.isNOP;
	isHalt = edb.isHalt;
	error2 = false;
	error3 = false;

	if(!isNOP && !isHalt){
		//lw
		if(op == 0x23){
			//error "Address Overflow"
			if(Data_address > 1020 || Data_address < 0) error2 = true;
			//error "Misalignment Error"
			if(Data_address%4 != 0) error3 = true;
			if(!error2 && !error3) Reg_value = (( Memory[Data_address] << 24 ) & 0xFF000000) | (( Memory[Data_address + 1] << 16 ) & 0x00FF0000) |
							(( Memory[Data_address + 2] << 8 ) & 0x0000FF00) | (( Memory[Data_address + 3] ) & 0x000000FF);
		}
		//lh
		else if(op == 0x21){
			//error "Address Overflow"
			if(Data_address > 1022 || Data_address < 0) error2 = true;
			//error "Misalignment Error"
			if(Data_address%2 != 0) error3 = true;
			if(!error2 && !error3){
				Reg_value = (((Memory[Data_address] << 24 ) >> 16) & 0xFFFFFF00 ) | ((( Memory[Data_address + 1] << 24) >> 24) & 0x000000FF);
				Reg_value = Reg_value & 0x0000FFFF;
			}
		}
		//lhu
		else if(op == 0x25){
			//error "Address Overflow"
			if(Data_address > 1022 || Data_address < 0) error2 = true;
			//error "Misalignment Error"
			if(Data_address%2 != 0) error3 = true;
			if(!error2 && !error3){
				Reg_value = (((Memory[Data_address] << 24 ) >> 16) & 0xFFFFFF00 ) | ((( Memory[Data_address + 1] << 24) >> 24) & 0x000000FF);
				Reg_value = Reg_value & 0x0000FFFF;
				Reg_value = (unsigned int)Reg_value;
			}
			
		}
		//lb
		else if(op == 0x20){
			//error "Address Overflow"
			if(Data_address > 1023 || Data_address < 0) error2 = true;
			if(!error2 && !error3){
				Reg_value = ((( Memory[Data_address] << 24) >> 24));
				Reg_value = Reg_value & 0x000000FF;
			}
		}
		//lbu
		else if(op == 0x24){
			//error "Address Overflow"
			if(Data_address > 1023 || Data_address < 0) error2 = true;
			if(!error2 && !error3){
				Reg_value = ((( Memory[Data_address] << 24) >> 24));
				Reg_value = Reg_value & 0x000000FF;
				Reg_value = (unsigned int)Reg_value;
			}
		}
		//sw
		else if(op == 0x2B){
			//error "Address Overflow"
			if(Data_address > 1020 || Data_address < 0) error2 = true;
			//error "Misalignment Error"
			if(Data_address%4 != 0) error3 = true;
			if(!error2 && !error3){
				Memory[Data_address] = Data_value[0];
				Memory[Data_address + 1] = Data_value[1];
				Memory[Data_address + 2] = Data_value[2];
				Memory[Data_address + 3] = Data_value[3];
			}
		}
		//sh
		else if(op == 0x29){
			//error "Address Overflow"
			if(Data_address > 1022 || Data_address < 0) error2 = true;
			//error "Misalignment Error"
			if(Data_address%2 != 0) error3 = true;
			if(!error2 && !error3){
				Memory[Data_address] = Data_value[0];
				Memory[Data_address + 1] = Data_value[1];
			}
		}
		//sb
		else if(op == 0x28){
			//error "Address Overflow"
			if(Data_address > 1023 || Data_address < 0) error2 = true;
			if(!error2 && !error3){
				Memory[Data_address] = Data_value[0];
			}
		}
	}

}
