#ifndef LAB2_EX_STAGE_H
#define LAB2_EX_STAGE_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <String>
#include "ID_EX_buffer.h"
#include "EX_DM_buffer.h"

using namespace std;

class EX_stage{

public:
	
	void implement(ID_EX_buffer ieb, EX_DM_buffer edb);
	
	//R-TYPE
    void add (unsigned int Rs, unsigned int Rt, unsigned int rd);
    void addu(unsigned int Rs, unsigned int Rt, unsigned int rd);
    void sub (unsigned int Rs, unsigned int Rt, unsigned int rd);
    void andf(unsigned int Rs, unsigned int Rt, unsigned int rd);
    void orf (unsigned int Rs, unsigned int Rt, unsigned int rd);
    void xorf(unsigned int Rs, unsigned int Rt, unsigned int rd);
    void nor (unsigned int Rs, unsigned int Rt, unsigned int rd);
    void nand(unsigned int Rs, unsigned int Rt, unsigned int rd);
    void slt (unsigned int Rs, unsigned int Rt, unsigned int rd);
    void sll (unsigned int Rt, unsigned int rd, unsigned int shamt, unsigned int rt);
    void srl (unsigned int Rt, unsigned int rd, unsigned int shamt);
    void sra (unsigned int Rt, unsigned int rd, unsigned int shamt);
	//I-TYPE
    void addi (unsigned int Rs, unsigned int rt,  int immediate);
    void addiu(unsigned int Rs, unsigned int rt,  int immediate);
    void lw   (unsigned int Rs, unsigned int rt,  int immediate);
    void lh   (unsigned int Rs, unsigned int rt,  int immediate);
    void lhu  (unsigned int Rs, unsigned int rt,  int immediate);
    void lb   (unsigned int Rs, unsigned int rt,  int immediate);
    void lbu  (unsigned int Rs, unsigned int rt,  int immediate);
    void sw   (unsigned int Rs, unsigned int Rt,  int immediate);
    void sh   (unsigned int Rs, unsigned int Rt,  int immediate);
    void sb   (unsigned int Rs, unsigned int Rt,  int immediate);
    void lui  (unsigned int rt,  int immediate);
    void andi (unsigned int Rs, unsigned int rt,  int immediate);
    void ori  (unsigned int Rs, unsigned int rt,  int immediate);
    void nori (unsigned int Rs, unsigned int rt,  int immediate);
    void slti (unsigned int Rs, unsigned int rt,  int immediate);
    /*void beq  (unsigned int Rs, unsigned int Rt,  int immediate);
    void bne  (unsigned int Rs, unsigned int Rt,  int immediate);
    void bgtz (unsigned int Rs,  int immediate);*/
	//J-TYPE
	void jal  ();
	
	unsigned int PC;
	int Reg_value , Data_value[4];
	unsigned int Reg_address, Data_address;
	unsigned int op;
	String inststr;
	bool error[4] = {0};
	bool isNOP = true;
	bool isHalt = false;
	bool isrsForwarding = false, isrtForwarding = false;
};

#endif LAB2_EX_STAGE_H