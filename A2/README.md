#Assignment 2 - Josephus problem

Solve the Josephus problem (https://en.wikipedia.org/wiki/Josephus_problem) using circular linked list. Design following functions:

- A function to create the initial army, ask user for number of soldiers in the army, insert each new soldier at the end of the list. Store soldiers name in the linked list, instead of just numbers.

- Write a function which starts with the first soldier in the list and finds the next target to kill by the Josephus permutation, delete that soldier from the circular linked list. Keep repeating, starting from the next soldier which was deleted, until only one soldier is left. Print names of all the soldiers as they are killed and also display the name of the soldier which survives.