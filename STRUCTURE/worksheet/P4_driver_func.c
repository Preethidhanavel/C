/*4. Function Pointers in Structures
Goal
Learn how to include and use function pointers inside structures for callback mechanisms and dynamic behavior in embedded systems.

Activity
Define a structure containing function pointers.
Initialize it with different functions and invoke them.
Use this setup to simulate a hardware driver interface with different behavior implementations.
Demonstrate dynamic assignment and execution of function pointers based on a condition or input.
Tip: Use typedef for cleaner function pointer declarations.*/
#include<stdio.h>
typedef void(*func)(void);
typedef struct st{
func init;
//func read;
//func write;
//func end;
}DRIVER;
void driver_init(void)
{
printf("In init function\n");
}
void driver_read(void)
{
printf("In read function\n");
}
void driver_write(void)
{
printf("In write function\n");
}
void driver_end(void)
{
printf("In end function\n");
}
int main()
{
DRIVER v;
int op;
while(1){
printf("Enter option 1.init 2.read 3.write 4.end\n");
scanf("%d",&op);
switch(op){
	case 1:v.init=driver_init;
	       //v.init();
	       break;
	case 2:v.init=driver_read;
	       //v.read();
	       break;
	case 3:v.init=driver_write;
	       //v.write();
	       break;
	case 4:v.init=driver_end;
	       //v.end();
	       break;
	default:printf("Invalid option\n");return 0;

}
v.init();
}
}
