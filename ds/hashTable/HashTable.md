# HASH TABLE
Hash tables are data structures that associate specific keys to corresponding values. These tables are typically implemented with an associative array to store the data. Moreover, they use a hash function to compute at which point of the array the data should be stored (the index).

So, we can understand a hash table as a key-value lookup. Thus, given a key associated with a value (data), we can recover the corresponding value through a quick lookup on the table.

```
 ------ -------
|key   | Value |
 ------ ------- 
|go    |  45   |
 ------ -------
|java  |  92   |
 ------ ------- 
|lua   |  05   |
 ------ -------
```

## HASHING 
Hashing is the process that takes a variable-length input and produces a fixed-length output value, called hash code or just hash.

```
           x                                          H                                           H(x)
 ---------------------------          ----------------------------------------           ------------------------
| Variable length input (x) | -----> | Hashing (using appriopriate algorithm) | ------> | Fixed length hash code | 
 ---------------------------          ----------------------------------------           ------------------------
```

There are different hashing algorithms :
* Multiplicative Method
* FNV-1a algorithm 
* Folding Method 
* Midsquare Method 

### Multiplicative Method 
The multiplicative method of hashing is a simple and fast method for generating hash values. The basic idea is to multiply the key by a constant and then take the fractional part of the result. This method is simple and fast, but it can lead to clustering if the keys have a common factor.

`H(k) = floor(SIZE_OF_HASHTABLE * frac(CONST_FRACTION * key))`

Here `frac` is `x - floor(x)`.
And choosing a good `CONST_FRACTION` is an important part of hash function which determine the efficiency of hash table. A good value can be mathmetical number golden ratio, approximately `0.618033988749895`.

```
//Helper function to convert string into numbers
int hashCode(const char *key) {

  int sum = 0;

  for (int i = 0; key[i] != '\0'; i++) {
    //Converting each character to ASCII and summing them  
    sum = sum + (int)key[i];
  }
  return sum;
}

int multiplicativeHashFunction(int key) {
  double r = key * CONST_FRACTION;

  // Extract the fractional part of r and store it in a variable f
  double f = r - (int)r;

  return (int)(SIZE * f);
}
```
### FNV-1a algorithm 
The FNV-1a (Fowler/Noll/Vo) hash function is an industry standard that has excellent distribution and is fast to compute. It uses an exclusive or (XOR) and multiplication to mix the bits of the key.

```
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
```
## Collision in Hash Table 
A collision is a situation where two different keys have the same hash value, which means they map to the same index in the hash table. This can cause problems for storing and retrieving data, as well as reducing the performance of the hash table.

There are mainly two ways to handle collisions :
* [Chaining](#chaining)
* [Open Addressing](#open-addressing)

### Chaining 
 This is a technique where each slot in the hash table contains a linked list of key-value pairs that have the same hash value. When a collision occurs, the new key-value pair is simply added to the end of the list. To search for a key, the hash function is used to find the index, and then the list is traversed until the key is found or the end is reached. This technique is simple and easy to implement, but it can cause memory overhead and slow down the search operation if the lists become too long.

```
Let's say our hash table look like this and suppose we want to insert a new key value pair python. But let's say python has same hash code as 
lua. In that situation we add the new data as a linked list at the end of the list.

 ------ -------
|key   | Value |
 ------ ------- 
|go    |  45   |
 ------ -------
|java  |  92   |
 ------ ------- 
|lua   |  05   |
 ------ -------
|elixir|  02   |
 ------ ------- 
|erlang|  50   |
 ------ -------

After inserting python

 ------ -------
|key   | Value |
 ------ ------- 
|go    |  45   |
 ------ -------
|java  |  92   |
 ------ -------       -------- -------
|lua   |  05   |---->| python |   27  |
 ------ -------       -------- -------
|elixir|  02   |
 ------ ------- 
|erlang|  50   |
 ------ -------

```

### Open Addressing 
This is a technique where all the key-value pairs are stored in the hash table itself, and no extra space is used. When a collision occurs, the hash table tries to find another empty slot to store the key-value pair, using a 
certain probing sequence.For example, `linear probing` checks the next slot in a circular manner until an empty slot is found. Other probing methods include `quadratic probing` and `double hashing`, which use different formulas to calculate the next slot. To search for a key, the same probing sequence is followed until either the key is found or an empty slot is encountered. This technique avoids memory overhead and can be faster than separate chaining, but it can cause clustering of occupied slots, which reduces the performance of the hash table.

```
Using linear probing,
Let's say we are again going to insert new key called python and somehow it has same hashCode as lua what do we do ?
We loop through the table to find the next empty slot and put that value there. 

 ------ -------
|key   | Value |
 ------ ------- 
|go    |  45   |
 ------ -------
|java  |  92   |
 ------ ------- 
|lua   |  05   |
 ------ -------
|elixir|  02   |
 ------ ------- 
|      |       |
 ------ -------
|  c   |  45   |
 ------ -------
|c++   |  09   |
 ------ ------- 
|      |       |
 ------ ------- 
|zig   |  12   |
 ------ ------- 
|rust  |  50   |
 ------ -------

For eg : Here python and lua has same hashCode so it start doing linear probing and find outs that the box after elixir is empty and put that key value pair there.

------ -------
|key   | Value |
 ------ ------- 
|go    |  45   |
 ------ -------
|java  |  92   |
 ------ ------- 
|lua   |  05   |
 ------ -------
|elixir|  02   |
 ------ ------- 
|python|  27   |
 ------ -------
|  c   |  45   |
 ------ -------
|c++   |  09   |
 ------ ------- 
|      |       |
 ------ ------- 
|zig   |  12   |
 ------ ------- 
|rust  |  50   |
 ------ -------

```

***NOTE : In our code here we haven't write any code to prevent from collision. So update your code***

