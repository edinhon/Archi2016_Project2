#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "IF_stage.h"
#include "ID_stage.h"
#include "EX_stage.h"
#include "DM_stage.h"
#include "WB_stage.h"
#include "IF&ID_buffer.h"
#include "ID&EX_buffer.h"
#include "EX&DM_buffer.h"
#include "DM&WB_buffer.h"
#include "instruction.h"
#include "regfile.h"
#include "memory.h"

using namespace std;

unsigned int PC = 0;

void simulator::runPipeline(){
	
	int i = 0;
	FILE *snap, *dump;
	snap = fopen("snapshot.rpt", "w");
	dump = fopen("error_dump.rpt", "w");
	instruction inst;
	regfile reg;
	memory memo;
	IF_stage ifs;
	ID_stage ids;
	EX_stage exs;
	DM_stage dms;
	WB_stage wbs;
	IF&ID_buffer iib;
	ID&EX_buffer ieb;
	EX&DM_buffer edb;
	DM&WB_buffer dwb;
	
	inst.readInputData(&PC);
	memo.readMemory(&(reg.Register[29]));
	fprintf(snap, "cycle %d\n", i);
	reg.printRegister(snap);
	fprintf(snap, "PC: 0x%0.8X\n\n\n", PC*4);
	i++;
	
	while( (!ifs.isHalt || !ids.isHalt || !exs.isHalt || !dms.isHalt || !wbs.isHalt) && !exs.error[2] && !exs.error[3]){
		
		wbs.writeToRegister(dwb, reg.Register[]);
		dms.writeToData(edb, memo.D_memory);
		dwb.getFromDMStage(dms);
		exs.implement(ieb, edb);
		edb.getFromEXStage(exs);
		ids.decode(reg.Register[], iib, edb);
		ieb.getFromIDStage(ids);
		ifs.readInstruction(&PC, inst.I_memory[], ids);
		iib.getFromIFStage(ifs);
		
		if(exs.error != 0){
			if(exs.error[0]){
				exs.error[0] = false;
				fprintf(dump,  "In cycle %d: Write $0 Error\n", i);
			}
			if(exs.error[2]){
				fprintf(dump, "In cycle %d: Address Overflow\n", i);
			}if(exs.error[3]){
				fprintf(dump, "In cycle %d: Misalignment Error\n", i);
			}if(exs.error[1]){
				exs.error[1] = false;
				fprintf(dump, "In cycle %d: Number Overflow\n", i);
			}
		}
		if( (!ifs.isHalt || !ids.isHalt || !exs.isHalt || !dms.isHalt || !wbs.isHalt) && !exs.error[2] && !exs.error[3]){
			fprintf(snap, "cycle %d\n", i);
			reg.printRegister(snap);
			fprintf(snap, "PC: 0x%0.8X\n\n\n", PC*4);
			/*fprintf(snap, "op code: 0x%0.2X\n", inst.op);
			if(inst.op == 0x00) fprintf(snap, "funct: 0x%0.2X\n\n\n", inst.funct);*/
			i++;
		}
	}
	
	
}