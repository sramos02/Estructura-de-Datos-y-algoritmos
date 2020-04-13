#include <iostream>
#include <vector>
using namespace std;

//P = {0 < datos.size() && 0 < minimo}
vector<int> laCasaDeHeidi(vector<int> datos, int minimo, int & secMasLarga, int & numLlanos) {
    vector<int> resultado;

    int j = datos.size() - 2;
    int altMax = datos[j + 1];
    int longitud = 1;


    while (j >= 0) {
        if (datos[j] == datos[j + 1]) {
            while (datos[j] == datos[j + 1] && j >= 0) {
                longitud++;
                j--;
            }

            if (longitud >= minimo) {
                if (datos[j] > altMax) altMax = datos[j];
                if (longitud > secMasLarga) secMasLarga = longitud;
                resultado.push_back(datos.size() - j + 1);
                numLlanos++;
            }
        }
        else {

            if (datos[j] > datos[j + 1]) {
                altMax = datos[j];
                j--;
            }
            else {
                while (datos[j] < altMax && j >= 0) {
                    j--;
                }
            }
        }
        longitud = 1;
    }

    return resultado;
}
//Q = resultado(u) = {PT u, w :(0 <= u <= w < datos.size()) && (PT k: u <= k <= w: datos[k] = datos.at[u] && esAccesible(datos, k)) : ((w - u) >= minimo)}
// esAccesible(datos, k) = {PT v: k <= v < w : datos[v] <= datos[k]}

//funcion de cota: n-j;

//Coste: O(N) lineal

bool resuelveCaso() {
    int n, minimo;
    int secMasLarga = 0, numLlanos = 0;
    vector<int> datos;

    cin >> n >> minimo;
    for (int i = 0; i < n; i++) {
        int aux;
        cin >> aux;
        datos.push_back(aux);
    }

    vector<int> ret = laCasaDeHeidi(datos, minimo, secMasLarga, numLlanos);

    //Mostrar solución
    cout << secMasLarga << " " << numLlanos << " ";
    for (int i = numLlanos - 1; i >= 0; i--) cout << ret[i] << " ";
    cout << endl;

    //Retorno
    if (secMasLarga == 0 && numLlanos == 0) return false;
    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}
