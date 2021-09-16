# Linked List
## What is a Linked List?
A linked list is a linear data structure. It consists of a sequence of nodes where each node keeps data and 1 or 2 pointers to previous or nexts nodes. A linked list is a self-referenced data type because it contains a link to another data of the same type.
<img src="../images/linked_lists_variants.jpg" width="75%" />

Some times the data field of a node can be another linked list. Through this mechanism, we can build many data structures linked with lists.

## Advantages
Items can be inserted into a list indefinitely using dynamic memory whereas an array will sooner or later fill up or need to be resized because it uses static memory.

Adding an element in the first and last position is efficient because in the Linked List you always know who is the first and the last node, therefore adding an element would not imply going through the list.

Removing an item from the list is quite simple as you don't need to rearrange the items in the list to maintain order because each item knows its previous and next. On the other hand, removing an element in an array is complicated because it would imply reorganizing the elements again to not leave gaps in the array.

## Disadvantages
Linked lists only allow sequential access to elements while arrays allow random access. In an array you just need the index to have direct access to the element. On the other hand, with linked list is inefficient because you would need to go through the list sequentially searching for the index given. Sequential access in vectors is also faster than in linked lists.

## Linked Lists operations and Time Complexity
| Operation    | Time Complexity |
| ------------ | --------------- |
| AddFront     | O(1)            |
| DeleteFront  | O(1)            |
| AddBack      | O(1)            |
| DeleteBack   | O(1)            |
| Search       | O(n)            |
| Nth          | O(n)            |

## Real life examples

