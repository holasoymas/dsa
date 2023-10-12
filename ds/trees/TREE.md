
# Differences Between Tree, Binary Tree, and Binary Search Tree

| Data Structure | Description | Properties |
|----------------|-------------|------------|
| Tree | A non-linear data structure with a hierarchical relationship between its elements. It is composed of nodes, which hold data, and connections between nodes, known as edges. Each tree has a node designated as the root and the remaining nodes are partitioned into non-overlapping sets, each of which is a tree itself, known as a subtree. | No specific order. Can have any number of children nodes. |
| Binary Tree | A specific type of tree in which each node has at most two children, typically referred to as the left child and the right child. This is a specialized form of tree with two child nodes (left child and right child). It is a simple representation of data in a tree structure  | Each node can have at most two children: left and right. |
| Binary Search Tree | A binary search tree (BST) is a node-based binary tree data structure that has the following properties: The left subtree of a node contains only nodes with keys lesser than the node’s key. The right subtree of a node contains only nodes with keys greater than the node’s key. The left and right subtree each must also be a binary search tree. | Each node can have at most two children: left and right. Left child node's key is less than the parent's key. Right child node's key is greater than the parent's key. |
| Balanced Binary Tree | If the height of the left and right subtree at any node differs at most by 1, then the tree is called a balanced tree. |

# Tree Terminologies

| Term | Definition |
|------|------------|
| Root Node | The top node in a tree. |
| Leaf Node | A node with no children. |
|Edge | Edge is a connection between one node to another. It is a line between two nodes or a node and a leaf.|
|Path / Traversing | Path is a number of successive edges from source node to destination node. ( A – B – E – J  is path from node A to E )|
| Ancestors | For any node n, every node on the path from the root to n, excluding n, is an ancestor of n. |
| Siblings | Nodes with the same parent are called siblings. |
| Depth of a Node | The depth of a node is defined as the length of the path from the root to that node. Each edge adds 1 unit of length to the path |
| Height of a Node | The height of a node can be defined as the length of the longest path from the node to a leaf node of the tree. |
| Height of the Tree | The height of a tree is the length of the longest path from the root of the tree to a leaf node of the tree. ( Height of root node is always 0 ) |
| Degree of a Node | The total count of subtrees attached to that node is called the degree of the node. The degree of a leaf node must be 0. The degree of a tree is the maximum degree of a node among all the nodes in the tree. |

