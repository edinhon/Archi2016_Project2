#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "ID_stage.h"
#include "EX&DM_buffer.h"

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

void ID_stage::decode(int Register[], IF&ID_buffer iib, EX&DM_buffer edb){
	this.PC = iib.PC;
	isBranch = false;
	
	isNOP = iib.isNOP;
	isHalt = iib.isHalt;
	isrsForwarding = false;
	isrtForwarding = false;
	
	if(!isNOP && !isHalt){
		op = (iib.instructionBuffer >> 26);
		//printf("%X\n", op);
		//R-TYPE
		if(op == 0x00){
			rs = (instruction << 6);
			rs = (rs >> 27);
			rt = (instruction << 11);
			rt = (rt >> 27);
			rd = (instruction << 16);
			rd = (rd >> 27);
			Rd = Register[rd];
			shamt = (instruction << 21);
			shamt = (shamt >> 27);
			funct = (instruction << 26);
			funct = (funct >> 26);
			
			if(rs == edb.Reg_address && funct != 0x00 && funct != 0x02 && funct != 0x03) Rs = edb.Reg_value;
			else Rs = Register[rs];
			if(rt == edb.Reg_address && funct != 0x08) Rt = edb.Reg_value;
			else Rt = Register[rt];
			
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
			rt = (instruction << 11);
			rt = (rt >> 27);
			immediate = (instruction << 16);
			immediate = (immediate >> 16);
			
			if(rs == edb.Reg_address && op != 0x0F) {
				Rs = edb.Reg_value;
				if(op == 0x04 || op == 0x05 || op == 0x07) isrsForwarding = true;
			}
			else Rs = Register[rs];
			if(rt == edb.Reg_address && op == 0x2B && op == 0x29 && op == 0x28 && op == 0x04 && op == 0x05) {
				Rt = edb.Reg_value;
				if(op == 0x04 || op == 0x05) isrtForwarding = true;
			}
			else Rt = Register[rt];
			
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
