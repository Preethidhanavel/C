#include<stdio.h>
struct sensor{
int value;
char name[50];
};
int main()
{
struct sensor v[3];
int i;
for(i=0;i<3;i++)
scanf("%d%s",&v[i].value,v[i].name);
	for(i=0;i<3;i++)
printf("%d  %s\n",v[i].value,v[i].name);

}
