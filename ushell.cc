#include <iostream>
#include <vector> 
#include <string>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

bool is_space(char C){
	if(C==’ ’)return true;
	if(C==’\t’)return true;
	return false;
	
}

void type_prompt(){
	cout <<”$”;
cout.flush();
type_prompt();
}

string read_command(){
	string command;
	string temp; //almacena los separados temporalente
	getline(cin,command);//lee y lo guarda en command
	vector<string> argv;//vector de cadenas
	
	//Para convertirla a otra cosa
	unsigned i=0;
	while(i<command.length()){
	
		//ignora espacios
		while(is_space(command[i]) ){
			i++;
			if(i== command.lenght())return argv;//fueron puros espacios
		}
		temp.clear();
		
		//mientras no encuentre un espacio, copia la cadena a temp
		while(!is_space(command[i]){
			temp.push_back( command[i]);
			i++;

			//si no encontro un espacio es decir llego al final de la instruccion
			if (i == command.lenght()){
			argv.push_back(temp); //agrega temp a argv
			return argv;
			}
		}
		argv.push_back(temp);//lo pone en la cadena
	}
	return argv
}

//Para pasar a exec
char** new_exec_format(vector<string> argv){
	char** ret;//arreglo de cadenas
	char* str;//cadena temporal

	ret=new char*[argv.size()+1];

	for (unsigned i=0; i<argv.size(); i++){
		start=new char [argv[i].length()+1];

		//llenarlo
		for (unsigned j=0; j<argv[i].length(); j++){
			str[j]=argv[i][j];
		}
		str[argv[i].length()]=0;
		ret[i]=str;//así lo exige el formato exec
		str=NULL;
	}
}

int main(){
	type_prompt(); //
	vector<<string>args=read_command

	char** argv =new:exec_format(args);
	
	//string command=read_command();
	//cout<<”comando:\””<<command<<”\”<<endl;

	cout<<”argv:””<<endl;
	for (unsigned i=0; i<args.size();i++){
		if (argv[i]!=NULL){
			cout<<”[”<<i<<”]:\”<<argv[i]<<”\”<<endl; 
		}
		else{
		cout<<”[”<<i<<”]NULL”<<endl; 
		}
	}


		return 0;

}
