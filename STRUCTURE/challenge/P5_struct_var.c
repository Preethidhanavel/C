/*5.What happens if you assign one structure variable with pointer members to another? What are the implications for 
memory safety?

Shared pointer: Changes via a.p or b.p affect the same integer.
If one frees a.p or b.p (assuming it points to dynamically allocated memory), the other pointer becomes dangling —
 pointing to freed memory.
Assigning b = a does not copy the integer pointed to by p, just the pointer itself.*/
