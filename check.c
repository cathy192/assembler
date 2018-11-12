#include "myas.h"

int is_valid(char *op, char *args)
{
	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");

	char *str1=strtok(args,",");
	char *str2=strtok(str1,",");

	if(strcmp(str1[0],"$")==0)&&(strcmp(str2[0],"$")==0)//imm to imm
	||(strcmp(str1[0],"("==0)&&(strcmp(str2[0],"(")==0)// mem to mem
	return 0;
	else

	return 1;
}
