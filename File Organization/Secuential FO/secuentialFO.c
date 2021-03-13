#include "secuentialFO.h"

#include <string.h>

/**
 * Read a binary file with a set of "Person" structs and returns the number of 
 *  structs stored.
 * If "PRINT_PEOPLE_DAT" is defined, it also prints the whole file as a table.
 * It returns -1 if there is an error.
 */
int readSecFile(char *secFile){
	FILE *file;
	if(secFile == NULL || NULL == (file = fopen(secFile, "rb"))){
		fprintf(stderr, "Error!! Cannot open file %s\n", secFile);
		return -1;
	}
	
	Person p;
	int nrr = 0;
	
	fseek(file, 0, SEEK_SET);
	
	while(fread(&p, sizeof(Person), 1, file)){
		#ifdef PRINT_PEOPLE_DAT
		   printf("%-5d%-10s%-20s%-20s%-20s%-11s\n", nrr++, p.dni, p.name, p.surname1, 
							p.surname2, p.province);
		#else
		   nrr++;
		#endif
	}
	
	return nrr;
}


/**
 * Search for a specific register given a DNI and reads the "Person" struct 
 *  from the file.
 * It returns:
 *  - (-1) in case of error
 *  - (-2) if the DNI wasnt found
 *  - nrr and the struct readed
 */
int searchRegister(char *dni, char *secFile, Person *pFinded){
	if(dni == NULL || secFile == NULL || pFinded == NULL){
		if(pFinded != NULL) 
			pFinded == NULL;
		return -1;
	
	}else{
		FILE *file;
		Person p;
		int nrr = 0;
		
		if(NULL == (file = fopen(secFile, "rb"))){
			fprintf(stderr, "Error!! Cannot open file %s\n", secFile);
			return -1;
		}
		
		fseek(file, 0, SEEK_SET);
		
		while(fread(&p, sizeof(Person), 1, file)){
			if(strcmp(p.dni, dni) == 0){
				*pFinded = p;
				return nrr;
			}else{
				nrr++;
			}
		}
		
		pFinded = NULL;
		return -2;
	}
}


/**
 * Insert a "Person" struct in the secuential binary file and returns
 *  the nrr the struct got.
 * It returns -1 in case of error.
 */
int insertRegister(Person *p, char *secFile){
	if(secFile == NULL || p == NULL){
		return -1;
	
	}else{
		FILE *file; 
		Person temp;
		int nrr = 0;
		
		if(NULL == (file = fopen(secFile, "rb+"))){
			fprintf(stderr, "Error!! Cannot open file %s\n", secFile);
			return -1;
		}	
		
		while(fread(&temp, sizeof(Person), 1, file)){
			nrr++;
		}
		
		fwrite(p, sizeof(Person), 1, file);
		fflush(file);
		fclose(file);
		return nrr;		
	}
}




