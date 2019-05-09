# Push_swap

This project is about sorting data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed I had to manipulate various types of algorithms 
and choose the one (of many) most appropriate solution for an optimized data sorting.

To write a sorting algorithm is always a very important step in a coder’s life, 
because it is often the first encounter with the concept of complexity.
Sorting algorithms, and their complexities are part of the classic questions discussed
during job interviews.

The learning objectives of this project are rigor, use of C and use of basic algorithms. 
Especially looking at the complexity of these basic algorithms.
Sorting values is simple. To sort them the fastest way possible is less simple, 
especially because from one integers configuration to another, the most efficient sorting algorithm can differ.

## Instruction set

Code	| Instruction			| Action
--------|-----------------------|----------------------------------------------
`sa`	| swap a				| swaps the 2 top elements of stack a
`sb`	| swap b				| swaps the 2 top elements of stack b
`ss`	| swap a + swap b		| both `sa` and `sb`
`pa`	| push a				| moves the top element of stack b at the top of stack a
`pb`	| push b				| moves the top element of stack a at the top of stack b
`ra`	| rotate a				| shifts all elements of stack a from bottom to top
`rb`	| rotate b				| shifts all elements of stack b from bottom to top
`rr`	| rotate a + rotate b	| both `ra` and `rb`
`rra`	| reverse rotate a		| shifts all elements of stack a from top to bottom
`rrb`	| reverse rotate b		| shifts all elements of stack b from top to bottom
`rrr`	| reverse rotate a + reverse rotate b	| both `rra` and `rrb`

 Check out the [subject](https://github.com/pavel1shatalov/42.Moscow/tree/master/files/subjects)
