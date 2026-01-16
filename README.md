Push Swap

📌 Description


push_swap is a project whose goal is to sort a stack of integers using a limited set of instructions and two stacks: A and B.
The challenge is to find the most efficient way possible (with the smallest number of moves) to sort the numbers in ascending order in stack A.

This project was developed following all norm rules and includes the bonus part.


🧠 Strategy Used


🔹 Sending from A to B — Chunks

To move numbers from stack A to stack B, I used the chunk strategy:

The stack is divided into blocks (chunks) based on the sorted indices of the numbers.

Numbers belonging to the current chunk are pushed to stack B.

Depending on the position of the number, rotations (ra, rra) are used to optimize movements.

This approach significantly reduces the number of operations for large inputs.

🔹 Returning from B to A — Turk Algorithm

To move numbers back from stack B to stack A, I used the Turk Algorithm:

Always selects the most advantageous number to move from B to A.

Calculates the cost of each move, considering simultaneous rotations (rr, rrr).

Ensures that elements return to A already close to their correct position.

This strategy helps keep the total number of operations low.


⭐ Bonus


The project includes the checker:

Reads a sequence of instructions from standard input.

Executes the instructions on the stacks.

Checks whether stack A is sorted and stack B is empty at the end.

Displays OK or KO depending on the result.

🛠️ Allowed Instructions

sa, sb, ss

pa, pb

ra, rb, rr

rra, rrb, rrr

▶️ How to Compile

make

To compile the bonus:

make bonus

▶️ How to Run

push_swap
./push_swap 3 2 1

checker
./push_swap 3 2 1 | ./checker 3 2 1
