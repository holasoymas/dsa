# Dynamic Programming

The most challenging algorithmic problems involve optimization, where we seek
to find a solution that maximizes or minimizes some function.

Algorithms for optimization problems require proof that they always return
the best possible solution. Greedy algorithms that make the best local decision
at each step are typically efficient but usually do not guarantee global optimality.
Exhaustive search algorithms that try all possibilities and select the best always
produce the optimum result, but usually at a prohibitive cost in terms of time
complexity.

Dynamic programming combines the best of both worlds. It gives us a way to
design custom algorithms that systematically search all **possibilities (thus guaranteeing correctness)**
while storing results to avoid **recomputing (thus providing efficiency)**.
By storing the **consequences** of all possible decisions and using this
information in a systematic way, the total amount of work is **minimized**.

**_The trick is seeing whether the naive recursive
algorithm computes the same subproblems over and over and over again. If so,
storing the answer for each subproblems in a table to look up instead of recompute
can lead to an efficient algorithm._**

Dynamic programming is generally the right method for optimization problems
on **combinatorial objects that have an inherent left to right order among components.**
Left-to-right objects includes: **character strings, rooted trees, polygons, and integer sequences.**

# Caching Vs Computation

Dynamic programming is essentially a tradeoff of space for time. Repeatedly re-
computing a given quantity is harmless unless the time spent doing so becomes
a drag on performance. Then we are better off storing the results of the initial
computation and looking them up instead of recomputing them again.
The tradeoff between space and time exploited in dynamic programming is best
illustrated when evaluating recurrence relations such as the Fibonacci numbers. We
look at three different programs for computing them below.

## Approximate String Matching

**How can we search for the substring closest to a given pattern to compensate for spelling errors?**

To deal with inexact string matching, we must first define a cost
function telling us how far apart two strings are—i.e., a distance measure between
pairs of strings. A reasonable distance measure reflects the number of _*changes*_ that
must be made to convert one string to another.There are three natural types of
changes:

- **Substitution** : Replace a single character from pattern **_P_** with a different
  character in text **_T_** , such as changing _*“shot”*_ to _*“spot”*_.

- **Insertion** : Insert a single character into pattern **_P_** to help it match text **_T_** ,
  such as changing _*“ago”*_ to _*“agog”*_.

- **Deletion** : Delete a single character into pattern **_P_** to help it match text **_T_** ,
  such as changing _*“hour”*_ to _*“our”*_.

Properly posing the question of string similarity requires us to set the cost of
each of these string transform operations. Assigning each operation an equal cost
of 1 defines the **_edit distance_** between two strings.

```
// NOTE: MINIMUM EDIT DISTANCE ALGORITHM (string approx. algorithm)
//    | " " |  A  |  L  |  G  |  O  |  R  |  I  |  T  |  H  |  M   |
//    |------------------------------------------------------------|
// " "|  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9   |
//    |------------------------------------------------------------|
//  A |  1  |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8   |
//    |------------------------------------------------------------|
//  L |  2  |  1  |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7   |
//    |------------------------------------------------------------|
//  G |  3  |  2  |  1  |  0  |  1  |  2  |  3  |  4  |  5  |  6   |
//    |------------------------------------------------------------|
//  E |  4  |  3  |  2  |  1  |  1  |  2  |  3  |  4  |  5  |  6   |
//    |------------------------------------------------------------|
//  B |  5  |  4  |  3  |  2  |  2  |  2  |  3  |  4  |  5  |  6   |
//    |------------------------------------------------------------|
//  R |  6  |  5  |  4  |  3  |  3  |  2  |  3  |  4  |  5  |  6   |
//    |------------------------------------------------------------|
//  A |  7  |  6  |  5  |  4  |  4  |  3  |  3  |  4  |  5  |  6   |
//    |------------------------------------------------------------|
//
//  Here we want to change the word "algebra" to "algorithm" .
//  what is the minimum way we can change the word "algebra" to "algorithm" ?
//
//  Let "algebra" be P and "algorithm" be T.
//
//  Let i(row) and j(column) be the indexes of the box of DP(i,j) :
//
//  if P[i] == T[j]:
//     DP[i][j] = DP[i - 1][j - 1]  // copy the value of prev. diagonal
//
//  else :                              // take the min of three
//     A[MATCH] = DP[i - 1][j - 1] + 1  // copy the prev. diagonal + 1 (REPLACE)
//     A[DELETE] = DP[i - 1][j] + 1  // copy the prev. row + 1 (DELETE in P)
//     A[INSERT] = DP[i][j - 1] + 1  // copy the prev. col + 1 (INSERT in P)
//
// -> Ans will be at the last row of last column . Here it is 6
```
