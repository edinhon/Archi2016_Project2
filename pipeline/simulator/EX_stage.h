#ifndef LAB2_EX_STAGE_H
#define LAB2_EX_STAGE_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <string>
#include "ID_EX_buffer.h"
#include "EX_DM_buffer.h"

using namespace std;

class ID_EX_buffer;
class EX_DM_buffer;

class EX_stage{

public:

	void implement(ID_EX_buffer ieb, EX_DM_buffer edb);

	//R-TYPE
    void add (int Rs, int Rt, unsigned int rd);
    void addu(int Rs, int Rt, unsigned int rd);
    void sub (int Rs, int Rt, unsigned int rd);
    void andf(int Rs, int Rt, unsigned int rd);
    void orf (int Rs, int Rt, unsigned int rd);
    void xorf(int Rs, int Rt, unsigned int rd);
    void nor (int Rs, int Rt, unsigned int rd);
    void nand(int Rs, int Rt, unsigned int rd);
    void slt (int Rs, int Rt, unsigned int rd);
    void sll (int Rt, unsigned int rd, unsigned int shamt, unsigned int rt);
    void srl (int Rt, unsigned int rd, unsigned int shamt);
    void sra (int Rt, unsigned int rd, unsigned int shamt);
	//I-TYPE
    void addi (int Rs, unsigned int rt,  int immediate);
    void addiu(int Rs, unsigned int rt,  int immediate);
    void lw   (int Rs, unsigned int rt,  int immediate);
    void lh   (int Rs, unsigned int rt,  int immediate);
    void lhu  (int Rs, unsigned int rt,  int immediate);
    void lb   (int Rs, unsigned int rt,  int immediate);
    void lbu  (int Rs, unsigned int rt,  int immediate);
    void sw   (int Rs, int Rt,  int immediate);
    void sh   (int Rs, int Rt,  int immediate);
    void sb   (int Rs, int Rt,  int immediate);
    void lui  (unsigned int rt,  int immediate);
    void andi (int Rs, unsigned int rt,  int immediate);
    void ori  (int Rs, unsigned int rt,  int immediate);
    void nori (int Rs, unsigned int rt,  int immediate);
    void slti (int Rs, unsigned int rt,  int immediate);
    /*void beq  (int Rs, int Rt,  int immediate);
    void bne  (int Rs, int Rt,  int immediate);
    void bgtz (int Rs,  int immediate);*/
	//J-TYPE
	void jal  ();

    unsigned int rs, rt;
	unsigned int PC;
	int Reg_value , Data_value[4];
	unsigned int Reg_address, Data_address;
	unsigned int op;
	string inststr;
	bool error4 = false;
	bool isNOP = true;
	bool isHalt = false;
	bool isrsForwarding = false, isrtForwarding = false;
};

#endif //LAB2_EX_STAGE_H
