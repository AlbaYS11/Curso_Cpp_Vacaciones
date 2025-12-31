#include <iostream> //Para poder usar System input y output osea cin y cout
#include <string>   //Para poder usar strings comodamente
// Import

using namespace std; // Para poder usar cin, cout y string sin alias, es la caja de herramientas

int main()
{

    int edad;
    string nombre;
    double precio;

    cout << "¡Bienvenido! \nPara entrar haz el registro." << endl;
    cout << "Ingresa tu nombre:" << endl;
    cin >> nombre; // Corta espacios

    cout << "Ingresa tu edad:" << endl;
    cin >> edad;

    if (edad >= 18)
    {

        cout << "Ingresa el precio de tu entrada:" << endl;
        cin >> precio;

        if (precio < 150)
        {

            cout << "Te falta varo, consigue más." << endl;
        }
        else
        {

            cout << "\nResumen del ticket:\nNombre: " << nombre << "\nEdad: " << edad << "\nA pagar: " << precio << endl;
        }
    }
    else
    {
        cout << "¡Largo de aqui, niño!" << endl;
    }

    return 0;
}
// ¿Por qué pasa? cin es flojo. Lee caracteres hasta que encuentra un espacio en blanco (espacio, tabulador o enter)
// y ahí se detiene, pensando que ya acabó el dato.
// Solución futura: Usaremos getline(cin, variable)
// más adelante para leer frases enteras. Por ahora, cin es suficiente.
