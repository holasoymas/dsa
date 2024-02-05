#include "graph.h"
#include <stdio.h>

int main() {

  Graph g;
  __initGraph__(&g);

  addNode(&g, 12);
  addNode(&g, 2);
  addNode(&g, 1);
  addNode(&g, 5);
  addNode(&g, 9);
  addNode(&g, 55);

  addEdge(&g, 2, 1);
  addEdge(&g, 0, 1);
  addEdge(&g, 1, 4);
  addEdge(&g, 4, 1);
  addEdge(&g, 1, 2);
  addEdge(&g, 1, 3);
  addEdge(&g, 3, 0);
  addEdge(&g, 5, 4);
  addEdge(&g, 4, 5);

  printGraph(&g);
  bft(&g, 0);
  dfs(&g, 4);

  return 0;
}
