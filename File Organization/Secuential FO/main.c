#include "secuentialFO.h"

#include <string.h>

int main(void){
	char dataFile[11] = "people.dat";

	int nReg, i, nrr;	
	Person p;
	char dni[20];
	
	//Read data file
	nReg = readSecFile(dataFile);
	printf("\n\x1b[33;3;4mTotal number of people:\x1b[0;36;1m %d \x1b[0m\n\n", nReg);

	//Search registers
	strcpy(dni, "7389298");
	i = searchRegister(dni, dataFile, &p);
	switch(i){
		case -1: printf("\x1b[31;1mError in searchRegister!!!\x1b[0m\n");
			break;
		case -2: printf("\x1b[31;1mCannot find person with dni %s\x1b[0m\n\n", dni);
			break;
		default: 
			printf("\x1b[32;1mRegister finded, NRR %d:",i);
			printf("\x1b[0;36;1m   %s %s %s %s %s \x1b[0m \n", p.dni, p.name, p.surname1, p.surname2, p.province);
	}
	
	
	strcpy(dni, "123456789");
	i = searchRegister(dni, dataFile, &p);
	switch(i){
		case -1: printf("\x1b[31;1mError in searchRegister!!!\x1b[0m\n");
			break;
		case -2: printf("\x1b[31;1mCannot find person with dni %s\x1b[0m\n\n", dni);
			break;
		default: 
			printf("\x1b[32;1mRegister finded, NRR %d",i);
			printf("\x1b[0;36;1m %s %s %s %s %s \x1b[0m \n\n", p.dni, p.name, p.surname1, p.surname2, p.province);
	}
	
	
	//Insert new register
	Person newPerson = {"12345678","Hi","im","new","Salamanca"};
	
	nrr = insertRegister(&newPerson, dataFile);
	if(nrr < 0)
		printf("\x1b[31;1mCannot insert the register\x1b[0m\n\n");
	else
		printf("\x1b[32;1mRegister was successfully inserted with NRR=\x1b[0;36;1m%d\x1b[0m \n\n", nrr);
	
	//Re-read data file and see changes
	nReg = readSecFile(dataFile);
	printf("\n\x1b[33;3;4mNew total number of people:\x1b[0;36;1m %d \x1b[0m\n\n", nReg);

	return 0;
}
