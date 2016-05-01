#ifndef LAB2_SIMULATOR_H
#define LAB2_SIMULATOR_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <String>
#include "IF_stage.h"
#include "ID_stage.h"
#include "EX_stage.h"
#include "DM_stage.h"
#include "WB_stage.h"
#include "IF_ID_buffer.h"
#include "ID_EX_buffer.h"
#include "EX_DM_buffer.h"
#include "DM_WB_buffer.h"
#include "instruction.h"
#include "regfile.h"
#include "memory.h"

using namespace std;

class simulator{

public:

	void runPipeline();
	
	void printStage(IF_stage ifs, ID_stage ids, EX_stage, exs, DM_stage dms, WB_stage wbs);
};

#endif LAB2_SIMULATOR_H