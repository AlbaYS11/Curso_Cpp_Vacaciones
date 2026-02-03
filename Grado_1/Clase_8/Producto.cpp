#include "Producto.h" // <--- IMPORTANTE: Conectar con el header
#include <fstream>
#include <sstream> //Se declara lo que se usa aca y ya despues no

//Aca se define lo que se dejo en header, el codigo

void guardarArchivo(const vector<Producto>& inv)
{
    ofstream archivo("inventario.txt");

    if (archivo.is_open())
    {
        for (const auto& p : inv)
            archivo << p.clave << "," << p.nombre << "," << p.precio << endl;

        archivo.close();
        cout << "--> Datos guardados en inventario.txt (CSV)." << endl;
    }
    else
        cout << "Error: No se pudo crear el archivo." << endl;
}

void cargarArchivo(vector<Producto>& inv)
{
    ifstream archivo("inventario.txt");
    string linea;

    if (!archivo.is_open())
    {
        cout << "--> No se encontro archivo previo. Iniciando inventario vacio." << endl;
        return;
    }

    Producto p;

    while (getline(archivo, linea))
    {
        stringstream stream(linea);
        string campo;

        getline(stream, campo, ',');
        p.clave = stoi(campo);

        getline(stream, campo, ',');
        p.nombre = campo;

        getline(stream, campo, ',');
        p.precio = stod(campo);

        inv.push_back(p);
    }

    archivo.close();
    cout << "--> Se cargaron " << inv.size() << " productos del archivo." << endl;
}

Producto* buscar(int clave, vector<Producto>& p)
{
    for (int i = 0; i < p.size(); i++)
        if (clave == p[i].clave)
            return &p[i];

    return nullptr;
}

void mostrarClaves(const vector<Producto>& p)
{
    if (p.empty())
    {
        cout << "El inventario esta vacio.\n";
        return;
    }

    cout << "Lista de claves en uso:\n";
    for (const auto& prod : p)
        cout << prod.clave << '\n';
}

void mostrarTodo(const vector<Producto>& p)
{
    if (p.empty())
    {
        cout << "El inventario esta vacio.\n";
        return;
    }

    cout << "---LISTA---\n";
    for (int i = 0; i < p.size(); i++)
        cout << i + 1 << ": "
             << p[i].clave << ". "
             << p[i].nombre << " $"
             << p[i].precio << '\n';
}

void mostrarNombres(const vector<Producto>& p)
{
    if (p.empty())
    {
        cout << "El inventario esta vacio.\n";
        return;
    }

    cout << "Lista de nombres de productos:\n";
    for (const auto& prod : p)
        cout << prod.nombre << '\n';
}

void agregar(vector<Producto>& p)
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

int indice(int clave, vector<Producto>& p)
{
    for (int i = 0; i < p.size(); i++)
        if (clave == p[i].clave)
            return i;

    return -1;
}

void Busqueda(vector<Producto>& p)
{
    int clave;

    cout << "Buscando el producto." << endl;
    mostrarTodo(p);

    cout << "\nIngresa la clave del producto a buscar:" << endl;
    cin >> clave;

    Producto* aux = buscar(clave, p);

    if (aux != nullptr)
    {
        cout << aux->clave << ". "
             << aux->nombre << " $"
             << aux->precio << '\n';
        return;
    }

    cout << "Ese producto no existe." << endl;
}

void eliminar(vector<Producto>& p)
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

void modificar(vector<Producto>& p)
{
    int clave, opc;

    cout << "Modificando un producto." << endl;
    mostrarTodo(p);

    cout << "\nIngresa la clave del producto a modificar:" << endl;
    cin >> clave;

    Producto* aux = buscar(clave, p);

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
            getline(cin, aux->nombre);
            break;

        case 2:
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


