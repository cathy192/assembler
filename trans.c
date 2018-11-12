#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	// check syntax 
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}


	else{
	char *str1=strtok(args,",");
        char *str2=strtok(str1,",");

	if( strcmp(str1[0],"%")==0 && strcmp(str2[0],"%")==0)//reg to reg
		strcpy(mcode, "a1");
	else if( strcmp(str1[0],"(")==0 && strcmp(str2[0],"%")==0)//mem to reg
		strcpy(mcode,"8b");
	else if( strcmp(str1[0],"-")==0 && strcmp(str2[0],"%")==0)//mem to reg
		strcpy(mcode,"8b");
	else if( strcmp(str1[0],"0")==0 && strcmp(str2,"%eax")==0)//mem to reg(eax)
		strcpy(mcode,"a1");
	else if( strcmp(str1,"%eax")==0 && strcmp(str2[0],"0")==0)//reg(eax) to mem
		strcpy(mcode,"a3");
	else if( strcmp(str1[0],"$")==0 && strcmp(str2[0],"%")==0)//immediate to reg
		strcpy(mcode,"b8");
	}
	return 1;	
}
