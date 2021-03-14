#include "hashFO.h"

#include <stdio.h>
#include <string.h>


int main(void){
	int i, nOverflows;
	FILE *f;
	Person p;
	char hashFile[12] = "people.hash";
	char dni[9];
	
	nOverflows = createHashFromBinaryFile("people.dat", hashFile);	
	i = readHashFile(hashFile);
	
	printf("\n\n\x1b[33;3;4mTotal Cubes:\x1b[0;35;1m %d\x1b[0m \n", i);
	printf("\x1b[33;3;4mOverflowing registers:\x1b[0;35;1m %d\x1b[0m \n\n", nOverflows);
	
	//Search registers
	strcpy(dni,"7389298"); //Exists in a bucket
	i = searchRegister(dni, hashFile, &p);	
	switch(i){
		case -1: printf("\x1b[31;1mError in searchRegister\x1b[0m \n"); break;
		case -2: printf("\x1b[31;1mError cannot open file in searchRegister!!!\x1b[0m \n"); break;
		case -3: printf("\x1b[31;1mCannot find person with dni %s\x1b[0m \n", dni); break;
		default: printf("\x1b[32;1mRegister finded in BUCKET %d:",i);
			printf("\x1b[0;36;1m   %s %s %s %s %s \x1b[0m \n", p.dni, p.name, p.surname1, 
				p.surname2,p.province);
	}
	
	
	strcpy(dni,"7219752"); //Exists in a overflow zone
	i = searchRegister(dni, hashFile, &p);
	switch(i){
		case -1: printf("\x1b[31;1mError in searchRegister\x1b[0m \n"); break;
		case -2: printf("\x1b[31;1mError cannot open file in searchRegister!!!\x1b[0m \n"); break;
		case -3: printf("\x1b[31;1mCannot find person with dni %s\x1b[0m \n", dni); break;
		default: printf("\x1b[32;1mRegister finded in BUCKET %d:",i);
			printf("\x1b[0;36;1m   %s %s %s %s %s \x1b[0m \n", p.dni, p.name, p.surname1, 
				p.surname2,p.province);
	}
	
	
	strcpy(dni,"12345678"); //Dont exist
	i = searchRegister(dni, hashFile, &p);	
	switch(i){
		case -1: printf("\x1b[31;1mError in searchRegister\x1b[0m \n"); break;
		case -2: printf("\x1b[31;1mError cannot open file in searchRegister!!!\x1b[0m \n"); break;
		case -3: printf("\x1b[31;1mCannot find person with dni %s\x1b[0m \n", dni); break;
		default: printf("\x1b[32;1mRegister finded in BUCKET %d:",i);
			printf("\x1b[0;36;1m   %s %s %s %s %s \x1b[0m \n", p.dni, p.name, p.surname1, 
				p.surname2,p.province);
	}
	
	
	//Insert register
	printf("\n");
	Person newPerson = {"12345678","Hi","im","new","Salamanca"}; //Inserts in overflow zone
	i = insertRegister(&newPerson, hashFile);
	switch(i){
		case -1: printf("\x1b[31;1mError in insertRegister\x1b[0m \n"); break;
		case -2: printf("\x1b[31;1mError cannot open file in insertRegister!!!\x1b[0m \n"); break;
		case -3: printf("\x1b[31;1mNo more space available to insert\x1b[0m \n"); break;
		default: printf("\x1b[32;1mRegister inserted in BUCKET %d \n",i);
	}
	
	
	Person otherNewPerson = {"19493800","Other","new","person","Salamanca"}; //Inserts in bucket 0
	i = insertRegister(&otherNewPerson, hashFile);
	switch(i){
		case -1: printf("\x1b[31;1mError in insertRegister\x1b[0m \n"); break;
		case -2: printf("\x1b[31;1mError cannot open file in insertRegister!!!\x1b[0m \n"); break;
		case -3: printf("\x1b[31;1mNo more space available to insert\x1b[0m \n"); break;
		default: printf("\x1b[32;1mRegister inserted in BUCKET %d \n",i);
	}
	
	//readHashFile(hashFile);
	
	printf("\n");
	return 0;
}
