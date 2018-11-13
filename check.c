#include "myas.h"

int is_valid(char *op, char *args)
{
	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");

	char index[40],des[40];
	int k;
	for(int i=0;i<strlen(args);i++)
	{
		if(args[i]==','){
			break;
		}
		index[i]=args[i];
		k=i;
	}
	for(int j=k+2;j<strlen(args);j++)
		des[j-k-2]=args[j];


	if(des[0]=='$')	return 0;
	else if(index[0]=='(' &&des[0]=='(') return 0;
	else if(index[0]=='(' &&des[0]=='0') return 0;
	else if(index[0]=='0' &&des[0]=='(') return 0;
        else if(index[0]=='0' &&des[0]=='0') return 0;
	else if(index[0]=='-' &&des[0]=='(') return 0;
        else if(index[0]=='-' &&des[0]=='0') return 0;


	else return 1;
}
