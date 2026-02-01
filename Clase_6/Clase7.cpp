#include <iostream>
#include <vector>
#include <string>
#include <fstream> //Libreria de archivos
#include <sstream> //Libreria para usar string stream, Nos ayuda a leer o separar texto

using namespace std;

struct Producto
{
    int clave;
    string nombre;
    double precio;
};

void guardarArchivo(const vector<Producto> &inv) //Solo cambia por comas
{ // Funcion para guardar productos en un archivo

    ofstream archivo("inventario.txt"); // Crea un archivo nuevo sin importar
    // Puente entre progra y archivo, nombre variable

    if (archivo.is_open()) // Verifica si se pudo abrir o crear
    {
        for (const auto &p : inv)
        {
            archivo << p.clave << "," << p.nombre << "," << p.precio << endl; // Sintaxis guardar esa linea en el txt
        } //EN ESTE CASO SE PONEN COMAS

        archivo.close(); // Siempre cerrar el archivo para guardar

        cout << "--> Datos guardados en inventario.txt (CSV)." << endl;
    }
    else
    {
        cout << "Error: No se pudo crear el archivo." << endl;
    }
}

void cargarArchivo(vector<Producto> &inv) //funcion para abrir y guardar
{

    ifstream archivo("inventario.txt"); // Inicia el archivo para abrir 
    //IFSTREAM LEE DESDE EL ARCHIVO

    string linea; //CREAR UN STRING PARA LEER Y GUARDAR LINEA

    if (!archivo.is_open()) // Verifica si existe
    {
        cout << "--> No se encontro archivo previo. Iniciando inventario vacio." << endl;
        return;
    }

    Producto p; // Declaramos para guardar del archivo

    while (getline(archivo, linea)) //SE LEE TODA LA LINEA DEL ARCHIVO HASTA TERMINAR
    { // mientras de datos y los asignamos a los demas

        //PRIMERO OBTIENE TODA LA LINEA EN UN STRING, SE LA PASAMOS AL STREAM

        stringstream stream(linea); //LEE DESDE UNA CADENA DE TEXTO
        string campo; //LEE EL CAMPO HASTA ANTES DE LA ,

        //ACA EL STREAM LEE DESDE AHI HASTA ENCONTRAR LA COMA Y EL DATO DEL CAMPO SE QUEDA
        //EN LA CADENA, LA CUAL ASIGNA EL ATRIBUTO

        getline(stream, campo, ',');
        p.clave = stoi(campo); //CONVIERTE TEXTO A INT

        getline(stream, campo, ',');
        p.nombre = campo;

        getline(stream, campo, ',');
        p.precio = stod(campo); //A DOuBLE

        inv.push_back(p); // Meter al vector.
    }

    archivo.close();
    cout << "--> Se cargaron " << inv.size() << " productos del archivo." << endl;
}

Producto *buscar(int clave, vector<Producto> &p)
{
    for (int i = 0; i < p.size(); i++)
    {
        if (clave == p[i].clave)
        {
            return &p[i];
        }
    }
    return nullptr;
}

void mostrarClaves(const vector<Producto> &p)
{
    if (p.empty())
    {
        cout << "El inventario esta vacio.\n";
        return;
    }

    cout << "Lista de claves en uso:\n";
    for (const auto &prod : p)
        cout << prod.clave << '\n';
}

void mostrarTodo(const vector<Producto> &p)
{
    if (p.empty())
    {
        cout << "El inventario esta vacio.\n";
        return;
    }

    cout << "---LISTA---\n";
    for (int i = 0; i < p.size(); i++)
    {
        cout << i + 1 << ": "
             << p[i].clave << ". "
             << p[i].nombre << " $"
             << p[i].precio << '\n';
    }
}

void mostrarNombres(const vector<Producto> &p)
{
    if (p.empty())
    {
        cout << "El inventario esta vacio.\n";
        return;
    }

    cout << "Lista de nombres de productos:\n";
    for (const Producto &prod : p)
        cout << prod.nombre << '\n';
}


void agregar(vector<Producto> &p)
{
    int clave;
    Producto aux;
    cout << "Agregando productos." << endl;
    mostrarClaves(p);

    cout << "\nIngresa la clave unica del producto: " << endl;
    cin >> clave;

    while (buscar(clave, p) != nullptr)
    {
        cout << "Clave invalida. Intenta otra vez: ";
        cin >> clave;
    }

    aux.clave = clave;

    cout << "Ingresa el nombre del producto: " << endl;
    cin.ignore();
    getline(cin, aux.nombre);

    cout << "Ingresa el precio del producto: " << endl;
    cin >> aux.precio;

    p.push_back(aux);

    cout << "Producto agregado con exito." << endl;
}

int indice(int clave, vector<Producto> &p)
{
    for (int i = 0; i < p.size(); i++)
    {
        if (clave == p[i].clave)
        {
            return i;
        }
    }
    return -1;
}


void Busqueda(vector<Producto> &p)
{
    int clave;
    cout << "Buscando el producto." << endl;
    mostrarTodo(p);

    cout << "\nIngresa la clave del producto a buscar:" << endl;
    cin >> clave;

    Producto *aux = buscar(clave, p);

    if (aux != nullptr)
    {
        cout << aux->clave << ". "
             << aux->nombre << " $"
             << aux->precio << '\n';
        return;
    }

    cout << "Ese producto no existe." << endl;
}

void eliminar(vector<Producto> &p)
{
    int clave, aux;

    cout << "Eliminando un producto." << endl;
    mostrarTodo(p);

    cout << "\nIngresa la clave del producto a eliminar:" << endl;
    cin >> clave;

    aux = indice(clave, p);
    if (aux != -1)
    {
        p.erase(p.begin() + aux);
        cout << "Producto eliminado con exito." << endl;
        return;
    }

    cout << "Ese producto no existe." << endl;
}

void modificar(vector<Producto> &p)
{
    int clave, opc;

    cout << "Modificando un producto." << endl;
    mostrarTodo(p);

    cout << "\nIngresa la clave del producto a modificar:" << endl;
    cin >> clave;
    Producto *aux = buscar(clave, p);

    if (aux != nullptr)
    {
        cout << aux->clave << ". "
             << aux->nombre << " $"
             << aux->precio << '\n';

        cout << "Ingresa el numero del atributo a modificar:\n1. Nombre.\n2. Precio." << endl;
        cin >> opc;

        switch (opc)
        {
        case 1:
            cin.ignore();
            cout << "Ingresa el nuevo nombre:" << endl;
            getline(cin, aux->nombre);
            break;

        case 2:
            cout << "Ingresa el nuevo precio:" << endl;
            cin >> aux->precio;
            break;

        default:
            cout << "Esa opcion no existe." << endl;
            break;
        }

        return;
    }

    cout << "Ese producto no existe." << endl;
}

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