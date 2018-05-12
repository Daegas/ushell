#include <iostream>
#include <vector> 
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

#include<stdio.h>

using namespace std;

bool is_space(char C){
  if (C==' ')return true;
  if (C=='\t')return true;
  return false;
}

void type_prompt(){
    
    cout<<"Dara's ushell~"<<get_current_dir_name()<<" $ ";
    cout.flush();
}

int arg_length(char* str){
	int i=0;
    while (!is_space(str[i])){
	    i++;
    	if(str[i]==0)break;
    }
    return i;
}

int space_length(char* str){
	int i=0;
    while (is_space(str[i])){
	    i++;
    	if(str[i]==0)break;
    }
    return i;
}

int arg_count(char* str){
    char* s=str;
    int n=0;
    
    while (true){
        s+=space_length(s);
        if(s[n]==0)break; 
        if(s[0]==0)break;  
        n++;
        s+=arg_length(s);       
    }
    return n;
}


char** read_command(){
    string command;
    getline(cin,command); 
    char* str=&command[0];
    
    int n=arg_count(str);
    char** args=new char*[n+1];
    char* temp;
    
    unsigned i=0;
    
    while(true){
        str+=space_length(str);
        if(str[0]==0)break;

        int len = arg_length(str);
        temp=new char[len+1];

        for(int j=0; j<len ; j++) temp[j]=str[j];
        temp[len]=0;
        
        args[i]=temp;
        i++;

        str+=len;
        if(str[0]==0)break;
    
        

    }
    args[i]=NULL;
    return args;
}

int main(){
    string aux;
    char** argv;
    char* prog;
    pid_t child;  
        
    while(true){
        
        
        if(aux=="quit")break;
        if(aux=="exit")break;
        

        type_prompt();
        argv=read_command();
        prog=&argv[0][0];
        aux=prog;
   

        if(aux=="cd"){
        
            chdir(argv[1]);
            
            continue;
        }
        

        //implementar mkdir, mv, cal, cat, head, tail, touch, gcc,  y buscar otros
        

        child=fork();

        if(child==0){
            execvp(prog,argv);
        }

        else{
            waitpid(child,NULL,0);        
        }

        unsigned i=0;

        while(argv[i]!=NULL){
	    	delete[] argv[i];//libera cadenas
	    	i++;
        }
        delete [] argv;//libera vector

    }    
  
    if(child!=0)cout<<"Bye :)"<<endl;
    return 0;
}
