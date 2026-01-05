#include <iostream> //Para poder usar System input y output osea cin y cout
#include <string>   //Para poder usar strings comodamente

#include <vector>
// Import

using namespace std; // Para poder usar cin, cout y string sin alias, es la caja de herramientas

void imprimirRecibo(vector<string> l){

if (!l.empty())
    {
        cout << "lista de invitados final: " << endl;
        for (string i : l)
        {
            cout << i << endl;
        }
    }
}

int main()
{
    vector<string> lista;
    int band;

    cout << "¿Deseas iniciar el registro?" << endl;
    cin >> band;

    cin.ignore();
    
    while (band == 1)
    {

        int edad;
        string nombre;
        double precio;

        cout << "¡Bienvenido! \nPara entrar haz el registro." << endl;
        cout << "Ingresa tu nombre:" << endl;
        getline(cin, nombre);
        // cin >> nombre; se corta al ver un espacio. El otro lee toda la linea

        cout << "Ingresa tu edad:" << endl;
        cin >> edad;

        if (edad >= 18)
        {

            cout << "Ingresa el precio de tu entrada:" << endl;
            cin >> precio;

            if (precio < 150)
            {

                cout << "Te falta varo, consigue mas." << endl;
            }
            else
            {

                cout << "\nResumen del ticket:\nNombre: " << nombre << "\nEdad: " << edad << "\nA pagar: " << precio << endl;
                lista.push_back(nombre);
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
// ¿Por qué pasa? cin es flojo. Lee caracteres hasta que encuentra un espacio en blanco (espacio, tabulador o enter)
// y ahí se detiene, pensando que ya acabó el dato.
// Solución futura: Usaremos getline(cin, variable)
// más adelante para leer frases enteras. Por ahora, cin es suficiente.
