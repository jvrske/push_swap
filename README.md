*This project has been created as part of the 42 curriculum by csilva.*

# Push Swap

## Description

**push_swap** is a sorting algorithm project whose objective is to sort a stack of integers in ascending order using a limited set of instructions and two stacks: **A** and **B**.

The main challenge of the project is to minimize the number of operations required to perform the sorting while respecting the allowed instructions.

This implementation fully complies with the 42 norm and includes the **bonus part**, featuring a checker program to validate the correctness of the operations.

### Strategy Used

#### Sending from A to B — Chunks

- The stack is divided into chunks based on the sorted index of each number.
- Elements belonging to the current chunk are pushed from stack A to stack B.
- Rotations (`ra`, `rra`) are used to bring the target elements to the top efficiently.
- This approach greatly reduces the number of operations for large inputs.

#### Returning from B to A — Turk Algorithm

- Selects the most cost-efficient element to move from B to A.
- Calculates the cost of each move, including combined rotations (`rr`, `rrr`).
- Ensures elements are reinserted into stack A close to their final position.

This combination keeps the total number of operations low and efficient.

## Instructions

### Compilation

Compile the mandatory part:

```bash
make
````

Compile the bonus (checker):

```bash
make bonus
```

### Execution

Run push_swap with a list of integers:

```bash
./push_swap 3 2 1
```

Run with the checker:

```bash
./push_swap 3 2 1 | ./checker 3 2 1
```

The checker outputs:

* `OK` if stack A is sorted and stack B is empty
* `KO` otherwise

### Allowed Instructions

* `sa`, `sb`, `ss`
* `pa`, `pb`
* `ra`, `rb`, `rr`
* `rra`, `rrb`, `rrr`

## Bonus

The bonus includes a **checker** program that:

* Reads instructions from standard input
* Executes them on stacks A and B
* Verifies that stack A is sorted and stack B is empty at the end

## Resources

### References

* 42 Push Swap subject
* Stack data structure documentation
* Sorting algorithms and complexity analysis
* Chunk-based sorting strategies
* Discussions and articles about the Turk Algorithm

### Use of AI

AI tools were used for:

* Understanding and reviewing algorithmic strategies
* Improving documentation clarity and English writing
* Structuring explanations for better readability

All algorithmic logic, optimizations, and code implementation were written manually.