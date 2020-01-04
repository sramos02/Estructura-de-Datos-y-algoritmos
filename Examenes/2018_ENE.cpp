//Ejercicio 2
#include <iostream>
#include <vector>
using namespace std;

//Coste O(logN) en relación con el numero de elementos del vector
//El vector divide a la mitad todo el rato hasta encontrar un numero igual o mayor y uno menor
int elCercano(const vector<int> datos, const int x, int ini, int fin, int mejorSol){

    //Calculo para dividir
    int m = (ini + fin) / 2;

    //Actualización
    if(datos[m] == x) return x;
    else if (abs(x - datos[m]) < abs(x - datos[mejorSol])) mejorSol = m;

    if(x <= datos[m]) for(int i = 0; m > 0 && datos[m - i - 1] == datos[m]; i--) m--;
    else  for(int i = 0; m < datos.size()-1 && datos[m + i + 1] == datos[m]; i++)m++;

    //Movimiento

    if(abs(mejorSol - m) == 1) return datos[mejorSol];
    else if(m > 0 && x <= datos[m]) elCercano(datos, x, ini, m, mejorSol);
    else if (m < datos.size() && x >= datos[m]) return elCercano(datos, x, m + 1, fin, mejorSol);

}

int main(){
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        int x, n;
        vector<int> datos;

        cin >> x >> n;
        for(int j = 0; j < n; j++){
            int aux;
            cin >> aux;
            datos.push_back(aux);
        }
        cout << elCercano(datos, x, 0, datos.size() - 1, 0);
    }

    return 0;
}


//Ejercicio 3

void lasQuitanieves(const vector<int> anchurasM, const vector<int> anchurasN, const vector<vector<int>> calidades,
                    int nivel, int solAct, vector<bool> marcasN,
                    int & mejorSol){
    int i = 0;
    while(i < anchurasN.size()) {
        if (!marcasN[i] && anchurasM >= anchurasN) {
            solAct += calidades[nivel][i];
            if(nivel == anchurasM.size()){ 
                if(solAct > mejorSol) mejorSol = solAct;
            }
            else { //NoEsSolucion
                marcasN[i] = false;
                lasQuitanieves(anchurasM, anchurasN, calidades, nivel + 1, solAct, marcasN, mejorSol);
                marcasN[i] = true;
            }
        }
    }
}

int main(){
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        int m, n;
        vector<int> anchurasM;
        vector<int> anchurasN;
        vector<bool> marcasN;
        vector<vector<int>> calidades;

        cin >> m >> n;
        for(int u = 0; u < m; u++) cin >> anchurasM[u];
        for(int v = 0; v < n; v++){
            cin >> anchurasN[v];
            marcasN[v] = true;
        } 

        for(int u = 0; u < m; u++){
            for(int v = 0; v < n; v++){
                cin >> calidades[u][v];
            }
        }

        int sol;
        lasQuitanieves(anchurasM, anchurasN, calidades, 0, 0, marcasN, sol);
        cout << sol << endl;
    }
    return 0;
}
