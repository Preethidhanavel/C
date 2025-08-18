/*10.Pointer and File I/O
Goal: Use pointers and dynamic memory to efficiently read and write data of variable sizes to files.
Activity:
Open a file for reading and writing.
Determine the size of the file or data to read.
Dynamically allocate a buffer to hold file data.
Use pointers to read the data into memory and write data back to a file.
Close the file and free allocated memory.*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
			FILE *fp=fopen("file1","w+");
			if(fp==NULL){
			printf("File doesn't exist\n");
			return 0;
			}
			int n;
			printf("Enter the size of file\n");
			scanf("%d",&n);
			char *p=(char *)malloc(n*sizeof(char));
			printf("enter the data\n");
			scanf(" %[^\n]",p);
			fputs(p,fp);
			rewind(fp);
			printf("Entered string is:%s\n",p);
			char c;
			printf("Data reading..\n");
			int size=0;
			while((c=fgetc(fp))!=EOF){
				size++;
				printf("%c",c);
			}
			printf("The sizeof file:%d\n",size);
			rewind(fp);
			char *q=(char *)malloc(size*sizeof(char));
			fgets(q,n,fp);
			rewind(fp);
			printf("Data stored in buffer is %s \n",q);
			fclose(fp);
			fp=NULL;
}
