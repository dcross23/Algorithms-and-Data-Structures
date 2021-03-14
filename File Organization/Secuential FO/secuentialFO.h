#ifndef __SECUENTIAL_FO_H__
#define __SECUENTIAL_FO_H__

#include <stdio.h>

//#define PRINT_PEOPLE_DAT

/**
 * Each struct is stored in a secuential order. This order is given by 
 *  the NRR (Relative Register Number), that goes from 0 to n, where 
 *  n is the NRR of the last struct. 
 */

typedef struct person{
	char dni[9];
	char name[19];
	char surname1[19];
	char surname2[19];
	char province[11];
}Person;

int readSecFile(char *secFile);
int searchRegister(char *dni, char *secFile, Person *p);
int insertRegister(Person *p, char *secFile);


//TODO: -modify struct and add "deleted" atribute to 
//       allow deletions in the file (overwrite)  
//      -add binary search function

//int deleteRegister(char *dni, FILE *secFile, Person *p);

#endif
