#include <iostream>
#include <thread>

using namespace std;

void thread1(){
	cout <<"hilo 1"<<endl;

}
void thread2(){
	cout <<"hilo 2"<<endl;

}

int main(){
	
	cout <<"main crea 2 hilos"<<endl;

	//std::thread t1();//Asi se crea el hilo, t1 es el nombre y adentro va una función
	thread t1(thread1); //tipo de clase, nombre de variable, parametros de la variable
	thread t2(thread2);
	
	cout << "main join" <<endl;
	t1.join();
	t2.join();
	cout << "termina main" <<endl;
	
	return 0;
	
}