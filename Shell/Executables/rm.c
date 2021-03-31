#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<errno.h>
int main(int argc,char * argv[]){
	//printf("%s\n",argv[0]);
	//printf("%s\n",argv[1]);
	int flag=atoi(argv[0]);
	if(flag==1){
		printf("Remove file?\n");
		char option[10];
		scanf("%[^\n]%*c",option);
		int res=0;

		if(strcmp(option,"yes")==0){
			res=remove(argv[1]);
		}
		if(res!=0){
		printf("%s\n",strerror(errno));
	}
		
		exit(0);
	
	}
	int res=0;
	res=remove(argv[1]);
	if(res!=0 && flag!=2){
		printf("%s\n",strerror(errno));
	}

	
	
	return 0;

}