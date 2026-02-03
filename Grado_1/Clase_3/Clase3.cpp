#include <iostream>

using namespace std;


int main(){

    int saldo = 500;
    cout << "Mostrando saldo: " << saldo << endl;
    cout << "Mostrando la direccion en memoria: " << &saldo << endl; //signo &

    int* pSaldo = &saldo; //Declaramos una variable puntero y esta guarda la direccion del saldo
                //Usando el signo
    cout << "Mostrando saldo del puntero: " << pSaldo << endl;
    cout << "Mostrando la direccion en memoria del puntero: " << &pSaldo << endl;

    *pSaldo = 1000000; //Para usar el puntero debemos darle un *

    cout << "Imprimiendo el saldo otra vez: " << saldo << endl;

    return 0;
}