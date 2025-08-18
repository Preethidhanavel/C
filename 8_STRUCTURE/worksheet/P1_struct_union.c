/*1.Structure vs Union in Embedded Systems
Goal
Understand how structures and unions differ in terms of memory layout, access, and use in embedded systems, 
particularly in data interpretation and memory saving.
Activity
Define a structure and a union with three different data types (e.g., char, int, float).
Print the size of each and compare.
Write values to each member and observe the behavior.
Map the union onto a byte buffer and visualize how different types share memory.
Document a scenario where only one data type is valid at a time (e.g., packet command structure).
Tip: Use sizeof() and printf() to track memory usage and value overlap.*/
#include<stdio.h>
#pragma pack(1)
struct st{
		int x;
		char ch;
		float f;
};
union ut{
		int y;
		char ch1;
		float f1;
};
int main()
{
		struct st s;
		s.x=4;
		s.ch='a';
		s.f=9.8;

		union ut u;
		u.y=9;
		u.ch1='b';
		u.f1=8.8;
		printf("sizeof(s) %ld\n",sizeof(s));
		printf("sizeof(u) %ld\n",sizeof(u));

		printf("Struct memb:%d  %c  %f\n",s.x,s.ch,s.f);
		printf("Union memb:%d  %c  %f\n",u.y,u.ch1,u.f1);
		char *p=(char*)&u;
		int i;
		for(i=0;i<sizeof(u);i++)
			printf("%d ",p[i]);
		struct st1{
		char id;
		union{
		short int s;
		float percent;
		}q;

		}st;

		printf("sizeof(st)%ld\n",sizeof(st));
		printf("sizeof(q)%ld\n",sizeof(st.q));

}
