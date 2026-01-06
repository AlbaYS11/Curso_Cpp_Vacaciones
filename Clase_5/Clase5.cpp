#include <iostream>
#include <random>

using namespace std;

random_device rnd;
mt19937 gen(rnd());
uniform_int_distribution<int> dist(0, 99);

// Heap: memoria dinámica (más grande, pero más lenta y manual)
//Tú pides espacio prestado manualmente. NO se borra sola.

int main(){

   int tam;

   cout << "Introduce el tamaño del arreglo" << endl;
   cin >> tam;

   int* arr = new int[tam]; //Para definir un arreglo dinamico,
   //que puedes elegir su tamaño en ejecucion, pero...
   // int size = sizeof(arr) / sizeof(*(arr)); 
   //sizeof no funciona porque arr es un puntero, no un arreglo real

   for (int i = 0; i < tam; i++)
   {
   arr[i] = dist(gen);
   cout << i << ": " << * (arr + i) << endl;
   }
   
   //for(int i : arr) No se puede usar for-each porque el puntero no conoce el tamaño del arreglo

   delete []arr; //Liberamos la memoria del heap al dejar de usarlo IMPORTANTE

    return 0;
}

//Stack (Pila): Donde estabas trabajando. 
//Variables rápidas, automáticas, pero de tamaño fijo. Se borran solas al cerrar la función {}.

