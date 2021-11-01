# Array Binary Tree
A binary tree is basically a tree in which each node can have from 0 up to 2 children as the limit. There are many ways to implement binary trees in the code, one of them is by using an Array. Then, we will show some simple formulas to explain how.
#### Formulas
- Root = index 1
- Left Node = index*2
- Right Node = index*2+1
- Ancestor = index/2
- Number of nodes = (2^N)-1

These formulas just work if we start in index 1 of the array.

<img src="../../images/array_binary_tree_example.jpg" width="80%" />

Each is node is stored in a specific position of the array. Basically, this is an Array of Nodes.