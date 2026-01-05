#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Persona
{
    int edad;
    string nombre;
    double precio;
};

void imprimirRecibo(vector<Persona> l)
{
    if (!l.empty())
    {
        cout << "lista de invitados final: " << endl;
        for (Persona i : l)
        {
            cout << i.nombre << endl;
        }
    }
}

int main()
{
    vector<Persona> lista;
    int band;

    cout << "¿Deseas iniciar el registro?" << endl;
    cin >> band;
    cin.ignore();

    while (band == 1)
    {
        int eTemp;
        string nTemp;
        double pTemp;

        Persona p;

        cout << "¡Bienvenido! \nPara entrar haz el registro." << endl;
        cout << "Ingresa tu nombre:" << endl;
        getline(cin, nTemp);

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
                p.edad = eTemp;
                p.nombre = nTemp;
                p.precio = pTemp;
                cout << "\nResumen del ticket:\nNombre: " << p.nombre << "\nEdad: " << p.edad << "\nA pagar: " << p.precio << endl;
                lista.push_back(p);
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
