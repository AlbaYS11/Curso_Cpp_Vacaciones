#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Persona //La Mochila de Datos. Es como un mini objeto
{
    int edad;
    string nombre;
    double precio;
};
//El signo sifnifica pasarle la direccion de memoria
void imprimirRecibo(vector<Persona>& l) //Usa directamente el de la referencia que le pasas como java
{
    if (!l.empty())
    {
        cout << "lista de invitados final: " << endl;
        for (const Persona& i : l) //Igual aqui. sin copias innecesarias e impidiendo modificacion
        {
            cout << i.nombre << endl;
        }
    }
}

int main()
{ 
    vector<Persona> lista; //Array list del struct
    int band;

    cout << "¿Deseas iniciar el registro?" << endl;
    cin >> band;
    cin.ignore(); //Elimina el espacio residual de antes para el getline

    while (band == 1)
    {
        int eTemp;
        string nTemp;
        double pTemp;

        Persona p; //Declaramos el struct, aca ya inicia

        cout << "¡Bienvenido! \nPara entrar haz el registro." << endl;
        cout << "Ingresa tu nombre:" << endl;
        getline(cin, nTemp); //Leer toda la linea, debemos eliminar la anterior

        cout << "Ingresa tu edad:" << endl;
        cin >> eTemp;

        if (eTemp >= 18)
        {

            cout << "Ingresa el precio de tu entrada:" << endl;
            cin >> pTemp;

            if (pTemp < 150)
            {
                cout << "Te falta varo, consigue mas." << endl;
            }
            else
            {
                //Llenamos el struct
                p.edad = eTemp;
                p.nombre = nTemp;
                p.precio = pTemp;
                cout << "\nResumen del ticket:\nNombre: " << p.nombre << "\nEdad: " << p.edad << "\nA pagar: " << p.precio << endl;
                lista.push_back(p); //Mostramos del original y agregamos a la lista
            }
    
        }
        else
        {
            cout << "¡Largo de aqui, niño!" << endl;
        }

        cout << "¿Deseas continuar?" << endl;
        cin >> band;
        cin.ignore();
    }

    imprimirRecibo(lista);

    cout << "\nRegistro terminado." << endl;
    return 0;
}
