#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<string.h>
#include<dirent.h>
#include<errno.h>

int main(int argc,char * argv[]){
	struct dirent *de;
	
    int flag=atoi(argv[0]);

	DIR *dr = opendir(argv[1]); 
  
    if (dr == NULL)  
    { 
        printf("%s\n",strerror(errno));
        
        return 0; 
    } 
  
    
    while ((de = readdir(dr)) != NULL){
    	if(flag==1){
    		printf("%s\n", de->d_name); 
    	}
    	if(flag==2 && strncmp(de->d_name,".",1)!=0){
    		printf("%llu ",de->d_ino);
			printf("%s\n", de->d_name); 
    	}
    	if(flag==0 && strncmp(de->d_name,".",1)!=0){
    		printf("%s\n", de->d_name); 
    	}

    		
    		
        	
    }
            
  
    closedir(dr);     
    return 0; 
	
	
}