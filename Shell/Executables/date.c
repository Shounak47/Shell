#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<string.h>
#include<time.h>

int main(int argc,char * argv[]){
	//printf("%s\n",argv[0]);
	//strcmp(argv[0],"..")==0
	if(argv[0]==NULL || strcmp(argv[0],"--debug")==0){
	
		time_t curtime; 
	    time(&curtime); 
	    printf("%s\n", ctime(&curtime));
		

	}else if(strcmp(argv[0],"-u")==0){
		struct tm *gtime;
	    time_t now;
	    time(&now);

	   
	    gtime = gmtime(&now);
	    printf("%s\n",asctime(gtime));

	}else{
		printf("Invalid flag option\n");

	}
	return 0;
}