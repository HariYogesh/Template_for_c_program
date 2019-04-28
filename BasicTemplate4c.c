#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main(int c,int **a)// command line argument for taking file name 
{

	char s[256];/*max size of file in linux*/
	if(c<2)/*command file_name checking */
	{

		printf("usage : ./a.out file_name\n");
		return 0;
	}
	strcpy(s,a[1]);/*copy to local buffer to perform operation*/
	/*if already user has given .c this condition skips appending .c to file extension*/
	if(strstr(s,".c")==NULL)
	strcat(s,".c");
	FILE *fp;
	/*to check file already present in present working directory*/
	fp=fopen(s,"r");
	if(fp==NULL)/*if not present then open and append basic info*/
	{
		fp=fopen(s,"w");
		fprintf(fp,"#include<stdio.h>\nint main()\n{\n\nreturn 0;\n}\n");
		fclose(fp);
	}
	execlp("vi","vi","m.c",NULL);/* open the file for user operation*/
		

		
	return 0;
}
