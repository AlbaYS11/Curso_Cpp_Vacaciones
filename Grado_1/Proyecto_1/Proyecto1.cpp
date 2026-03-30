#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Producto  
{
    int clave;
    string nombre;
    double precio;
};

Producto *buscar(int clave, vector<Producto> &p) //Metodo que regresa un puntero de un solo producto
{
    for (int i = 0; i < p.size(); i++)
    {
        if (clave == p[i].clave)
        {
            return &p[i]; //Regresa la direccion de ese puntero, si la clave existe
        }
    }
    return nullptr; //Regresa un puntero nulo si no encuentra la clave existente
} 

void agregar(vector<Producto> &p)
{
    int clave;
    Producto aux; //Creando un struct

    cout << "Agregando productos." << endl;
    mostrarClaves(p);

    cout << "\nIngresa la clave unica del producto: " << endl;
    cin >> clave;

    while (buscar(clave, p) != nullptr) //Lo hace mientras sea diferente de nulo osea esa ya existe
    {                                   //Si es nulo significa que esa clave se puede tomar
        cout << "Clave invalida. Intenta otra vez: ";
        cin >> clave;
    } 

    aux.clave = clave;

    cout << "Ingresa el nombre del producto: " << endl;
    cin.ignore();
    getline(cin, aux.nombre);

    cout << "Ingresa el precio del producto: " << endl;
    cin >> aux.precio;

    p.push_back(aux); //Ingresa ese struct al vector(Array list)

    cout << "Producto agregado con exito." << endl;
}

int indice(int clave, vector<Producto> &p) //Regresa el indice si encuentra la clave si no -1
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

void mostrarClaves(const vector<Producto> &p)
{
    if (p.empty())
    {
        cout << "El inventario esta vacio.\n";
        return;
    }

    cout << "Lista de claves en uso:\n";
    for (const auto &prod : p) // auto deduce el tipo por ti (auto) y ademas usa el original sin copias (const)
        cout << prod.clave << '\n'; //Comillas simples un caracter
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

void Busqueda(vector<Producto> &p)
{
    int clave;
    cout << "Buscando el producto." << endl;
    mostrarTodo(p);

    cout << "\nIngresa la clave del producto a buscar:" << endl;
    cin >> clave;

    Producto *aux = buscar(clave, p); //Creamos un puntero que puede apuntar a esa direccion en memoria del vector

    if (aux != nullptr) //Si es diferente de nulo significa que lo encontro y existe, osea podemos mostrarlo
    {                   //Si es nulo no es diferente asi que no existe
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
    if (aux != -1) //Si es diferente de -1 significa que la clave existe y devuelve su indice
    {
        p.erase(p.begin() + aux); //borra del arraylist segun la direccion usando begin de inicio y sumando indices
        cout << "Producto eliminado con exito." << endl;
        return;
    }
    //Si es -1 no es diferente entonces no entra al if y no existe
    cout << "Ese producto no existe." << endl;
}

void modificar(vector<Producto> &p)
{
    int clave, opc;

    cout << "Modificando un producto." << endl;
    mostrarTodo(p);

    cout << "\nIngresa la clave del producto a modificar:" << endl;
    cin >> clave;
    Producto *aux = buscar(clave, p); //Igual devuelve nulo si no lo encuentra y un puntero, si lo encuentra

    if (aux != nullptr) //Si es diferente lo encontro y existe para modificarlo y mostrarlo
    {                   //Si es nulo no existe. No lo mostramos y modificamos
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
            //Usando esa direccion de memoria de ese puntero modificamos los atributos de ese struct en el vector
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

    do
    {
        cout << "\n--- MENU ---\n1. Agregar producto.\n2. Buscar producto." << "\n3. Modificar producto.\n4. Eliminar Producto.\n0. Salir." << endl;
        cin >> opc;
        cin.ignore(); //Para usar getline y no se coma el espacio

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

    return 0;
}
