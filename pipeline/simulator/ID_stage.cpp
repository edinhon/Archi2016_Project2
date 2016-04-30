#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "ID_stage.h"

ID_stage::ID_stage(){
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
	isBranch = false;
}

void ID_stage::decode(int Register[], IF&ID_buffer iib){
	this.PC = iib.PC;
	isBranch = false;
	
	isNOP = iib.isNOP;
	isHalt = iib.isHalt;
	
	if(!isNOP && !isHalt){
		op = (iib.instructionBuffer >> 26);
		//printf("%X\n", op);
		//R-TYPE
		if(op == 0x00){
			rs = (instruction << 6);
			rs = (rs >> 27);
			Rs = Register[rs];
			rt = (instruction << 11);
			rt = (rt >> 27);
			Rt = Register[rt];
			rd = (instruction << 16);
			rd = (rd >> 27);
			Rd = Register[rd];
			shamt = (instruction << 21);
			shamt = (shamt >> 27);
			funct = (instruction << 26);
			funct = (funct >> 26);
			//printf("%X %X %X %X %X\n", rs, rt, rd, shamt, funct);
			//jr
			if(funct == 0x08){
				PC = Rs >> 2;
				isBranch = true;
			}
		}
		//J-TYPE
		//j
		else if(op == 0x02){
			address = (instruction << 6);
			address = (address >> 6);
			PC = address;
			isBranch = true;
		}
		//jal
		else if(op == 0x03){
			address = (instruction << 6);
			address = (address >> 6);
			PC = address;
			isBranch = true;
		}
		//halt
		else if(op == 0x3F){
			address = (instruction << 6);
			address = (address >> 6);
			isHalt = true;
		}
		//I-TYPE
		else{
			rs = (instruction << 6);
			rs = (rs >> 27);
			Rs = Register[rs];
			rt = (instruction << 11);
			rt = (rt >> 27);
			Rt = Register[rt];
			immediate = (instruction << 16);
			immediate = (immediate >> 16);
			//beq
			if(op == 0x04){
				if(Rs == Rt) PC += (1 + immediate);
				isBranch = true;
			}
			//bne
			else if(op == 0x05){
				if(Rs != Rt) PC += (1 + immediate);
				isBranch = true;
			}
			//bgtz
			else if(op == 0x07){
				if(Rs > 0) PC += (1 + immediate);
				isBranch = true;
			}
		}
		}
	}
}
