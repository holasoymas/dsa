#include "../queue/queue.h"
#include "../stacks/stack.h"
// #include "../stacks/stack.h"
#include "graph.h"
#include <stdio.h>

void __initGraph__(Graph *g) {
  g->n_edges = 0;
  g->n_vertices = 0;

  for (int i = 0; i < MAX_VER; i++) {
    g->nodes[i] = NULL;
    g->degree[i] = 0;
  }
}

void addNode(Graph *g, int data) {

  if (g->n_vertices > MAX_VER) {
    printf("Graph is full : Void insertion\n");
    return;
  }

  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  // assign that graph index to its required node
  g->nodes[g->n_vertices] = newNode;
  g->n_vertices++;
}

void addEdge(Graph *g, int src, int dest) {
  if (src > g->n_vertices && dest > g->n_vertices) {
    printf("Invalid src or dest.\n");
    return;
  }

  Edge *newEdge = (Edge *)malloc(sizeof(Edge));
  newEdge->src = src;
  newEdge->dest = dest;
  newEdge->next = NULL;

  // Here we are adding edge to the node (kind of insert at begining in linked
  // list)
  newEdge->next = g->nodes[src]->next;

  g->nodes[src]->next = newEdge;

  g->n_edges++;
  g->degree[src]++;
}

void bft(Graph *g, int startingNode) {

  // Initializing queue
  Queue q;
  __queueinit__(&q);

  // setting all the nodes to 0 indicating unvisited nodes
  int visited[MAX_VER] = {UNVISITED};

  // add the starting node to the queue
  enQueue(&q, startingNode);

  printf("BFS : Traversal\n");

  // if the size of the queue is 0 , it indicate that all the nodes are visited
  while (q.size > 0) {
    // remove the first inserted data (FIFO)
    int removedQueue = deQueue(&q);

    // if that Node is only unvisited then only go to that node
    if (visited[removedQueue] == UNVISITED) {
      printf("%d <--", removedQueue);

      // after visiting there mark as VISITED
      visited[removedQueue] = VISITED;

      // loop through the neoghbours of selected Node and enQueue the unvisited
      Edge *neighbours = g->nodes[removedQueue]->next;
      while (neighbours != NULL) {
        if (visited[neighbours->dest] == UNVISITED) {
          enQueue(&q, neighbours->dest);
        }
        neighbours = neighbours->next;
      }
    }
  }

  // some unconnected graph are left behind so including them.
  for (int i = 0; i < g->n_vertices; ++i) {
    if (visited[i] == UNVISITED) {
      printf("%d <--", i);
      visited[i] = VISITED;
    }
  }
  printf("\n");
}

void dfs(Graph *g, int startingNode) {
  Stack s;
  __initStack__(&s);

  // setting all the nodes to 0 indicating unvisited nodes
  int visited[MAX_VER] = {UNVISITED};

  pushNum(&s, startingNode);

  printf("DFS : Traversal\n");

  while (!isEmpty(&s)) {

    int toRemoveStack = popNum(&s);

    if (visited[toRemoveStack] == UNVISITED) {
      printf("%d <-- ", toRemoveStack);
      visited[toRemoveStack] = VISITED;

      Edge *depth = g->nodes[toRemoveStack]->next;
      // printf("%p\n", depth);
      while (depth != NULL) {
        int dest = depth->dest;
        // printf("%d\n", dest);
        if (visited[dest] == UNVISITED) {
          pushNum(&s, dest);
        }
        depth = depth->next;
      }
    }
  }

  // some unconnected graph are left behind so including them.
  for (int i = 0; i < g->n_vertices; ++i) {
    if (visited[i] == UNVISITED) {
      printf("%d <--", i);
      visited[i] = VISITED;
    }
  }
  printf("\n");
}

void printGraph(Graph *g) {
  for (int i = 0; i < g->n_vertices; i++) {
    printf("Node %d. (%d) -> ", i, g->nodes[i]->data);
    Edge *edges = g->nodes[i]->next;
    while (edges != NULL) {
      printf("%d, ", edges->dest);
      edges = edges->next;
    }
    printf("\n");
  }
  printf("\n");
  printf("Total nodes = %d\n", g->n_vertices);
  printf("Total edges = %d\n", g->n_edges);
}
