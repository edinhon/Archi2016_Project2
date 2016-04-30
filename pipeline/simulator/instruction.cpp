#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "instruction.h"

using namespace std;

instruction::instruction(){
	for(int i = 0 ; i < 256 ; i++){
        I_memory[i] = 0;
    }
	times = 0;
}

void instruction::readInputData(unsigned int *PC){
	
	FILE *fPtr;
	unsigned char input[4];

	fPtr = fopen("iimage.bin", "rb");

	if (!fPtr) {
        printf("wrong data\n");
        return ;
    }

    fread(&input[0], sizeof(unsigned char), 1, fPtr);
    fread(&input[1], sizeof(unsigned char), 1, fPtr);
    fread(&input[2], sizeof(unsigned char), 1, fPtr);
    fread(&input[3], sizeof(unsigned char), 1, fPtr);
    *PC = ( input[0] << 24 ) + ( input[1] << 16 ) + ( input[2] <<  8 ) + input[3];
	*PC /= 4;
	//printf("%d\n", *PC);

    fread(&input[0], sizeof(unsigned char), 1, fPtr);
    fread(&input[1], sizeof(unsigned char), 1, fPtr);
    fread(&input[2], sizeof(unsigned char), 1, fPtr);
    fread(&input[3], sizeof(unsigned char), 1, fPtr);
    times = ( input[0] << 24 ) + ( input[1] << 16 ) + ( input[2] <<  8 ) + input[3];

    for(int i = 0 ; i < times ; i++){
        fread(&input[0], sizeof(unsigned char), 1, fPtr);
        fread(&input[1], sizeof(unsigned char), 1, fPtr);
        fread(&input[2], sizeof(unsigned char), 1, fPtr);
        fread(&input[3], sizeof(unsigned char), 1, fPtr);
        I_memory[*PC + i] |= ( input[0] << 24 ) + ( input[1] << 16 ) + ( input[2] <<  8 ) + input[3];
        //printf("%0.8X\n", I_memory[*PC + i]);
    }

    fclose(fPtr);
	
}
