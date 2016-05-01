#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <String>
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
unsigned int oldPC = 0;

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
	/*fprintf(snap, "cycle %d\n", i);
	reg.printRegister(snap);
	fprintf(snap, "PC: 0x%0.8X\n\n\n", PC*4);
	printStage();
	i++;*/
	ifs.newPC = PC;
	
	while( (!ifs.isHalt || !ids.isHalt || !exs.isHalt || !dms.isHalt || !wbs.isHalt) && !exs.error[2] && !exs.error[3]){
		
		oldPC = PC;
		
		wbs.writeToRegister(dwb, reg.Register[]);
		dms.writeToData(edb, memo.D_memory);
		dwb.getFromDMStage(dms);
		exs.implement(ieb, edb);
		edb.getFromEXStage(exs);
		ids.decode(reg.Register[], iib, ieb, edb, dwb);
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
			fprintf(snap, "PC: 0x%0.8X\n", oldPC*4);
			/*fprintf(snap, "op code: 0x%0.2X\n", inst.op);
			if(inst.op == 0x00) fprintf(snap, "funct: 0x%0.2X\n\n\n", inst.funct);*/
			i++;
		}
	}
	
	
}

void simulator::printStage(IF_stage ifs, ID_stage ids, EX_stage, exs, DM_stage dms, WB_stage wbs){
	//IF
	fprintf(snap, "IF: 0x%0.8X", ifs.instruction);
	if(ifs.isStall){
		fprintf(snap, " to_be_stalled");
	}
	if(ifs.isFlush){
		fprintf(snap, " to_be_flushed");
	}
	fprintf(sanp, "\n");
	
	//ID
	if(ids.isNOP) fprintf(snap, "ID: NOP");
	else fprintf(snap, "ID: %S", ids.inststr);
	if(ids.isStall){
		fprintf(snap, " to_be_stalled");
	}
	if(ids.isrsForwarding){
		fprintf(snap, " fwd_EX-DM_rs_$%d", ids.rs);
	}
	if(ids.isrtForwarding){
		fprintf(snap, " fwd_EX-DM_rt_$%d", ids.rt);
	}
	fprintf(snap, "\n");
	
	//EX
	if(exs.isNOP) fprintf(snap, "EX: NOP");
	else fprintf(snap, "EX: %S", exs.inststr);
	if(exs.isrsForwarding){
		fprintf(snap, " fwd_EX-DM_rs_$%d", exs.rs);
	}
	if(exs.isrtForwarding){
		fprintf(snap, " fwd_EX-DM_rt_$%d", exs.rt);
	}
	fprintf(snap, "\n");
	
	//DM
	if(dms.isNOP) fprintf(snap, "DM: NOP");
	else fprintf(snap, "DM: %S", dms.inststr);
	fprintf(snap, "\n");
	
	//WB
	if(wbs.isNOP) fprintf(snap, "WB: NOP");
	else fprintf(snap, "WB: %S", wbs.inststr);
	fprintf(snap, "\n\n\n");
}


