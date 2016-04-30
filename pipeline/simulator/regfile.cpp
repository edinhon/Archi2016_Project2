#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "regfile.h"

regfile::regfile(){
    for(int i = 0 ; i < 32 ; i++){
        Register[i] = 0;
    }
    Register[29] = 0x400;
}

void regfile::printRegister(FILE *snap){
	for(int i = 0 ; i < 32 ; i++){
		fprintf(snap, "$%0.2d: 0x%0.8X\n", i, Register[i]);
	}
}