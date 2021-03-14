#ifndef __HASH_FO_H__
#define __HASH_FO_H__

#define CAPACITY 5
#define BUCKETS 20
#define OVERFLOW_BUCKETS 4 

//Auxiliar "functions"
#define HASH(K) ((K)%BUCKETS)
#define HASH_BUCKET(K) ((HASH(K))*sizeof(Bucket))
#define OVERFLOW_ZONE (BUCKETS*sizeof(Bucket))


/**
 * Each struct is stored in a bucket according to a hash. This hash is 
 *  calculated with the dni of the person using modulus formula:
 *       hash = dni % BUCKETS 
 *
 * Each calculated hash is related to a specific bucket where that person
 *  is/is going to be stored.
 *
 * If all (20) buckets all full, there is a auxiliar zone to store more people.
 *  This is called "Overflow zone", and has a capacity of 4 more buckets. This zone
 *  is a secuential area that stores people when the bucket that corresponds to the hash
 *  calculated with a dni is full. When a person is stored in this zone, the size of the 
 *  cube where the person should have been stored is increased even if it is stored in 
 *  the overflow zone. This lets the user know that there should be more people than there 
 *  are in the full bucket, and that they are stored in the overflow zone.
 *
 * If both the (20)buckets and overflow zone are full, no more people can be inserted.
 */

typedef struct person{
	char dni[9];
	char name[19];
	char surname1[19];
	char surname2[19];
	char province[11];
}Person;


typedef struct bucket{
	Person registers[CAPACITY];
	int size;
}Bucket;


//Create hash file
int createEmptyHashFile(char *hashFile);
int createHashFromBinaryFile(char *binaryFile, char *hashFile);

//Functions
int readHashFile(char *hashFile);
int searchRegister(char *dni, char *hashFile, Person *p);
int insertRegister(Person *p, char *hashFile);


//TODO: deleteRegister function (reduce bucket size and relocate overflow zone registers
//         that should have been in the buckets)
#endif
