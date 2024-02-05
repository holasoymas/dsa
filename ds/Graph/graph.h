#ifndef GRAPH
#define GRAPH

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VER 100
#define UNVISITED 0
#define VISITED 1

typedef struct Edge {
  int src, dest;
  struct Edge *next;
} Edge;

typedef struct Node {
  int data;          // node info
  struct Edge *next; // next Node on a list
} Node;

typedef struct Graph {
  Node *nodes[MAX_VER];
  int degree[MAX_VER]; // degree of each vertices
  int n_vertices;      // number of vertices in graph
  int n_edges;         // number of edges in graph
} Graph;

void __initGraph__(Graph *g);
void addNode(Graph *g, int data);
void addEdge(Graph *g, int src, int dest);
void printGraph(Graph *g);
void bft(Graph *g, int startingNode); // Breadth first traversal
void dft(Graph *g, int startingNode); // Depth first traversal
void dfs(Graph *g, int startingNode); // Depth first traversal

#endif // !GRAPH
