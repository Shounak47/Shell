
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include<string.h>
#include <sys/stat.h>
#include <errno.h> 
#define MAX 1000
char str[MAX];
char working_direct[500];
int hist_length=0;


void cd(char * token){
	//printf("%s\n",token);
    if(token==NULL){
        return;
    }
    if(strncmp(token,"~",3)==0){
    	chdir("/Users/shounakghatak");
    	return;
    }
    if(strncmp(token,"..",2)==0){
    	chdir("..");
    	return;
    }
    
    //token=strtok(NULL," ");
    char addr[500];
    strcpy(addr,getcwd(working_direct,500));
    strcat(addr,"/");
    strcat(addr,token);

    int res=chdir(token);
    if(res==-1){
        printf("%s\n",strerror(errno));
        //printf("Invalid Address\n");
    }
}
void pwd(){
    printf("%s\n",getcwd(working_direct,500));
}

void echo(char *token){
	//printf("%s",token);
	if(token==NULL){
		return;
	}
    int flag=0;
    if(strcmp(token,"-n")==0){
        flag=1;

    }
    if(strcmp(token,"-E")==0){

        //token=token+3;
        token=strtok(NULL, "\n");
        while(token!=NULL){
            printf("%s\n",token);
            token = strtok(NULL, "\n"); 
        }
        //printf("reached\n");

        
        return;
    }
    if(flag==1){
        token = strtok(NULL, " "); 
    }

    while (token != NULL) {
            
            printf("%s ",token);

        
            token = strtok(NULL, " "); 
            //word++;
        }
    if(flag==0){
        printf("\n");
    }
    
}

void hist(char *token){
    if(token==NULL){
        FILE *fptr1=fopen("/Users/shounakghatak/Desktop/Shell/hist.txt","r");
       char dat[1000];
       while(fgets(dat,sizeof(dat),fptr1)){
            
            char *token1;
            
            token1=strtok(dat,",");
            
            
            while(token1!=NULL){
                printf("%s",token1);
                token1=strtok(NULL," "); 
            }
            
        }
        printf("\n");
        return;
    }else if(strcmp(token,"-c")==0){
        FILE *fptr1=fopen("/Users/shounakghatak/Desktop/Shell/hist.txt","w");
        fclose(fptr1);

    }else{
        int lim=hist_length-atoi(token)+1;
        int row_num=1;
        FILE *fptr1=fopen("/Users/shounakghatak/Desktop/Shell/hist.txt","r");
       char dat[1000];
       while(fgets(dat,sizeof(dat),fptr1)){
            
            char *token1;
            
            token1=strtok(dat,",");
            
            
            while(token1!=NULL){
                if(row_num>=lim){
                    printf("%s",token1);
                }
                
                token1=strtok(NULL," "); 
            }
            row_num++;
            
        }
        printf("\n");




    }

}
void date(char * token){
	
	int pid=fork();
	if(pid<0){
		printf("Unable to spawn child process\n");
		return;
	}else if(pid==0){

		
		int res=execl("/Users/shounakghatak/Desktop/Shell/Executables/date",token,(char*)NULL);
		if(res!=0){
			printf("%s\n",strerror(errno));
		}
		exit(0);

	}else{
		wait(NULL);
		return;
	}
}

void ls(char * token){
	int pid=fork();
	if(pid<0){
		printf("Unable to spawn child's process\n");
		return;

	}else if(pid==0){
		int res;
		if(token==NULL){
			res=execl("/Users/shounakghatak/Desktop/Shell/Executables/ls","0",getcwd(working_direct,500),(char*)NULL);

		}else if(strncmp(token,"-a",2)==0){
			token=strtok(NULL," ");
			if(token==NULL){
				res=execl("/Users/shounakghatak/Desktop/Shell/Executables/ls","1",getcwd(working_direct,500),(char*)NULL);

			}else{
				char addr[500];
				strcpy(addr,getcwd(working_direct,500));
				strcat(addr,token);
				res=execl("/Users/shounakghatak/Desktop/Shell/Executables/ls","1",addr,(char*)NULL);

			}
		}else if(strncmp(token,"-i",2)==0){
			token=strtok(NULL," ");
			if(token==NULL){
				res=execl("/Users/shounakghatak/Desktop/Shell/Executables/ls","2",getcwd(working_direct,500),(char*)NULL);

			}else{
				char addr[500];
				strcpy(addr,getcwd(working_direct,500));
				strcat(addr,token);
				res=execl("/Users/shounakghatak/Desktop/Shell/Executables/ls","2",addr,(char*)NULL);

			}


		}else if(strncmp(token,"/",1)==0){
			char addr[500];
			strcpy(addr,getcwd(working_direct,500));
			strcat(addr,token);
			res=execl("/Users/shounakghatak/Desktop/Shell/Executables/ls","0",addr,(char*)NULL);

		}
		if(res!=0){
			printf("%s\n",strerror(errno));
		}

		exit(0);

	}else{
		wait(NULL);
		return;
	}
}
void cat(char *token){
	int pid=fork();
	if(pid<0){
		printf("Unable to spawn child's process\n");
		return;

	}else if(pid==0){
		int res;
		if(token==NULL){
			printf("Missing file name\n");
			exit(0);

		}else if(strncmp(token,"-n",2)==0){
			token=strtok(NULL," ");
			if(token==NULL){
				printf("Missing file name\n");
				exit(0);

			}else{
				char addr[500];
				strcpy(addr,getcwd(working_direct,500));
				strcat(addr,"/");
				strcat(addr,token);
				res=execl("/Users/shounakghatak/Desktop/Shell/Executables/cat","1",addr,(char*)NULL);

			}
		}else if(strncmp(token,"-e",2)==0){
			token=strtok(NULL," ");
			if(token==NULL){
				printf("Missing file name\n");
				exit(0);

			}else{
				char addr[500];
				strcpy(addr,getcwd(working_direct,500));
				strcat(addr,"/");
				strcat(addr,token);
				res=execl("/Users/shounakghatak/Desktop/Shell/Executables/cat","2",addr,(char*)NULL);

			}


		}else{
			char addr[500];
			strcpy(addr,getcwd(working_direct,500));
			strcat(addr,"/");
			strcat(addr,token);
			res=execl("/Users/shounakghatak/Desktop/Shell/Executables/cat","0",addr,(char*)NULL);

		}
		if(res!=0){
			printf("%s\n",strerror(errno));
		}

		exit(0);

	}else{
		wait(NULL);
		return;
	}
}
void makdir(char * token){
	int pid=fork();
	if(pid<0){
		printf("Unable to spawn child's process\n");
		return;

	}else if(pid==0){
		int res;
		if(token==NULL){
			printf("Missing file name\n");
			exit(0);

		}else if(strncmp(token,"-m777",5)==0){
			token=strtok(NULL," ");
			if(token==NULL){
				printf("Missing file name\n");
				exit(0);

			}else{
				char addr[500];
				strcpy(addr,getcwd(working_direct,500));
				strcat(addr,"/");
				strcat(addr,token);
				res=execl("/Users/shounakghatak/Desktop/Shell/Executables/mkdir","1",addr,(char*)NULL);

			}
		}else if(strncmp(token,"-v",2)==0){
			token=strtok(NULL," ");
			if(token==NULL){
				printf("Missing file name\n");
				exit(0);

			}else{
				char addr[500];
				strcpy(addr,getcwd(working_direct,500));
				strcat(addr,"/");
				strcat(addr,token);
				res=execl("/Users/shounakghatak/Desktop/Shell/Executables/mkdir","2",addr,(char*)NULL);

			}


		}else{
			char addr[500];
			strcpy(addr,getcwd(working_direct,500));
			strcat(addr,"/");
			strcat(addr,token);
			res=execl("/Users/shounakghatak/Desktop/Shell/Executables/mkdir","0",addr,(char*)NULL);

		}
		if(res!=0){
			printf("%s\n",strerror(errno));
		}

		exit(0);

	}else{
		wait(NULL);
		return;
	}
}
void re_d(char * token){
	int pid=fork();
	if(pid<0){
		printf("Unable to spawn child's process\n");
		return;

	}else if(pid==0){
		int res;
		if(token==NULL){
			printf("Missing file name\n");
			exit(0);

		}else if(strncmp(token,"-i",2)==0){
			token=strtok(NULL," ");
			if(token==NULL){
				printf("Missing file name\n");
				exit(0);

			}else{
				char addr[500];
				strcpy(addr,getcwd(working_direct,500));
				strcat(addr,"/");
				strcat(addr,token);
				res=execl("/Users/shounakghatak/Desktop/Shell/Executables/rm","1",addr,(char*)NULL);

			}
		}else if(strncmp(token,"-f",2)==0){
			token=strtok(NULL," ");
			if(token==NULL){
				printf("Missing file name\n");
				exit(0);

			}else{
				char addr[500];
				strcpy(addr,getcwd(working_direct,500));
				strcat(addr,"/");
				strcat(addr,token);
				res=execl("/Users/shounakghatak/Desktop/Shell/Executables/rm","2",addr,(char*)NULL);

			}


		}else{
			char addr[500];
			strcpy(addr,getcwd(working_direct,500));
			strcat(addr,"/");
			strcat(addr,token);
			res=execl("/Users/shounakghatak/Desktop/Shell/Executables/rm","0",addr,(char*)NULL);

		}
		if(res!=0){
			printf("%s\n",strerror(errno));
		}

		exit(0);

	}else{
		wait(NULL);
		return;
	}
}



int main(){
    FILE *fptr1=fopen("/Users/shounakghatak/Desktop/Shell/hist.txt","w");
    fclose(fptr1);
	
	while(1){
		printf(">");
        scanf("%[^\n]%*c", str);
		//fgets(str, MAX, stdin);
       FILE *fptr;
       fptr = fopen("/Users/shounakghatak/Desktop/Shell/hist.txt","a");
       fprintf(fptr,"%s\n",str);
       hist_length++;
       fclose(fptr);
		
		char* token=strtok(str," ");
        
        if(strncmp(token,"echo",4)==0){
            token = strtok(NULL, " "); 
            echo(token);


        }else if(strncmp(token,"cd",2)==0){
            token = strtok(NULL, " ");
            cd(token); 

        }else if(strncmp(token,"history",7)==0){
            token = strtok(NULL, " ");
            hist(token);


        }else if(strncmp(token,"pwd",3)==0){
            pwd();

        }else if(strncmp(token,"ls",2)==0){
        	token = strtok(NULL, " ");
        	ls(token);

        }else if(strcmp(token,"cat")==0){
        	token = strtok(NULL, " ");
        	cat(token);

        }else if(strcmp(token,"date")==0){
        	token = strtok(NULL, " ");
        	date(token);

        }else if(strcmp(token,"rm")==0){
        	token = strtok(NULL, " ");
        	re_d(token);

        }else if(strcmp(token,"mkdir")==0){
        	token = strtok(NULL, " ");
        	makdir(token);


        }else if(strncmp(token,"exit",4)==0){
            exit(0);

        }else{
            printf("Command not recognised\n");
        }

	}
    
	return 0;
}