#ifndef HASH_TABLE
#define HASH_TABLE

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define CONST_FRACTION 0.61803398

// size tell how many elements are there in hash table
typedef struct HashTable {
  int arr[SIZE];
  int size;
} HashTable;

// HashTable operations with multiplicative method

void __initHash__(HashTable *table);
int multiplicativeHashFunction(int key);
int hashCode(const char *key);

void insertHash(HashTable *table, const char *key, int data);
int lookUp(HashTable *table, const char *key);
void deleteHash(HashTable *table, const char *key);

// NOTE: Hash table with FNV_1a algirthm

void __initHashFNV__(HashTable *table);
int FNV_1a_hashIndx(int hashCode);
unsigned long FNV_1a_hashFunction(const char *key);

void insertHashFNV(HashTable *table, const char *key, int data);
int lookUpFNV(HashTable *table, const char *key);
void deleteHashFNV(HashTable *table, const char *key);

#endif // HASH_TABLE
