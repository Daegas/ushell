//para quitar el problema de muthilos
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
//candado de ambito global
//para que todos los hilos puedan verlos
mjutex candado;

void thread1(){
	candado.lock();
	cout <<"hilo 1"<<endl;
	candado.unlock();

}
void thread2(){
	candado.lock();
	cout <<"hilo 2"<<endl;
	candado.unlock();
	

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