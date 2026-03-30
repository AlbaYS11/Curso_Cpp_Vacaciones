#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*ll n, aux;
    vector<ll> d;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        d.push_back(aux);
    }

    sort(all(d));

    int menor = d[0] - d[1];
    for (int i = 1, j = 0; j < d.size(); i++, j++)
    {
        if (d[i] - d[j] < menor)
        {
            menor = d[i] - d[j];
        }
    }

    cout << menor;*/

    int n;
    cin >> n;

    // TRUCO DE VELOCIDAD: Creo el vector ya con N espacios
    vector<ll> d(n);

    // Leo directo en la posicion, sin push_back ni variables aux
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    sort(d.begin(), d.end()); // (o sort(all(d)) si tienes la macro)

    // Inicializo con la diferencia del primer par adyacente
    ll menor = d[1] - d[0];

    // Recorro desde el tercero hasta el final
    for (int i = 2; i < n; i++)
    {
        // La funcion min() actualiza 'menor' automaticamente si encuentra algo mas chico
        menor = min(menor, d[i] - d[i - 1]);
    }

    cout << menor << '\n'; // '\n' es mas rapido que endl

    return 0;
}