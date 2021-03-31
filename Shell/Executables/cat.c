#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<string.h>
#include <sys/stat.h>
#include<stdio.h>
#include<errno.h>

int main(int argc,char * argv[]){
	
	int flag=atoi(argv[0]);
	
	FILE *fptr;
	fptr=fopen(argv[1],"r");
	if(fptr==NULL){
		printf("%s\n",strerror(errno));
		//perror("File not opened");
		exit(0);
	}
	char dat[800];
	int row_num=1;
	while(fscanf(fptr,"%[^\n]\n",dat)!=EOF){ 
		if(flag==0){
			printf("%s\n",dat);
		}else if(flag==1){
			printf("%d %s\n",row_num,dat);
			row_num++;
		}else if(flag ==2){
			printf("%s$\n",dat);


		} 
   
   	

   } 
	printf("\n");
	return 0;
}