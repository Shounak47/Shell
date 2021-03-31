#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>
#include<errno.h>


int main(int argc,char * argv[]){

	//argv[0]="/Users/shounakghatak/Desktop/test";
	//int res;mkdir(argv[0],07);
	//printf("%d\n",res);
	int res;
	int flag=atoi(argv[0]);
	if(flag==0){
		res=mkdir(argv[1],0766);

	}else if(flag==1){
		res=mkdir(argv[1],0777);

	}else if(flag==2){
		res=mkdir(argv[1],0766);
	}
	if(res==-1){
		printf("%s\n",strerror(errno));

	}


	return 0;
}