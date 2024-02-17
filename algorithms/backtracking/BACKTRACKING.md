# Terminologies used in Backtracking

- `Candidate` : A **candidate** is a **potential choice** or element that can be added to the current solution. Eg : [1,2,3,4,5]. Possible candidate from **even numbers** are only [2,4].

- `Constraints` : **conditions** that must be `met/satisfy` by **potential solutions** to a problem.

- `Configurations` : Representations or arrangements of elements in a specific way.

- `Solution` : The solution is a valid and complete configuration that satisfies all problem constraints.

- `Search Space` : The entire set of possible **configurations or states** that can be explored during the search for a solution.

- `Solution Space` : The **subset of the search space** that **contains configurations satisfying the problem's** requirements or constraints.

- `Partial Solution` : A partial solution is an **intermediate or incomplete configuration** being constructed during the backtracking process.

- `Feasible Solution` : A solution that **satisfies all the constraints** of the problem.

- `Decision Point` : A decision point is a specific step in the algorithm where a candidate is **chosen and added** to the partial solution or removed if not satisfied.

- `Decision Space` : The set of all the Possible **candidates or choices** at each decision point.

- `Backtrack` : Backtracking involves undoing previous decisions and returning to a prior decision point to explore other posibilities.

- `Dead End` : A situation in a partial solution where it is not possible to find a valid solution, and backtracking is required.

- `Optimal Solution` : In optimization problems, the optimal solution is the **best possible solution** among other solutions.

- `Pruning` : Eliminating branches or subtrees of the search space that cannot lead to a valid solution.

**Pruning is the technique of cutting off the search the instant we have established that
a partial solution cannot be extended into a full solution. For traveling salesman, we seek
the cheapest tour that visits all vertices. Suppose that in the course of our search we find
a tour `t` whose cost is `C(t)` . Later, we may have a partial
solution `a` whose edge sum `C(A) > C(t)`.**

**Is there any reason to continue exploring this node ?**

**No, because any tour with this prefix `a(1) , . . . , a(k)` will have cost greater than
tour `t`, and hence is doomed to be nonoptimal.**

**Cutting away such failed partial tours as soon as possible can have an enormous impact on running time.**

# BACKTRACKING

Backtracking is a systematic way to iterate through all the possible configurations of a **search space**.
These **configurations** may represent all possible arrangements of objects (permutations) or all possible
ways of building a collection of them (subsets). Other situations may demand enumerating all spanning trees of a graph,
all paths between two vertices, or all possible ways to partition vertices into color classes.

`What these problems have in common is that we must generate each one possible configuration exactly once. Avoiding both repetitions and missing configurations means that we must define a systematic generation order.`

## Steps to solve a combinatorial / Backtracking problems

1. We will model our combinatorial search solution as a `Vector a = [a(1), a(2), a(3), ..., a(n)]` where each `a(i)` is selected from a finite ordered set `S(i)` .
   Such a vector might represent an arrangement where `a(i)` contains the `i(th)` element of the permutation.
   Or, the vector might represent a given subset `S` where `a(i)` is true if an only if the `i(th)` of the **universe** is in `S`.
   The vector can even represent a sequence of moves in a game or a path in a graph, where `a(i)` contains the `i(th)` event in the sequence.

2. At each step in the backtracking algorithm, we try to extend a given partial solution `a = [a(1), a(2), a(3), ... , a(k)]` by adding another element at the end.
   **After extending, we must test whether what we now have is a solution**: 1. If so we should print it or count it or do what ever the final solution should do. 2. If not, we must check whether the partial solution is still potentially
   extendible to some complete solution.

## Use this utilities functions to make backtracking problems more simple

1. **`is_a_solution(a, k, n)`** - This **_Boolean function_** tests whether the first `k`
   elements of **vector / array** `a` from a complete solution for the given problem. The last
   argument, input, allows us to pass general information into the routine. We
   can use it to specify `n`**—the** size of a target solution.

2. **`construct candidates(a,k,input,c,ncandidates)`** - This routine fills an
   array `c` with the complete set of possible candidates for the ` k`**th** position of
   `a`, given the contents of the first `k − 1` positions. The number of candidates
   returned in this array is denoted by **ncandidates**. Again, input may be used
   to pass auxiliary information.

3. **`process solution(a,k,input)`** - This routine prints, counts, or however
   processes a complete solution once it is constructed.

4. **`make_move(a,k,input) and unmake_move(a,k,input)`** - These routines enable
   us to modify a data structure in response to the latest move, as well as
   clean up this data structure if we decide to take back the move. Such a data
   structure could be rebuilt from scratch from the solution **vector / array** `a`
   as needed,but this is inefficient when each move involves incremental changes
   that can easily be undone.
