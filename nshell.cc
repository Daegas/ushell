#include <iostream>
#include <vector> 
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <cstddef>


using namespace std;

bool is_space(char C){
  if (C==' ')return true;
  if (C=='\t')return true;
  return false;
}

void type_prompt(){
    cout<<"Daras's ushell$ ";
    cout.flush();
}

vector<string> read_command(){
    string command;
    string temp;
    getline(cin,command);
    vector<string> argv;//vector de cadenas

    //Convertirla

    unsigned i=0;

    //si 
   while(i<command.length()){
         
    
        temp.clear();
    
    //salta espacios
        while (!is_space(command[i])){
            temp.push_back(command[i]);
            i++;

    //si llegó al final de la isntrucción
            if(i==command.length()){
             argv.push_back(temp);
                return argv;    
            }
        }
    i++;
    argv.push_back(temp);
    }


    return argv;
}

char** new_exec_format(vector<string> argv){
    char** ret;
    char* str;

    ret=new char*[argv.size()+1];

    for(unsigned i=0; i<argv.size(); i++){
        str=new char [argv[i].length()+1];
        
        for (unsigned j=0;j<argv[i].length();j++){
            str[j]=argv[i][j];
        }
        str[argv[i].length()]=0;
        ret[i]=str;
        str=NULL;
    }
    ret[argv.size() +1]=0;
    return ret;
}



int main(){
    
    type_prompt();
    vector <string> args=read_command();
    char** argv = new_exec_format(args);

    //imprimir
    for (unsigned i=0;i<args.size();i++){
         // cout<<"["<<i<<"]NULL"<<endl;
         cout<<"["<<i<<"]:"<<args[i]<<endl;
    }
   
        
   cout<<"end"<<endl;
    return 0;
}
