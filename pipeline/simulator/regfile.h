#ifndef LAB1_REGFILE_H
#define LAB1_REGFILE_H

#include<iostream>
#include<cstdio>
#include<cstdlib>

class regfile{

public:

    regfile();
	void printRegister(FILE *snap);

    int Register[32] = {0};

};

#endif // LAB1_REGFILE_H
