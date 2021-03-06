#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "ID_EX_buffer.h"
#include "EX_DM_buffer.h"
#include "EX_stage.h"

using namespace std;

void EX_stage::implement(ID_EX_buffer ieb, EX_DM_buffer edb){
	PC = ieb.PC;
	op = ieb.op;
	rs = ieb.rs;
	rt= ieb.rt;
	Reg_value = 0;
	Reg_address = ieb.Reg_address;
	for(int i = 0 ; i < 4 ; i++){
        Data_value[i] = 0;
	}
	Data_address = 0;
	inststr = ieb.inststr;
	isNOP = ieb.isNOP;
	isHalt = ieb.isHalt;
	isrsForwarding = false;
	isrtForwarding = false;
	error4 = false;

	if(!isNOP && !isHalt){
		//R-TYPE
		if(ieb.op == 0x00){
			//add
			if(ieb.funct == 0x20){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00) {
					add(edb.Reg_value, ieb.Rt, ieb.rd);
					isrsForwarding = true;
				}
				else if(ieb.rt == edb.Reg_address && edb.Reg_address != 0x00) {
					add(ieb.Rs, edb.Reg_value, ieb.rd);
					isrtForwarding = true;
				}
				else {
					add(ieb.Rs, ieb.Rt, ieb.rd);
				}
			}
			//addu
			else if(ieb.funct == 0x21){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00) {
					addu(edb.Reg_value, ieb.Rt, ieb.rd);
					isrsForwarding = true;
				}
				else if(ieb.rt == edb.Reg_address && edb.Reg_address != 0x00) {
					addu(ieb.Rs, edb.Reg_value, ieb.rd);
					isrtForwarding = true;
				}
				else {
					addu(ieb.Rs, ieb.Rt, ieb.rd);
				}
			}
			//sub
			else if(ieb.funct == 0x22){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00) {
					sub(edb.Reg_value, ieb.Rt, ieb.rd);
					isrsForwarding = true;
				}
				else if(ieb.rt == edb.Reg_address && edb.Reg_address != 0x00) {
					sub(ieb.Rs, edb.Reg_value, ieb.rd);
					isrtForwarding = true;
				}
				else {
					sub(ieb.Rs, ieb.Rt, ieb.rd);
				}
			}
			//and
			else if(ieb.funct == 0x24){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00) {
					andf(edb.Reg_value, ieb.Rt, ieb.rd);
					isrsForwarding = true;
				}
				else if(ieb.rt == edb.Reg_address && edb.Reg_address != 0x00) {
					andf(ieb.Rs, edb.Reg_value, ieb.rd);
					isrtForwarding = true;
				}
				else {
					andf(ieb.Rs, ieb.Rt, ieb.rd);
				}
			}
			//or
			else if(ieb.funct == 0x25){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00) {
					orf(edb.Reg_value, ieb.Rt, ieb.rd);
					isrsForwarding = true;
				}
				else if(ieb.rt == edb.Reg_address && edb.Reg_address != 0x00) {
					orf(ieb.Rs, edb.Reg_value, ieb.rd);
					isrtForwarding = true;
				}
				else {
					orf(ieb.Rs, ieb.Rt, ieb.rd);
				}
			}
			//xor
			else if(ieb.funct == 0x26){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00) {
					xorf(edb.Reg_value, ieb.Rt, ieb.rd);
					isrsForwarding = true;
				}
				else if(ieb.rt == edb.Reg_address && edb.Reg_address != 0x00) {
					xorf(ieb.Rs, edb.Reg_value, ieb.rd);
					isrtForwarding = true;
				}
				else {
					xorf(ieb.Rs, ieb.Rt, ieb.rd);
				}
			}
			//nor
			else if(ieb.funct == 0x27){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00) {
					nor(edb.Reg_value, ieb.Rt, ieb.rd);
					isrsForwarding = true;
				}
				else if(ieb.rt == edb.Reg_address && edb.Reg_address != 0x00) {
					nor(ieb.Rs, edb.Reg_value, ieb.rd);
					isrtForwarding = true;
				}
				else {
					nor(ieb.Rs, ieb.Rt, ieb.rd);
				}
			}
			//nand
			else if(ieb.funct == 0x28){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00) {
					nand(edb.Reg_value, ieb.Rt, ieb.rd);
					isrsForwarding = true;
				}
				else if(ieb.rt == edb.Reg_address && edb.Reg_address != 0x00) {
					nand(ieb.Rs, edb.Reg_value, ieb.rd);
					isrtForwarding = true;
				}
				else {
					nand(ieb.Rs, ieb.Rt, ieb.rd);
				}
			}
			//slt
			else if(ieb.funct == 0x2A){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00) {
					slt(edb.Reg_value, ieb.Rt, ieb.rd);
					isrsForwarding = true;
				}
				else if(ieb.rt == edb.Reg_address && edb.Reg_address != 0x00) {
					slt(ieb.Rs, edb.Reg_value, ieb.rd);
					isrtForwarding = true;
				}
				else {
					slt(ieb.Rs, ieb.Rt, ieb.rd);
				}
			}
			//sll
			else if(ieb.funct == 0x00){
				if(ieb.rt == edb.Reg_address && edb.Reg_address != 0x00) {
					sll(edb.Reg_value, ieb.rd, ieb.shamt, ieb.rt);
					isrtForwarding = true;
				}
				else {
					sll(ieb.Rt, ieb.rd, ieb.shamt, ieb.rt);
				}
			}
			//srl
			else if(ieb.funct == 0x02){
				if(ieb.rt == edb.Reg_address && edb.Reg_address != 0x00) {
					srl(edb.Reg_value, ieb.rd, ieb.shamt);
					isrtForwarding = true;
				}
				else {
					srl(ieb.Rt, ieb.rd, ieb.shamt);
				}
			}
			//sra
			else if(ieb.funct == 0x03){
				if(ieb.rt == edb.Reg_address && edb.Reg_address != 0x00) {
					sra(edb.Reg_value, ieb.rd, ieb.shamt);
					isrtForwarding = true;
				}
				else {
					sra(ieb.Rt, ieb.rd, ieb.shamt);
				}
			}
		}
		//J-TYPE
		//jal
		else if(ieb.op == 0x03){
			jal();
		}
		//I-TYPE
		else{
			//addi
			if(ieb.op == 0x08){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00){
					addi(edb.Reg_value, ieb.rt, ieb.immediate);
					isrsForwarding = true;
				}
				else{
					addi(ieb.Rs, ieb.rt, ieb.immediate);
				}
			}
			//addiu
			else if(ieb.op == 0x09){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00){
					addiu(edb.Reg_value, ieb.rt, ieb.immediate);
					isrsForwarding = true;
				}
				else{
					addiu(ieb.Rs, ieb.rt, ieb.immediate);
				}
			}
			//lw
			else if(ieb.op == 0x23){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00){
					lw(edb.Reg_value, ieb.rt, ieb.immediate);
					isrsForwarding = true;
				}
				else{
					lw(ieb.Rs, ieb.rt, ieb.immediate);
				}
			}
			//lh
			else if(ieb.op == 0x21){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00){
					lh(edb.Reg_value, ieb.rt, ieb.immediate);
					isrsForwarding = true;
				}
				else{
					lh(ieb.Rs, ieb.rt, ieb.immediate);
				}
			}
			//lhu
			else if(ieb.op == 0x25){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00){
					lhu(edb.Reg_value, ieb.rt, ieb.immediate);
					isrsForwarding = true;
				}
				else{
					lhu(ieb.Rs, ieb.rt, ieb.immediate);
				}
			}
			//lb
			else if(ieb.op == 0x20){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00){
					lb(edb.Reg_value, ieb.rt, ieb.immediate);
					isrsForwarding = true;
				}
				else{
					lb(ieb.Rs, ieb.rt, ieb.immediate);
				}
			}
			//lbu
			else if(ieb.op == 0x24){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00){
					lbu(edb.Reg_value, ieb.rt, ieb.immediate);
					isrsForwarding = true;
				}
				else{
					lbu(ieb.Rs, ieb.rt, ieb.immediate);
				}
			}
			//sw
			else if(ieb.op == 0x2B){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00){
					sw(edb.Reg_value, ieb.Rt, ieb.immediate);
					isrsForwarding = true;
				}
				else if(ieb.rt == edb.Reg_address && edb.Reg_address != 0x00){
					sw(ieb.Rs, edb.Reg_value, ieb.immediate);
					isrtForwarding = true;
				}
				else{
					sw(ieb.Rs, ieb.Rt, ieb.immediate);
				}
			}
			//sh
			else if(ieb.op == 0x29){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00){
					sh(edb.Reg_value, ieb.Rt, ieb.immediate);
					isrsForwarding = true;
				}
				else if(ieb.rt == edb.Reg_address && edb.Reg_address != 0x00){
					sh(ieb.Rs, edb.Reg_value, ieb.immediate);
					isrtForwarding = true;
				}
				else{
					sh(ieb.Rs, ieb.Rt, ieb.immediate);
				}
			}
			//sb
			else if(ieb.op == 0x28){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00){
					sb(edb.Reg_value, ieb.Rt, ieb.immediate);
					isrsForwarding = true;
				}
				else if(ieb.rt == edb.Reg_address && edb.Reg_address != 0x00){
					sb(ieb.Rs, edb.Reg_value, ieb.immediate);
					isrtForwarding = true;
				}
				else{
					sb(ieb.Rs, ieb.Rt, ieb.immediate);
				}
			}
			//lui
			else if(ieb.op == 0x0F){
				lui(ieb.rt, ieb.immediate);
			}
			//andi
			else if(ieb.op == 0x0C){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00){
					andi(edb.Reg_value, ieb.rt, ieb.immediate);
					isrsForwarding = true;
				}
				else{
					andi(ieb.Rs, ieb.rt, ieb.immediate);
				}
			}
			//ori
			else if(ieb.op == 0x0D){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00){
					ori(edb.Reg_value, ieb.rt, ieb.immediate);
					isrsForwarding = true;
				}
				else{
					ori(ieb.Rs, ieb.rt, ieb.immediate);
				}
			}
			//nori
			else if(ieb.op == 0x0E){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00){
					nori(edb.Reg_value, ieb.rt, ieb.immediate);
					isrsForwarding = true;
				}
				else{
					nori(ieb.Rs, ieb.rt, ieb.immediate);
				}
			}
			//slti
			else if(ieb.op == 0x0A){
				if(ieb.rs == edb.Reg_address && edb.Reg_address != 0x00){
					slti(edb.Reg_value, ieb.rt, ieb.immediate);
					isrsForwarding = true;
				}
				else{
					slti(ieb.Rs, ieb.rt, ieb.immediate);
				}
			}
			/*//beq
			else if(ieb.op == 0x04){
				beq(ieb.Rs, ieb.rt, ieb.immediate);
			}
			//bne
			else if(ieb.op == 0x05){
				bne(ieb.Rs, ieb.rt, ieb.immediate);
			}
			//bgtz
			else if(ieb.op == 0x07){
				bgtz(ieb.Rs, ieb.immediate);
			}*/
		}
	}

}

//R-TYPE
void EX_stage::add (int Rs, int Rt, unsigned int rd){
	//error "Number Overflow"
	if(Rs > 0 && Rt > 0 && (Rs + Rt) <= 0){
		error4 = true;
	}
	else if(Rs < 0 && Rt < 0 && (Rs + Rt) >= 0){
		error4 = true;
	}
	{
		Reg_value = Rs + Rt;
		Reg_address = rd;
	}
}
void EX_stage::addu(int Rs, int Rt, unsigned int rd){
	{
		Reg_value = Rs + (unsigned int)Rt;
		Reg_address = rd;
	}
}
void EX_stage::sub (int Rs, int Rt, unsigned int rd){
	//error "Number Overflow"
	if(Rs > 0 && (Rt*-1) > 0 && (Rs + (Rt*-1)) <= 0){
		error4 = true;
	}
	else if(Rs < 0 && (Rt*-1) < 0 && (Rs + (Rt*-1)) >= 0){
		error4 = true;
	}
	{
		Reg_value = Rs - Rt;
		Reg_address = rd;
	}
}
void EX_stage::andf(int Rs, int Rt, unsigned int rd){
	{
		Reg_value = Rs & Rt;
		Reg_address = rd;
	}
}
void EX_stage::orf (int Rs, int Rt, unsigned int rd){
	{
		Reg_value = Rs | Rt;
		Reg_address = rd;
	}
}
void EX_stage::xorf(int Rs, int Rt, unsigned int rd){
	{
		Reg_value = Rs ^ Rt;
		Reg_address = rd;
	}
}
void EX_stage::nor (int Rs, int Rt, unsigned int rd){
	{
		Reg_value = ~(Rs | Rt);
		Reg_address = rd;
	}
}
void EX_stage::nand(int Rs, int Rt, unsigned int rd){
	{
		Reg_value = ~(Rs & Rt);
		Reg_address = rd;
	}
}
void EX_stage::slt (int Rs, int Rt, unsigned int rd){
	{
		Reg_value = (Rt > Rs) ? 1 : 0;
		Reg_address = rd;
	}
}
void EX_stage::sll (int Rt, unsigned int rd, unsigned int shamt, unsigned int rt){
	{
		Reg_value = Rt << shamt;
		Reg_address = rd;
	}
}
void EX_stage::srl (int Rt, unsigned int rd, unsigned int shamt){
	{
		if((Rt >> 31) == 0xFFFFFFFF) {
			//Register[rd] = ( (((0xFFFFFFFF << (32 - shamt)))*-1)-1) & (Register[rt] >> shamt);
			if(shamt != 0) Reg_value = ~(0xFFFFFFFF << (32 - shamt)) & (Rt >> shamt);
			else if(shamt == 0) Reg_value = ~(0xFFFFFFFF << 32) & (Rt >> shamt);
		}
		else{
			Reg_value = Rt >> shamt;
		}
		Reg_address = rd;
	}
}
void EX_stage::sra (int Rt, unsigned int rd, unsigned int shamt){
	{
		Reg_value = Rt >> shamt;
		Reg_address = rd;
	}
}


//I-TYPE
void EX_stage::addi (int Rs, unsigned int rt, int immediate){
	//error "Number Overflow"
	if(Rs > 0 && immediate > 0 && (Rs + immediate) <= 0){
		error4 = true;
	}
	else if(Rs < 0 && immediate < 0 && (Rs + immediate) >= 0){
		error4 = true;
	}
	{
		Reg_value = Rs + immediate;
		Reg_address = rt;
	}
}
void EX_stage::addiu(int Rs, unsigned int rt, int immediate){
	{
		Reg_value = Rs + ((unsigned int)immediate);
		Reg_address = rt;
	}
}
void EX_stage::lw   (int Rs, unsigned int rt, int immediate){
	//error "Number Overflow"
		if(Rs > 0 && immediate > 0 && (Rs + immediate) <= 0){
			error4 = true;
		}
		else if(Rs < 0 && immediate < 0 && (Rs + immediate) >= 0){
			error4 = true;
		}
	{
		/*Register[rt] = (( Memory[Register[rs] + immediate] << 24 ) & 0xFF000000) | (( Memory[Register[rs] + immediate + 1] << 16 ) & 0x00FF0000) |
						(( Memory[Register[rs] + immediate + 2] << 8 ) & 0x0000FF00) | (( Memory[Register[rs] + immediate + 3] ) & 0x000000FF);*/
		Reg_address = rt;
		Data_address = Rs + immediate;
	}
}
void EX_stage::lh   (int Rs, unsigned int rt, int immediate){
	//error "Number Overflow"
		if(Rs > 0 && immediate > 0 && (Rs + immediate) <= 0){
			error4 = true;
		}
		else if(Rs < 0 && immediate < 0 && (Rs + immediate) >= 0){
			error4 = true;
		}
	{
		//Register[rt] = (((Memory[Register[rs] + immediate] << 24 ) >> 16) & 0xFFFFFF00 ) | ((( Memory[Register[rs] + immediate + 1] << 24) >> 24) & 0x000000FF);
		//Register[rt] = Register[rt] & 0x0000FFFF;
		Reg_address = rt;
		Data_address = Rs + immediate;
	}
}
void EX_stage::lhu  (int Rs, unsigned int rt, int immediate){
	//error "Number Overflow"
		if(Rs > 0 && immediate > 0 && (Rs + immediate) <= 0){
			error4 = true;
		}
		else if(Rs < 0 && immediate < 0 && (Rs + immediate) >= 0){
			error4 = true;
		}
	{
		/*Register[rt] = (((Memory[Register[rs] + immediate] << 24 ) >> 16) & 0x0000FF00) | ((( Memory[Register[rs] + immediate + 1] << 24) >> 24) & 0x000000FF);
		//Register[rt] = Register[rt] & 0x0000FFFF;
		Register[rt] = (unsigned int)Register[rt];*/
		Reg_address = rt;
		Data_address = Rs + immediate;
	}
}
void EX_stage::lb   (int Rs, unsigned int rt, int immediate){
	//error "Number Overflow"
		if(Rs > 0 && immediate > 0 && (Rs + immediate) <= 0){
			error4 = true;
		}
		else if(Rs < 0 && immediate < 0 && (Rs + immediate) >= 0){
			error4 = true;
		}
	{
		//Register[rt] = ((( Memory[Register[rs] + immediate] << 24) >> 24));
		//Register[rt] = Register[rt] & 0x000000FF;
		Reg_address = rt;
		Data_address = Rs + immediate;
	}
}
void EX_stage::lbu  (int Rs, unsigned int rt, int immediate){
	//error "Number Overflow"
		if(Rs > 0 && immediate > 0 && (Rs + immediate) <= 0){
			error4 = true;
		}
		else if(Rs < 0 && immediate < 0 && (Rs + immediate) >= 0){
			error4 = true;
		}
	{
		/*Register[rt] = ((( Memory[Register[rs] + immediate] << 24) >> 24) & 0x000000FF);
		//Register[rt] = Register[rt] & 0x000000FF;
		Register[rt] = (unsigned int)Register[rt];*/
		Reg_address = rt;
		Data_address = Rs + immediate;
	}
}
void EX_stage::sw   (int Rs, int Rt, int immediate){
	//error "Number Overflow"
		if(Rs > 0 && immediate > 0 && (Rs + immediate) <= 0){
			error4 = true;
		}
		else if(Rs < 0 && immediate < 0 && (Rs + immediate) >= 0){
			error4 = true;
		}
	{
		/*Memory[Register[rs] + immediate] = ( Register[rt] >> 24 ) & 0x000000FF;
		Memory[Register[rs] + immediate + 1] = ( Register[rt] << 8 ) >> 24 & 0x000000FF;
		Memory[Register[rs] + immediate + 2] = ( Register[rt] << 16 ) >> 24 & 0x000000FF;
		Memory[Register[rs] + immediate + 3] = ( Register[rt] << 24 ) >> 24 & 0x000000FF;*/
		Data_address = Rs + immediate;
		Data_value[0] = ( Rt >> 24 ) & 0x000000FF;
		Data_value[1] = ( Rt << 8 ) >> 24 & 0x000000FF;
		Data_value[2] = ( Rt << 16 ) >> 24 & 0x000000FF;
		Data_value[3] = ( Rt << 24 ) >> 24 & 0x000000FF;
	}
}
void EX_stage::sh   (int Rs, int Rt, int immediate){
	//error "Number Overflow"
		if(Rs > 0 && immediate > 0 && (Rs + immediate) <= 0){
			error4 = true;
		}
		else if(Rs < 0 && immediate < 0 && (Rs + immediate) >= 0){
			error4 = true;
		}
	{
		/*Memory[Register[rs] + immediate] = ( (Register[rt]&0x0000FFFF) << 16 ) >> 24;
		Memory[Register[rs] + immediate] = Memory[Register[rs] + immediate] & 0x000000FF;
		Memory[Register[rs] + immediate + 1] = ( (Register[rt]&0x0000FFFF) << 24 ) >> 24;
		Memory[Register[rs] + immediate + 1] = Memory[Register[rs] + immediate + 1] & 0x000000FF;*/
		Data_address = Rs + immediate;
		Data_value[0] = ( (Rt&0x0000FFFF) << 16 ) >> 24;
		Data_value[0] = Data_value[0] & 0x000000FF;
		Data_value[1] = ( (Rt&0x0000FFFF) << 24 ) >> 24;
		Data_value[1] = Data_value[1] & 0x000000FF;
	}
}
void EX_stage::sb   (int Rs, int Rt, int immediate){
	//error "Number Overflow"
		if(Rs > 0 && immediate > 0 && (Rs + immediate) <= 0){
			error4 = true;
		}
		else if(Rs < 0 && immediate < 0 && (Rs + immediate) >= 0){
			error4 = true;
		}
	{
		/*Memory[Register[rs] + immediate] = ( (Register[rt]&0x000000FF) << 24 ) >> 24 & 0x000000FF;
		Memory[Register[rs] + immediate] = Memory[Register[rs] + immediate] & 0x000000FF;*/
		Data_address = Rs + immediate;
		Data_value[0] = ( (Rt&0x000000FF) << 24 ) >> 24 & 0x000000FF;
		Data_value[0] = Data_value[0] & 0x000000FF;
	}
}
void EX_stage::lui  (unsigned int rt, int immediate){
	{
		Reg_value = (immediate << 16);
		Reg_address = rt;
	}
}
void EX_stage::andi (int Rs, unsigned int rt, int immediate){
	{
		Reg_value = Rs & ((unsigned int)immediate & 0x0000FFFF);
		Reg_address = rt;
	}
}
void EX_stage::ori  (int Rs, unsigned int rt, int immediate){
	{
		Reg_value = Rs | ((unsigned int)immediate & 0x0000FFFF);
		Reg_address = rt;
	}
}
void EX_stage::nori (int Rs, unsigned int rt, int immediate){
	{
		Reg_value = Rs | ((unsigned int)immediate & 0x0000FFFF);
		Reg_value = (Reg_value*-1) - 1;
		Reg_address = rt;
	}
}
void EX_stage::slti (int Rs, unsigned int rt, int immediate){
	{
		Reg_value = (Rs < immediate) ? 1 : 0;
		Reg_address = rt;
	}
}
/*void EX_stage::beq  (int Rs, int Rt, int immediate){
	if(Rs == Rt) PC += (1 + immediate);

}
void EX_stage::bne  (int Rs, int Rt, int immediate){
	if(Rs != Rt) PC += (1 + immediate);

}
void EX_stage::bgtz (int Rs, int immediate){
	if(Rs > 0) PC += (1 + immediate);

}*/


//J-TYPE
void EX_stage::jal  (){
	Reg_value = (PC + 1);
	Reg_value = Reg_value << 2;
	Reg_address = 31;
}
