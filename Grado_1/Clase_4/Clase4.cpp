#include <iostream>

#include <random> //Para usar la generacion de randoms

using namespace std; //Declararse antes para usar random

//O agregarles std
random_device rd;                       // Fuente del random "entropia"
mt19937 gen(rd());                      // Declarando el generador de randoms con un "algoritmo"
uniform_int_distribution<> dist(0, 99); // Define la uniformidad, tipo y rango (int default)
//Debo poner este y cambiarlo si quiero otro tipo de datos o distribucion (Consultar)
//Puedo usar varios

int main()
{

    int numeros[5] = {0}; //El arreglo inicializado reserva 5 espacios de memoria de enteros

    int *p = numeros; // apuntando default al espacio 0

    cout << "Mostrando datos del arreglo: " << endl;

    //Length
    int size = sizeof(numeros) / sizeof(numeros[0]); //debemos dividirlo entre el primer elemento
    //Ya que regresa los bytes del tipo tipo de dato, no el tamaño entonces lo dividimos entre el 
    //Primero para obtener el tamaño de los elementos reales

    //5 * 4 bytes al dividirlo recibimos el tamaño sin importar el tipo de dato

    for (int i = 0; i < size; i++) // Para usar los valores
    { //Se puede llenar de manera tradicional pero podemos usar: 

    *(numeros + i) = dist(gen); //Generar randoms y usar aritmetica de punteros direcciones dentro del arreglo
    
    cout << "|" << *(p + i) << "|" ; //Sin endl no salta y no limpia

    }

    return 0;
}

//uniform_int_distribution.     Un solo generador de int y doubles se le coloca alias
//uniform_real_distribution

//uniform_real_distribution<double> distDouble(0.0, 500.0); declarando una double distinto
// uniform_int_distribution<> distInt(0, 99); //declarando uno de int aparte

//Se usan: dist(gen) pero cambiando el nombre de dist el generador es el mismo
