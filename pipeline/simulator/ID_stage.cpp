#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "ID_stage.h"
#include "IF&ID_buffer.h"
#include "ID&EX_buffer.h"
#include "EX&DM_buffer.h"
#include "DM&WB_buffer.h"

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

void ID_stage::decode(int Register[], IF&ID_buffer iib, ID&EX_buffer ieb, EX&DM_buffer edb, DM&WB_buffer dwb){
	this.PC = iib.PC;
	isBranch = false;
	
	isNOP = iib.isNOP;
	isHalt = iib.isHalt;
	isrsForwarding = false;
	isrtForwarding = false;
	unsigned int instruction = iib.instructionBuffer;
	
	if(!isNOP && !isHalt){
		op = (instruction >> 26);
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
			if(op != 0x08) Reg_address = rd;
			
			//stall by conditional branch data hazard
			if(funct == 0x08){
				if(rs == ieb.Reg_address) isNOP = true;
			}
			
			//stall by Reg_address in DM stage
			//sll sra srl not need to read Rs
			if(rs == dwb.Reg_address && funct != 0x00 && funct != 0x02 && funct != 0x03){
				isNOP = true;
			}
			//jr not need to read Rt
			if(rt == dwb.Reg_address && funct != 0x08){
				isNOP = true;
			}
			
			//stall by load memory
			if(ieb.op == 0x23 || ieb.op == 0x21 || ieb.op == 0x25 || ieb.op == 0x20 || ieb.op == 0x24){
				//lui not need to read Rs
				if(rs == ieb.rt && funct != 0x0F){
					isNOP = true;
				}
				//only save beq bne need to read rt
				if(rt == ieb.rt && funct == 0x2B && funct == 0x29 && funct == 0x28 && funct == 0x04 && funct == 0x05){
					isNOP = true;
				}
			}
			
			//jr rs forwarding if not stall
			if(rs == edb.Reg_address && !edb.isNOP && funct == 0x08) {
				Rs = edb.Reg_value;
				isrsForwarding = true;
			}
			else Rs = Register[rs];
			
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
			Reg_address = 0x31;
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
			if(op != 0x2B || op != 0x29 || op != 0x28 || op != 0x04 || op != 0x05 || op != 0x07) Reg_address = rt;
			
			//stall by conditional branch data hazard
			if(op == 0x04 || op == 0x05 || op == 0x07){
				if(rs == ieb.Reg_address) isNOP = true;
				if(rt == ieb.Reg_address && op != 0x07) isNOP = true;
			}
			
			//stall by Reg_address in DM stage
			//lui not need to read Rs
			if(rs == dwb.Reg_address && op != 0x0F){
				isNOP = true;
			}
			//only save beq bne need to read rt
			if(rt == dwb.Reg_address && (op == 0x2B || op == 0x29 || op == 0x28 || op == 0x04 || op == 0x05) ){
				isNOP = true;
			}
			
			//stall by load memory
			if(ieb.op == 0x23 || ieb.op == 0x21 || ieb.op == 0x25 || ieb.op == 0x20 || ieb.op == 0x24){
				//lui not need to read Rs
				if(rs == ieb.rt && op != 0x0F){
					isNOP = true;
				}
				//only save beq bne need to read rt
				if(rt == ieb.rt && op == 0x2B && op == 0x29 && op == 0x28 && op == 0x04 && op == 0x05){
					isNOP = true;
				}
			}
			
			//beq bne bgtz rs forwarding if not stall
			if(rs == edb.Reg_address && !edb.isNOP && (op == 0x04 || op == 0x05 || op == 0x07) && !isNOP) {
				Rs = edb.Reg_value;
				isrsForwarding = true;
			}
			else Rs = Register[rs];
			//beq bne rt forwarding if not stall
			if(rt == edb.Reg_address && !edb.isNOP && (op == 0x04 || op == 0x05) && !isNOP) {
				Rt = edb.Reg_value;
				isrtForwarding = true;
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
