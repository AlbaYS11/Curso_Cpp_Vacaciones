#include <bits/stdc++.h> // Incluye todas las librerías estándar
using namespace std;

// 🔹 Alias de tipos
typedef long long ll; // usar cuando hay números grandes (evita overflow)

// 🔹 Macros (atajos)
#define endl '\n'          // más rápido que endl (evita flush)
#define pb push_back       // v.pb(x) en vez de v.push_back(x)
#define all(x) x.begin(), x.end() // todo el contenedor (para sort, etc.)

int main() {
    // 🔹 Fast I/O (SIEMPRE en ICPC)
    ios_base::sync_with_stdio(false); // acelera cin/cout
    cin.tie(NULL); // evita flush automático al usar cin

    // -----------------------------
    // 🧠 RECORDATORIOS IMPORTANTES
    // -----------------------------

    // 📌 Antes de programar:
    // Revisar N (tamaño de entrada)
    // N <= 1e3   → O(N^2) OK (doble for)
    // N <= 1e5   → O(N log N) o O(N) (sort, map, etc.)
    // N <= 1e9   → O(log N) o O(1) (matemáticas)

    // 📌 Operaciones:
    // ~10^8 operaciones ≈ 1 segundo

    // -----------------------------
    // 🔹 ESTRUCTURAS MÁS USADAS
    // -----------------------------

    // vector
    vector<ll> v;

    // map (frecuencia)
    map<ll, ll> freq;
    // freq[x]++; // contar ocurrencias

    // set (elementos únicos ordenados)
    set<ll> s;

    // -----------------------------
    // 🔹 FUNCIONES CLAVE STL
    // -----------------------------

    // ordenar
    // sort(all(v));

    // búsqueda binaria (vector DEBE estar ordenado)
    // binary_search(all(v), x);

    // máximo / mínimo
    // *max_element(all(v));
    // *min_element(all(v));

    // contar
    // count(all(v), x);

    // -----------------------------
    // 🔹 EJEMPLO BÁSICO
    // -----------------------------

    /*
    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v.pb(x);
    }

    sort(all(v));

    for (auto x : v)
        cout << x << " ";
    cout << endl;
    */

    return 0;
}