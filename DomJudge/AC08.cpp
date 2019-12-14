#include <iostream>
#include <vector>
using namespace std;

//P = {0 <= datos.size() < 1000 && PT i: 0 <= i < n : v[i] < 4000}
int valdesqui(vector<int> datos){
    int i = 1;
    int mejorSolucion = 0;
    int solucionAct = 1;

    if(datos.size() > 0) {
        mejorSolucion++;

        //I = {mejorSolucion = max(solucionAct) && solucionAct = u, w: 0 <= u <= w < i && v[u] < v[w]: w - u}
        while (i < datos.size()) {
            if (datos[i] <= datos[i - 1]) {
                solucionAct++;
                if (solucionAct > mejorSolucion) mejorSolucion = solucionAct;
            }
            else solucionAct = 1;
            i++;
        }
    }
    return mejorSolucion;
}
//Q = {mejorSolucion = max(u, w: 0 <= u <= w < n && v[u] < v[w]: w - u)}
//fdc = n - i
//Coste: O(N) lineal debido al unico bucle que se recorre un total de N veces, el resto de instrucciones, incluidas las de su interior
// son de coste contante O(1) por lo que no modifican el coste del algoritmo

int main(){
    int casos;
    cin >> casos;

    for(int i = 0; i < casos; i++){
        int n;
        vector<int> datos;
        cin >> n;
        for(int j = 0; j < n; j++){
            int aux;
            cin >> aux;
            datos.push_back(aux);
        }
        cout << valdesqui(datos) << endl;
    }
    return 0;
}
