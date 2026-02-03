#include "Producto.h" //Importante incluir
#include <iostream> //Igual aqui declaraciones ya no faltan

int main()
{
    int opc;
    vector<Producto> inv;

    cargarArchivo(inv);

    do
    {
        cout << "\n--- MENU ---\n1. Agregar producto.\n2. Buscar producto.\n3. Modificar producto.\n4. Eliminar Producto.\n0. Salir." << endl;
        cin >> opc;
        cin.ignore();

        switch (opc)
        {
        case 1:
            agregar(inv);
            break;

        case 2:
            Busqueda(inv);
            break;

        case 3:
            modificar(inv);
            break;

        case 4:
            eliminar(inv);
            break;

        case 0:
            cout << "Has salido." << endl;
            break;

        default:
            cout << "ERROR. Ingresa una opcion valida." << endl;
            break;
        }

    } while (opc != 0);

    mostrarTodo(inv);

    guardarArchivo(inv);

        return 0;
}

//Tenemos varios archivos, para ejecutar debemos cambiar a la direccion y crear el ejecutable
//cd "C:\Users\adria\OneDrive\Documentos\Curso_Cpp\Clase_8"

//g++ main.cpp Producto.cpp -o inventario

//g++ → compilador
//main.cpp Producto.cpp → todos los archivos .cpp que quieres compilar
//-o inventario → nombre del programa ejecutable que se crea

