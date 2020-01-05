#include <iostream>
#include <vector>
using namespace std;

void lasLuces(const int numColores, const int longitud, const int consumoMaximo, const vector<int> consumos,
              int nivel, vector<bool> usados, int solAct,
              int & numSoluciones){
    int i = 0;
    while(i < numColores){
        if(!usados[i] && solAct <= consumoMaximo){
            solAct += consumos[i];
            if(nivel == longitud - 1) numSoluciones++;
            else lasLuces(numColores, longitud, consumoMaximo, consumos, nivel + 1, usados, solAct, numSoluciones);
        }
        i++;
    }
}

int main(){
    int longitud;
    cin >> longitud;
    while(longitud != 0) {
        int numColores, consumoMaximo;
        vector<int> consumos;
        vector<bool> marcas;

        cin >> numColores >> consumoMaximo;
        for(int u = 0; u < numColores; u++){
            int aux;
            cin >> aux;
            consumos.push_back(aux);
            marcas[u] = false;
        }

        int mejorSol = consumoMaximo;
        lasLuces(numColores, longitud, consumoMaximo, consumos, 0, marcas, 0, mejorSol);
        cout << mejorSol << endl;

        cin >> longitud;
    }
    return 0;
}
