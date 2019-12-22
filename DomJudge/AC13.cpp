#include <iostream>
#include <vector>
using namespace std;

char cualFalta(vector<char> datos, char primero, char ultimo, int ini, int fin){
    //Casos directos
    if(datos[0] != primero) return primero;
    else if (datos[datos.size()-1] != ultimo) return ultimo;

    //Casos base
    if(ini == fin) return datos[ini] - 1;

    //Llamadas recursivas
    int m = (ini + fin) / 2;
    if(datos[m] == primero + m) return cualFalta(datos, primero, ultimo, m + 1, fin);
    else return cualFalta(datos, primero, ultimo, ini, m);
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
