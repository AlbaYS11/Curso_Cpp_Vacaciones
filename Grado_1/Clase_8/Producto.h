#ifndef PRODUCTO_H  //Pregunta si existe para pasar o no. Si fue definido antes. (se pueden duplicar)
#define PRODUCTO_H  //define una bandera para registrarlo

//En un header (.h) va: Declaraciones, no la lógica pesada, struct / class, Prototipos de funciones,
//Constantes, typedef, enum

#include <iostream>
#include <vector>
#include <string> //Importante definir

//Pura declaracion
using namespace std;

//El struct se declara aqui
struct Producto {
    int clave;
    string nombre;
    double precio;
};

//Aqui van prototipos como las de java llamadas abstractas, no importa el orden
void guardarArchivo(const vector<Producto>& inv);
void cargarArchivo(vector<Producto>& inv);

Producto* buscar(int clave, vector<Producto>& p);

void mostrarClaves(const vector<Producto>& p);
void mostrarTodo(const vector<Producto>& p);
void mostrarNombres(const vector<Producto>& p);

void agregar(vector<Producto>& p);

int indice(int clave, vector<Producto>& p);

void Busqueda(vector<Producto>& p);
void eliminar(vector<Producto>& p);
void modificar(vector<Producto>& p);

#endif //Cierra