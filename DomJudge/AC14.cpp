#include <iostream>
#include <vector>
using namespace std;

char cualFalta(vector<char> datos, char primero, char ultimo, int ini, int fin){
    //Casos directos
    if(datos[0] != primero) return primero;
    else if (datos[datos.size()-1] != ultimo) return ultimo;

    //else if(ini == datos.size() - 1) return datos[ini] - 1;
    //else if (fin == 0) return datos[fin] + 1;
    else if(ini == fin) {
        if (datos[ini] == primero + ini) return primero + ini + 1;
        else return primero + ini;
    }

    //Llamadas recursivas
    int m = (ini + fin) / 2;
    if(datos[m] == (primero + m)) return cualFalta(datos, primero, ultimo, ini, m);
    else return cualFalta(datos, primero, ultimo, m + 1, fin);
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        vector<char> datos;
        char primero, ultimo;
        cin >> primero >> ultimo;

        for(int j = 0; j < (ultimo - primero); j++){
            char aux;
            cin >> aux;
            datos.push_back(aux);
        }

        cout << cualFalta(datos, primero, ultimo, 0, datos.size() - 1) << endl;
    }
    return 0;
}
