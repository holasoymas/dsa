#include "hash_table_api.h"

// The FNV-1a (Fowler/Noll/Vo) hash function is an industry standard that has
// excellent distribution and is fast to compute. It uses an exclusive or (XOR)
// and multiplication to mix the bits of the key

// __initHashFNV__

void __initHashFNV__(HashTable *table) {
  table->size = 0;
  for (int i = 0; i < SIZE; i++) {
    table->arr[i] = INT_MIN;
  }
}

unsigned long FNV_1a_hashFunction(const char *key) {
  // Initializing hash value to a specific offset value 0x811c9dc5, which is a
  // magic number used in the FNV-1a hash algorithm
  unsigned long hash = 0x811C9DC5; // 2166136261
  int c;
  // looping over the character of strings
  while ((c = *key++)) {
    // performing a bitwise XOR operation with the ASCII value of the current
    // character
    hash = hash ^ c;
    // the hash value by a specific magic number 0x01000193, which is a prime
    // number and is used to further mix the bits of the hash value.
    hash = hash * 0X01000193;
  }
  return hash;
};

int FNV_1a_hashIndx(int hashCode) { return hashCode % (unsigned int)SIZE; }

void insertHashFNV(HashTable *table, const char *key, int data) {
  unsigned long hashCode = FNV_1a_hashFunction(key);
  int hashIndx = FNV_1a_hashIndx(hashCode);
  if (table->arr[hashIndx] == INT_MIN) {
    table->arr[hashIndx] = data;
    table->size++;
    return;
  }
  printf("Void Insertion : Hash code for %s already present\n", key);
}

// IF value return is == INT_MIN it mean that record is empty
int lookUpFNV(HashTable *table, const char *key) {
  unsigned long hashCode = FNV_1a_hashFunction(key);
  int hashIndx = FNV_1a_hashIndx(hashCode);

  return table->arr[hashIndx];
}

void deleteHashFNV(HashTable *table, const char *key) {

  int hashCode = FNV_1a_hashFunction(key);
  int hashIndx = FNV_1a_hashIndx(hashCode);

  if (table->arr[hashIndx] != INT_MIN) {
    table->arr[hashIndx] = INT_MIN;
    return;
  }
  printf("No record with the key %s found int the table.\n", key);
}
