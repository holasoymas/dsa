#include "hash_table_api.h"

// NOTE: First do __initHash__ or __initHashFNV__ depending on your table before
// inserting elements into that table

int main() {

  HashTable table, fnvTable;

  __initHash__(&table);
  __initHashFNV__(&fnvTable);

  insertHash(&table, "ramesh", 45);
  insertHash(&table, "rama", 23);
  insertHash(&table, "!..e", 23);
  insertHash(&table, "tomal", 23);

  int fst = lookUp(&table, "ramesh");
  int dst = lookUp(&table, "tamesh");

  deleteHash(&table, "tomal");
  deleteHash(&table, "rokaya");

  insertHashFNV(&fnvTable, "rahul", 44);
  insertHashFNV(&fnvTable, "mas123", 123);
  insertHashFNV(&fnvTable, "tamol", 49);
  insertHashFNV(&fnvTable, "river", 120);
  insertHashFNV(&fnvTable, "village", 350);

  int lookrahul = lookUpFNV(&fnvTable, "rahul");
  int lookMahul = lookUpFNV(&fnvTable, "mahul");

  deleteHashFNV(&fnvTable, "rahul");
  deleteHashFNV(&fnvTable, "mahul");

  printf("%d and %d and .\n", lookrahul, lookMahul);
  printf("%d and %d and .\n", fst, dst);

  return 0;
}
