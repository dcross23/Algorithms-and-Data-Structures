#include "hashFO.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Creates a .hash file with empty buckets.
 * Returns 0 if success, -1 if error.
 */
int createEmptyHashFile(char *hashFile){
	FILE *hFile;
	Bucket b;
	int i, nBuckets;

	if(NULL == (hFile = fopen(hashFile, "wb")))
		return -1;

	
	memset(&b, 0, sizeof(Bucket));	
	nBuckets = BUCKETS + OVERFLOW_BUCKETS;

	for(i=0; i<nBuckets; i++){
		fwrite(&b, sizeof(Bucket), 1, hFile);
	}
	
	fclose(hFile);
	return 0;
}


/**
 * Creates a .hash file from a .dat file. It reads people info from
 *  a .dat file and inserts it to buckets in .hash file.
 * It returns:
 *  - (-1) if params error
 *  - (-2) if cannot open .dat file
 *  - number of overflowing registers that where inserted.
 */
int createHashFromBinaryFile(char *binaryFile, char *hashFile){
	if(-1 == createEmptyHashFile(hashFile))
		return -1;

	FILE *inFile, *outFile;
	if(NULL == (inFile = fopen(binaryFile, "rb"))) return -2;

	Person p;
	Bucket b;
	int nOverflows = 0;
	int insertedBucket;
	
	while(fread(&p, sizeof(Person), 1, inFile)){
		insertedBucket = insertRegister(&p, hashFile);
		
		if(insertedBucket >= BUCKETS)
			nOverflows++;
	}
	return nOverflows;
}


/**
 * Reads, interprets and prints a .hash file to see how data is stored.
 * Returns the total number of buckets the .hash file stores (including
 *  buckets in overflowing area), or -1 if cannot open the .hash file.
 */
int readHashFile(char *hashFile){
	FILE *hFile;
	Bucket b;
	int i,j,n;
	
	if(NULL == (hFile = fopen(hashFile, "rb")))
		return -1;
	
	rewind(hFile);
	
	i = 0;
	fread(&b, sizeof(Bucket), 1, hFile);
	while(!feof(hFile)){
		for(j=0; j<CAPACITY; j++){
			if(j == 0){
				printf("\x1b[36;1m==============================================================\n");
				printf("\x1b[33;3;4mBucket %2d (%02d registers assigned)\n\x1b[0m",i, b.size);
			}
			
			if(j < b.size)
				printf("\t\t\t%-8s %-19s %-19s %-19s %-11s\n", b.registers[j].dni, b.registers[j].name,
				 b.registers[j].surname1,b.registers[j].surname2,b.registers[j].province);
			else
				printf("\n");	
		}
		
		i++;
		fread(&b, sizeof(Bucket), 1, hFile);
	}
	
	printf("\x1b[36;1m==============================================================\n\x1b[0m");
	fclose(hFile);
	return i;
}


/**
 * Searches for a register in a .hash file given a dni.
 * It returns:
 *  - (-1) if params error
 *  - (-2) if cannot open .hash file
 *  - (-3) if dni is not stored in .hash file
 *  - bucket number where dni has been found
 */
int searchRegister(char *dni, char *hashFile, Person *p){
	if(dni == NULL || hashFile == NULL || p == NULL)
		return -1;
		
	FILE *hFile;
	if(NULL == (hFile = fopen(hashFile, "rb")))
		return -2;
	
	int i;
	Bucket b;
	
	//Move to the bucket where dni should be stored according to the hashFile
	fseek(hFile, HASH_BUCKET(atoi(dni)), SEEK_SET);
	fread(&b, sizeof(Bucket), 1, hFile);
	
	//Look if the dni is in that bucket. If it is not in the cube:
	// - If bucket size <  CAPACITY -> dni is not stored anywhere
	// - If bucket size >= CAPACITY -> dni might be stored in overflow zone
	for(i=0; i<CAPACITY && i<b.size; i++){
		if(strcmp(b.registers[i].dni, dni) == 0){
			*p = b.registers[i];
			return HASH(atoi(dni));
		}
	}
	
	if(b.size < CAPACITY)
		return -3;
	else{
		int bucketReaded;
	
		//Move to overflow zone
		fseek(hFile, OVERFLOW_ZONE, SEEK_SET);
		
		bucketReaded = 0;
		while(fread(&b, sizeof(Bucket), 1, hFile)){
			for(i=0; i<CAPACITY && i<b.size; i++){
				if(strcmp(b.registers[i].dni, dni) == 0){
					*p = b.registers[i];
					return BUCKETS + bucketReaded;
				}
			}
			
			//If the last bucket is reached (last is not full) and 
			// dni was not found, dni is not stored anywhere.
			if(b.size < CAPACITY)
				return -3;
			
			bucketReaded++;	
		}
	}
}


/**
 * Inserts a new register (person) in a .hash file.
 *  - (-1) if params error
 *  - (-2) if cannot open .hash file
 *  - (-3) if there is no more available space to store people
 *  - bucket number where dni has been stored if success
 */
int insertRegister(Person *p, char *hashFile){
	if(p == NULL || hashFile == NULL)
		return -1;
		
	FILE *hFile;
	if(NULL == (hFile = fopen(hashFile, "rb+"))){
		return -2;
	}
	
	Bucket b;
	
	//Move pointer to the cube where the register in going to be
	// stored, according to the DNI hash
	fseek(hFile, HASH_BUCKET(atoi(p->dni)), SEEK_SET);
	
	//Reads the cube from the file:
	// - If bucket size <  CAPACITY -> Bucket has space to store the registers
	// - If bucket size >= CAPACITY -> Bucket has no space, register is stores in overflow zone.
	fread(&b, sizeof(Bucket), 1, hFile);
	
	if(b.size < CAPACITY){
		b.registers[b.size] = *p;
		(b.size)++;
		
		//Move pointer back to the bucket again and overwrite it
		fseek(hFile, -sizeof(Bucket), SEEK_CUR);
		fwrite(&b, sizeof(Bucket), 1, hFile);
		
		fclose(hFile);
		return HASH(atoi(p->dni));

	}else{
		int i, bucketToRead;
	
		//Increment size and rewrite the register that is full.
		b.size++;
		fseek(hFile, -sizeof(Bucket), SEEK_CUR);	
		fwrite(&b, sizeof(Bucket), 1, hFile);
		
		//Move to overflow zone and search for a empty space to 
		// store the register. If there is no more space available,
		// it returns -3.
		fseek(hFile, OVERFLOW_ZONE, SEEK_SET);
		
		bucketToRead = 0;
		fread(&b, sizeof(Bucket), 1, hFile);
		
		while(!(b.size < CAPACITY)){
			bucketToRead++;
			if(bucketToRead == OVERFLOW_BUCKETS){
				fclose(hFile);
				return -3;
			}
				
			fread(&b, sizeof(Bucket), 1, hFile);
		}
		
		
		//If there is a bucket with available space, inserts the register
		// and overwrites the bucket in the file.
		b.registers[b.size] = *p;
		fseek(hFile, -sizeof(Bucket), SEEK_CUR);	
		fwrite(&b, sizeof(Bucket), 1, hFile);
		
		//Finally, increments the number of registers assigned in all 
		// overflow buckets located before the bucket where the register
		// was saved
		fseek(hFile, OVERFLOW_ZONE, SEEK_SET);
		for(i=0; i<=bucketToRead; i++){
			//Read cube
			fread(&b, sizeof(Bucket), 1, hFile);
			//Increment size
			b.size++;
			//Overwrite cube
			fseek(hFile, -sizeof(Bucket), SEEK_CUR);	
			fwrite(&b, sizeof(Bucket), 1, hFile);
		}
		
		fclose(hFile);
		return (BUCKETS + bucketToRead);
	}
}


