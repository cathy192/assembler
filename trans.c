#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	char index[20]={"\0"},des[20]={"\0"};

	int k=0;
	// check syntax 
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}


	else{
	//char index[20],des[20];

	for(int i=0;i<strlen(args);i++){
		if(args[i]==',')
			break;
		index[i]=args[i];
		k=i;
	}

	for(int j=k+2;j<strlen(args);j++){
	
			des[j-k-2]=args[j];
	}

	//printf("index:%s des:%s\n",index,des);

	if( index[0]=='0' &&index[1]=='x'){
		if(des[2]=='a'&&des[3]=='x')
		strcpy(mcode, "a1");
	}
	else if( index[0]=='('|| index[strlen(index)-1]==')'){  
		strcpy(mcode,"8b");
	}
	else if( index[0]=='%'&&index[1]=='e'){
			if(des[0]=='%'&&des[1]=='e'){
			strcpy(mcode,"89");}
	}
	else if( index[0]=='%'&&index[1]=='e'){
		if(des[0]=='0'&&des[1]=='x'){
		strcpy(mcode,"a3");}
	}
	else if( index[0]=='$'){
		
			if(des[2]=='a'&&des[3]=='x')
				strcpy(mcode,"b8");
 
 			else if(des[2]=='b'&&des[3]=='x')
                                 strcpy(mcode,"bb");

			else if(des[2]=='c'&&des[3]=='x')
				strcpy(mcode,"b9");
			else  if(des[2]=='d'&&des[3]=='x')
				 strcpy(mcode,"ba");
			else if(des[2]=='s'&&des[3]=='p')
				 strcpy(mcode,"bc");
			else if(des[2]=='b'&&des[3]=='p')
				 strcpy(mcode,"bd");
			else if(des[2]=='s'&&des[3]=='i')
                                 strcpy(mcode,"be");
			else if(des[2]=='d'&&des[3]=='i')
	                        strcpy(mcode,"bf");
	}
		else  strcpy(mcode,"error");
	
		
	}
	printf("index:%s des:%s\n",index,des);
	return 1;	
}
