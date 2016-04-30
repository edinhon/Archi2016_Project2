#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "ID&EX_buffer.h"
#include "EX_stage.h"

void EX_stage::implement(ID&EX_buffer ieb){
	this.PC = ieb.PC;
	this.op = ieb.op;
	Reg_value = 0;
	Reg_address = 0;
	Data_value = {0};
	Data_address = 0;
	isNOP = ieb.isNOP;
	isHalt = ieb.isHalt;
	
	if(!isNOP && !isHalt){
		//R-TYPE
		if(ieb.op == 0x00){
			//add
			if(ieb.funct == 0x20){
				add(ieb.Rs, ieb.Rt, ieb.rd);
			}
			//addu
			else if(ieb.funct == 0x21){
				addu(ieb.Rs, ieb.Rt, ieb.rd);
			}
			//sub
			else if(ieb.funct == 0x22){
				sub(ieb.Rs, ieb.Rt, ieb.rd);
			}
			//and
			else if(ieb.funct == 0x24){
				andf(ieb.Rs, ieb.Rt, ieb.rd);
			}
			//or
			else if(ieb.funct == 0x25){
				orf(ieb.Rs, ieb.Rt, ieb.rd);
			}
			//xor
			else if(ieb.funct == 0x26){
				xorf(ieb.Rs, ieb.Rt, ieb.rd);
			}
			//nor
			else if(ieb.funct == 0x27){
				nor(ieb.Rs, ieb.Rt, ieb.rd);
			}
			//nand
			else if(ieb.funct == 0x28){
				nand(ieb.Rs, ieb.Rt, ieb.rd);
			}
			//slt
			else if(ieb.funct == 0x2A){
				slt(ieb.Rs, ieb.Rt, ieb.rd);
			}
			//sll
			else if(ieb.funct == 0x00){
				sll(ieb.Rt, ieb.rd, ieb.shamt, ieb.rt);
			}
			//srl
			else if(ieb.funct == 0x02){
				srl(ieb.Rt, ieb.rd, ieb.shamt);
			}
			//sra
			else if(ieb.funct == 0x03){
				sra(ieb.Rt, ieb.rd, ieb.shamt);
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
				addi(ieb.Rs, ieb.rt, ieb.immediate);
			}
			//addiu
			else if(ieb.op == 0x09){
				addiu(ieb.Rs, ieb.rt, ieb.immediate);
			}
			//lw
			else if(ieb.op == 0x23){
				lw(ieb.Rs, ieb.rt, ieb.immediate);
			}
			//lh
			else if(ieb.op == 0x21){
				lh(ieb.Rs, ieb.rt, ieb.immediate);
			}
			//lhu
			else if(ieb.op == 0x25){
				lhu(ieb.Rs, ieb.rt, ieb.immediate);
			}
			//lb
			else if(ieb.op == 0x20){
				lb(ieb.Rs, ieb.rt, ieb.immediate);
			}
			//lbu
			else if(ieb.op == 0x24){
				lbu(ieb.Rs, ieb.rt, ieb.immediate);
			}
			//sw
			else if(ieb.op == 0x2B){
				sw(ieb.Rs, ieb.Rt, ieb.immediate);
			}
			//sh
			else if(ieb.op == 0x29){
				sh(ieb.Rs, ieb.Rt, ieb.immediate);
			}
			//sb
			else if(ieb.op == 0x28){
				sb(ieb.Rs, ieb.Rt, ieb.immediate);
			}
			//lui
			else if(ieb.op == 0x0F){
				lui(ieb.rt, ieb.immediate);
			}
			//andi
			else if(ieb.op == 0x0C){
				andi(ieb.Rs, ieb.rt, ieb.immediate);
			}
			//ori
			else if(ieb.op == 0x0D){
				ori(ieb.Rs, ieb.rt, ieb.immediate);
			}
			//nori
			else if(ieb.op == 0x0E){
				nori(ieb.Rs, ieb.rt, ieb.immediate);
			}
			//slti
			else if(ieb.op == 0x0A){
				slti(ieb.Rs, ieb.rt, ieb.immediate);
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
void EX_stage::add (unsigned int Rs, unsigned int Rt, unsigned int rd){
	//error "Write to register $0"
	if(rd == 0x00){
		error[0] = true;
		
	}
	//error "Number Overflow"
	if(Rs > 0 && Rt > 0 && (Rs + Rt) <= 0){
		error[1] = true;
		//
	}
	else if(Rs < 0 && Rt < 0 && (Rs + Rt) >= 0){
		error[1] = true;
		//
	}
	if(!error[0] && !error[2] && !error[3]){
		Reg_value = Rs + Rt;
		Reg_address = rd;
	}
}
void EX_stage::addu(unsigned int Rs, unsigned int Rt, unsigned int rd){
	//error "Write to register $0"
	if(rd == 0x00){
		error[0] = true;
		
	}
	if(!error[0] && !error[2] && !error[3]){
		Reg_value = Rs + (unsigned int)Rt;
		Reg_address = rd;
	}
}
void EX_stage::sub (unsigned int Rs, unsigned int Rt, unsigned int rd){
	//error "Write to register $0"
	if(rd == 0x00){
		error[0] = true;
		
	}
	//error "Number Overflow"
	if(Rs > 0 && (Rt*-1) > 0 && (Rs + (Rt*-1)) <= 0){
		error[1] = true;
		//
	}
	else if(Rs < 0 && (Rt*-1) < 0 && (Rs + (Rt*-1)) >= 0){
		error[1] = true;
		//
	}
	if(!error[0] && !error[2] && !error[3]){
		Reg_value = Rs - Rt;
		Reg_address = rd;
	}
}
void EX_stage::andf(unsigned int Rs, unsigned int Rt, unsigned int rd){
	//error "Write to register $0"
	if(rd == 0x00){
		error[0] = true;
		
	}
	if(!error[0] && !error[2] && !error[3]){
		Reg_value = Rs & Rt;
		Reg_address = rd;
	}
}
void EX_stage::orf (unsigned int Rs, unsigned int Rt, unsigned int rd){
	//error "Write to register $0"
	if(rd == 0x00){
		error[0] = true;
		
	}
	if(!error[0] && !error[2] && !error[3]){
		Reg_value = Rs | Rt;
		Reg_address = rd;
	}
}
void EX_stage::xorf(unsigned int Rs, unsigned int Rt, unsigned int rd){
	//error "Write to register $0"
	if(rd == 0x00){
		error[0] = true;
		
	}
	if(!error[0] && !error[2] && !error[3]){
		Reg_value = Rs ^ Rt;
		Reg_address = rd;
	}
}
void EX_stage::nor (unsigned int Rs, unsigned int Rt, unsigned int rd){
	//error "Write to register $0"
	if(rd == 0x00){
		error[0] = true;
		
	}
	if(!error[0] && !error[2] && !error[3]){
		Reg_value = ~(Rs | Rt);
		Reg_address = rd;
	}
}
void EX_stage::nand(unsigned int Rs, unsigned int Rt, unsigned int rd){
	//error "Write to register $0"
	if(rd == 0x00){
		error[0] = true;
		
	}
	if(!error[0] && !error[2] && !error[3]){
		Reg_value = ~(Rs & Rt);
		Reg_address = rd;
	}
}
void EX_stage::slt (unsigned int Rs, unsigned int Rt, unsigned int rd){
	//error "Write to register $0"
	if(rd == 0x00){
		error[0] = true;
		
	}
	if(!error[0] && !error[2] && !error[3]){
		Reg_value = (Rt > Rs) ? 1 : 0;
		Reg_address = rd;
	}
}
void EX_stage::sll (unsigned int Rt, unsigned int rd, unsigned int shamt, unsigned int rt){
	//error "Write to register $0"
	if(rd == 0x00 && (rt != 0x00 || shamt != 0x00)){
		error[0] = true;
		
	}
	if(!error[0] && !error[2] && !error[3]){
		Reg_value = Rt << shamt;
		Reg_address = rd;
	}
}
void EX_stage::srl (unsigned int Rt, unsigned int rd, unsigned int shamt){
	//error "Write to register $0"
	if(rd == 0x00){
		error[0] = true;
		
	}
	if(!error[0] && !error[2] && !error[3]){
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
void EX_stage::sra (unsigned int Rt, unsigned int rd, unsigned int shamt){
	//error "Write to register $0"
	if(rd == 0x00){
		error[0] = true;
		
	}
	if(!error[0] && !error[2] && !error[3]){
		Reg_value = Rt >> shamt;
		Reg_address = rd;
	}
}


//I-TYPE
void EX_stage::addi (unsigned int Rs, unsigned int rt, int immediate){
	//error "Write to register $0"
	if(rt == 0x00){
		error[0] = true;
		
	}
	//error "Number Overflow"
	if(Rs > 0 && immediate > 0 && (Rs + immediate) <= 0){
		error[1] = true;
		//
	}
	else if(Rs < 0 && immediate < 0 && (Rs + immediate) >= 0){
		error[1] = true;
		//
	}
	if(!error[0] && !error[2] && !error[3]){
		Reg_value = Rs + immediate;
		Reg_address = rt;
	}
}
void EX_stage::addiu(unsigned int Rs, unsigned int rt, int immediate){
	//error "Write to register $0"
	if(rt == 0x00){
		error[0] = true;
		
	}
	if(!error[0] && !error[2] && !error[3]){
		Reg_value = Rs + ((unsigned int)immediate);
		Reg_address = rt;
	}
}
void EX_stage::lw   (unsigned int Rs, unsigned int rt, int immediate){
	//error "Write to register $0"
	if(rt == 0x00){
		error[0] = true;
		
	}
	//error "Address Overflow"
	if((Rs + immediate) > 1020 || (Rs + immediate) < 0){
		error[2] = true;
	}
	//error "Misalignment Error"
	if((Rs + immediate)%4 != 0){
		error[3] = true;
	}
	//error "Number Overflow"
		if(Rs > 0 && immediate > 0 && (Rs + immediate) <= 0){
			error[1] = true;
			//
		}
		else if(Rs < 0 && immediate < 0 && (Rs + immediate) >= 0){
			error[1] = true;
			//
		}
	if(!error[0] && !error[2] && !error[3]){
		/*Register[rt] = (( Memory[Register[rs] + immediate] << 24 ) & 0xFF000000) | (( Memory[Register[rs] + immediate + 1] << 16 ) & 0x00FF0000) |
						(( Memory[Register[rs] + immediate + 2] << 8 ) & 0x0000FF00) | (( Memory[Register[rs] + immediate + 3] ) & 0x000000FF);*/
		Reg_address = rt;
		Data_address = Rs + immediate;
	}
}
void EX_stage::lh   (unsigned int Rs, unsigned int rt, int immediate){
	//error "Write to register $0"
	if(rt == 0x00){
		error[0] = true;
		
	}
	//error "Address Overflow"
	if((Rs + immediate) > 1022 || (Rs + immediate) < 0){
		error[2] = true;
	}
	//error "Misalignment Error"
	if((Rs + immediate)%2 != 0){
		error[3] = true;
	}
	//error "Number Overflow"
		if(Rs > 0 && immediate > 0 && (Rs + immediate) <= 0){
			error[1] = true;
			//
		}
		else if(Rs < 0 && immediate < 0 && (Rs + immediate) >= 0){
			error[1] = true;
			//
		}
	if(!error[0] && !error[2] && !error[3]){
		//Register[rt] = (((Memory[Register[rs] + immediate] << 24 ) >> 16) & 0xFFFFFF00 ) | ((( Memory[Register[rs] + immediate + 1] << 24) >> 24) & 0x000000FF);
		//Register[rt] = Register[rt] & 0x0000FFFF;
		Reg_address = rt;
		Data_address = Rs + immediate;
	}
}
void EX_stage::lhu  (unsigned int Rs, unsigned int rt, int immediate){
	//error "Write to register $0"
	if(rt == 0x00){
		error[0] = true;
		
	}
	//error "Address Overflow"
	if((Rs + immediate) > 1022 || (Rs + immediate) < 0){
		error[2] = true;
	}
	//error "Misalignment Error"
	if((Rs + immediate)%2 != 0){
		error[3] = true;
	}
	//error "Number Overflow"
		if(Rs > 0 && immediate > 0 && (Rs + immediate) <= 0){
			error[1] = true;
			//
		}
		else if(Rs < 0 && immediate < 0 && (Rs + immediate) >= 0){
			error[1] = true;
			//
		}
	if(!error[0] && !error[2] && !error[3]){
		/*Register[rt] = (((Memory[Register[rs] + immediate] << 24 ) >> 16) & 0x0000FF00) | ((( Memory[Register[rs] + immediate + 1] << 24) >> 24) & 0x000000FF);
		//Register[rt] = Register[rt] & 0x0000FFFF;
		Register[rt] = (unsigned int)Register[rt];*/
		Reg_address = rt;
		Data_address = Rs + immediate;
	}
}
void EX_stage::lb   (unsigned int Rs, unsigned int rt, int immediate){
	//error "Write to register $0"
	if(rt == 0x00){
		error[0] = true;
		
	}
	//error "Address Overflow"
	if((Rs + immediate) > 1023 || (Rs + immediate) < 0){
		error[2] = true;
	}
	//error "Number Overflow"
		if(Rs > 0 && immediate > 0 && (Rs + immediate) <= 0){
			error[1] = true;
			//
		}
		else if(Rs < 0 && immediate < 0 && (Rs + immediate) >= 0){
			error[1] = true;
			//
		}
	if(!error[0] && !error[2] && !error[3]){
		//Register[rt] = ((( Memory[Register[rs] + immediate] << 24) >> 24));
		//Register[rt] = Register[rt] & 0x000000FF;
		Reg_address = rt;
		Data_address = Rs + immediate;
	}
}
void EX_stage::lbu  (unsigned int Rs, unsigned int rt, int immediate){
	//error "Write to register $0"
	if(rt == 0x00){
		error[0] = true;
		
	}
	//error "Address Overflow"
	if((Rs + immediate) > 1023 || (Rs + immediate) < 0){
		error[2] = true;
	}
	//error "Number Overflow"
		if(Rs > 0 && immediate > 0 && (Rs + immediate) <= 0){
			error[1] = true;
			//
		}
		else if(Rs < 0 && immediate < 0 && (Rs + immediate) >= 0){
			error[1] = true;
			//
		}
	if(!error[0] && !error[2] && !error[3]){
		/*Register[rt] = ((( Memory[Register[rs] + immediate] << 24) >> 24) & 0x000000FF);
		//Register[rt] = Register[rt] & 0x000000FF;
		Register[rt] = (unsigned int)Register[rt];*/
		Reg_address = rt;
		Data_address = Rs + immediate;
	}
}
void EX_stage::sw   (unsigned int Rs, unsigned int Rt, int immediate){
	//error "Address Overflow"
	if((Rs + immediate) > 1020 || (Rs + immediate) < 0){
		error[2] = true;
	}
	//error "Misalignment Error"
	if((Rs + immediate)%4 != 0){
		error[3] = true;
	}
	//error "Number Overflow"
		if(Rs > 0 && immediate > 0 && (Rs + immediate) <= 0){
			error[1] = true;
			//
		}
		else if(Rs < 0 && immediate < 0 && (Rs + immediate) >= 0){
			error[1] = true;
			//
		}
	if(!error[0] && !error[2] && !error[3]){
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
void EX_stage::sh   (unsigned int Rs, unsigned int Rt, int immediate){
	//error "Address Overflow"
	if((Rs + immediate) > 1022 || (Rs + immediate) < 0){
		error[2] = true;
	}
	//error "Misalignment Error"
	if((Rs + immediate)%2 != 0){
		error[3] = true;
	}
	//error "Number Overflow"
		if(Rs > 0 && immediate > 0 && (Rs + immediate) <= 0){
			error[1] = true;
			//
		}
		else if(Rs < 0 && immediate < 0 && (Rs + immediate) >= 0){
			error[1] = true;
			//
		}
	if(!error[0] && !error[2] && !error[3]){
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
void EX_stage::sb   (unsigned int Rs, unsigned int Rt, int immediate){
	//error "Address Overflow"
	if((Rs + immediate) > 1023 || (Rs + immediate) < 0){
		error[2] = true;
	}
	//error "Number Overflow"
		if(Rs > 0 && immediate > 0 && (Rs + immediate) <= 0){
			error[1] = true;
			//
		}
		else if(Rs < 0 && immediate < 0 && (Rs + immediate) >= 0){
			error[1] = true;
			//
		}
	if(!error[0] && !error[2] && !error[3]){
		/*Memory[Register[rs] + immediate] = ( (Register[rt]&0x000000FF) << 24 ) >> 24 & 0x000000FF;
		Memory[Register[rs] + immediate] = Memory[Register[rs] + immediate] & 0x000000FF;*/
		Data_address = Rs + immediate;
		Data_value[0] = ( (Rt&0x000000FF) << 24 ) >> 24 & 0x000000FF;
		Data_value[0] = Data_value[0] & 0x000000FF;
	}
}
void EX_stage::lui  (unsigned int rt, int immediate){
	//error "Write to register $0"
	if(rt == 0x00){
		error[0] = true;
		
	}
	if(!error[0] && !error[2] && !error[3]){
		Reg_value = (immediate << 16);
		Reg_address = rt;
	}
}
void EX_stage::andi (unsigned int Rs, unsigned int rt, int immediate){
	//error "Write to register $0"
	if(rt == 0x00){
		error[0] = true;
		
	}
	if(!error[0] && !error[2] && !error[3]){
		Reg_value = Rs & ((unsigned int)immediate & 0x0000FFFF);
		
	}
}
void EX_stage::ori  (unsigned int Rs, unsigned int rt, int immediate){
	//error "Write to register $0"
	if(rt == 0x00){
		error[0] = true;
		
	}
	if(!error[0] && !error[2] && !error[3]){
		Reg_value = Rs | ((unsigned int)immediate & 0x0000FFFF);
		
	}
}
void EX_stage::nori (unsigned int Rs, unsigned int rt, int immediate){
	//error "Write to register $0"
	if(rt == 0x00){
		error[0] = true;
		
	}
	if(!error[0] && !error[2] && !error[3]){
		Reg_value = Rs | ((unsigned int)immediate & 0x0000FFFF);
		Reg_value = (Reg_value*-1) - 1;
		Reg_address = rt;
	}
}
void EX_stage::slti (unsigned int Rs, unsigned int rt, int immediate){
	//error "Write to register $0"
	if(rt == 0x00){
		error[0] = true;
		
	}
	if(!error[0] && !error[2] && !error[3]){
		Reg_value = (Rs < immediate) ? 1 : 0;
		Reg_address = rt;
	}
}
/*void EX_stage::beq  (unsigned int Rs, unsigned int Rt, int immediate){
	if(Rs == Rt) PC += (1 + immediate);
	
}
void EX_stage::bne  (unsigned int Rs, unsigned int Rt, int immediate){
	if(Rs != Rt) PC += (1 + immediate);
	
}
void EX_stage::bgtz (unsigned int Rs, int immediate){
	if(Rs > 0) PC += (1 + immediate);
	
}*/


//J-TYPE
void EX_stage::jal  (){
	Reg_value = (PC + 1);
	Reg_value = Reg_value << 2;
	Reg_address = 31;
}