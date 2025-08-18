/*Invalid Pointer Arithmetic
Task: Explain why the following code snippet is invalid and what would happen if you try to compile/run it:
1.int arr[5];
2.int *p1 = &arr[1];
3.int *p2 = &arr[3];
4.int *p3 = p1 + p2; // Invalid operation
Expected output:
Error: Cannot add two pointers in C. Pointer addition is not defined.*/

/*ANSWER:
The reason pointer addition is disallowed is because it has no meaningful interpretation in memory addressing. 
If added two memory addresses together, the result wouldn't point to a valid or predictable memory location
*/