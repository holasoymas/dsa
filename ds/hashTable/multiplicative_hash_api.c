#include "hash_table_api.h"

void __initHash__(HashTable *table) {
  table->size = 0;
  for (int i = 0; i < SIZE; i++) {
    table->arr[i] = INT_MIN;
  }
}

// h(k) = floor(SIZE_OF_HASHTABLE * frac(CONST_FRACTION * key))
// where fact is frac(x) = x - floor(x)

int multiplicativeHashFunction(int key) {
  double r = key * CONST_FRACTION;

  // Extract the fractional part of r and store it in a variable f
  double f = r - (int)r;

  return (int)(SIZE * f);
}

int hashCode(const char *key) {

  int sum = 0;

  for (int i = 0; key[i] != '\0'; i++) {
    sum = sum + (int)key[i];
  }
  return sum;
}

void insertHash(HashTable *table, const char *key, int value) {
  int hashNum = hashCode(key);
  int hashIndx = multiplicativeHashFunction(hashNum);
  if (table->arr[hashIndx] == INT_MIN) {
    table->arr[hashIndx] = value;
    table->size++;
    return;
  }
  printf("Hash Code Number for %s already exist, choose another key\n", key);
}

// if lookUp return INT_MIN we know that there is no key in the table
// with that name else it return the value in that key cause in
// __initHash__ function we set all the elements INT_MIN by default
int lookUp(HashTable *table, const char *key) {

  int hashNum = hashCode(key);
  int hashIndx = multiplicativeHashFunction(hashNum);

  return table->arr[hashIndx];
}

// if to be deleted index value is INT_MIN we know that it is empty
// so it throw an error saying no deletion.
void deleteHash(HashTable *table, const char *key) {

  int hashNum = hashCode(key);
  int hashIndx = multiplicativeHashFunction(hashNum);

  if (table->arr[hashIndx] != INT_MIN) {
    table->arr[hashIndx] = INT_MIN;
    return;
  }
  printf("No key of %s match in Table , so no deletion.\n", key);
}
