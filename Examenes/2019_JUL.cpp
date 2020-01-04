#include <iostream>
#include <vector>
using namespace std;

//Ejercicio 1
//P = {0 <= n <= long(datos)}
int cuantoSinMejora(int n, vector<int> datos){ //return ret
    int ret = 0;
    int i = 0;

    //I = {ret = max(u, v: 0 <= u < v < i && datos[u] <= datos[v]: #v)}
    while(i < n){
        int act = 0;
        int j = i;

        //I = {j = i && act = u: 0 <= u < j <= i && datos[u] <= datos[j]: #v && ret = max(u, v: 0 <= u < v < i && datos[u] <= datos[v]: #v)}
        while(i < n && datos[i + 1] <= datos[j] ){
            act++;
            if(ret < act) ret = act;
            i++;
        }
        act = 0;
        i++;
    }
    return ret;
}
//Q = {ret = max(u, v: 0 <= u < v < n && datos[u] <= datos[v]: #v)}

//El coste del algoritmo es O(N), todas las instrucciones son de coste lineal exceptuando los dos bucles while. Estos se recorren un total
//de N veces entre ambos. Ya que comparten la misma variable i. Siguiendo la función de cota, por esta lógica, fdc = n-i. Recorriendo un total
//de n veces antes de acabar el problema

int main(){
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        int n;
        vector<int> datos;

        cin >> n;
        for(int j = 0; j < n; j++) {
            int aux;
            cin >> aux;
            datos.push_back(aux);
        }

        cout << cuantoSinMejora(n, datos) << endl;
    }
    return 0;
}

//Ejercicio 2 (Sin terminar)
typedef struct{
    bool esValida;
    int numParcelas;
}tSolucion;

bool equilibrado(const int n0, const int n1, const int n2, const int n3){
    return abs(n0 - n1) < 2 &&
           abs(n0 - n2) < 2 &&
           abs(n0 - n3) < 2 &&
           abs(n1 - n2) < 2 &&
           abs(n1 - n3) < 2 &&
           abs(n2 - n3) < 2;
}

tSolucion lasParcelitas(int f, int c, const vector<vector<int>> matriz){
    int dim = f - c + 1;
    int unos = 0;

    if(dim == 2){
        for(int i = c; i < 2; i++){
            for(int j = f; j < 2; j++){
                if(matriz[i][j] == 1) unos++;
            }
        }
        return{true, unos};
    }
    else {
        int m = dim / 2;
        int n0 = 0, n1 = 0, n2 = 0, n3 = 0;

        n0 += lasParcelitas(c, c + m, matriz).numParcelas;
        n1 += lasParcelitas(c + m, c, matriz).numParcelas;
        n2 += lasParcelitas(c, c, matriz).numParcelas;
        n3 += lasParcelitas(c + m, c + m, matriz).numParcelas;

        unos = unos + n0 + n1 + n2 + n3;

        if (dim == matriz.size()) { //caso final
            return {(!(unos < ((c * c) / 25) || unos > ((c * c) / 75) || !equilibrado(n0, n1, n2, n3))), unos};
        }

    }
}

int main(){
    int casos;
    cin >> casos;
    for(int i = 0; i < casos; i++){
        int n;
        vector<vector<int>> matriz;

        cin >> n;
        for(int u = 0; u < n; u++){
            vector<int> aux;
            for(int v = 0; v < n; v++){
                int aux2;
                cin >> aux2;
                aux.push_back(aux2);
            }
            matriz.push_back(aux);
        }
        lasParcelitas(n, n, matriz).esValida?cout <<"SI\n":cout << "NO\n";
    }
    return 0;
}
