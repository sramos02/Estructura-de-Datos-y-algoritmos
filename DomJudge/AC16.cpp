#include <iostream>
#include <vector>
using namespace std;

struct degradado {
    int suma;
    bool correcto;
};


degradado elDegradado(const vector<int> matriz, const int ini, const int fin){
    //Caso base (2 elementos)
    if (ini + 1 >= fin) return {matriz[ini] + matriz[fin], matriz[ini] <= matriz[fin]};

    //Caso recursivo
    degradado izq, drc;
    int m = (ini + fin) / 2;

    izq = elDegradado(matriz, ini, m);
    drc = elDegradado(matriz, m + 1, fin);
    return{izq.suma + drc.suma, izq.correcto && drc.correcto && izq.suma < drc.suma};
}

bool resuelveCaso(){
    int n, m;
    bool ret = true;

    cin >> n>> m;
    if(!cin) return  false;


    vector<vector<int>> matriz;
    for(int i = 0; i < n; i++){
        vector<int> fila;
        for(int j = 0; j < m; j++){
            int aux;
            cin >> aux;
            fila.push_back(aux);
        }
        matriz.push_back(fila);
    }

    //Si hay un solo elemento no hay degradado
    if(m > 1){
        for(int i = 0; i < n && ret; i++){
            ret = elDegradado(matriz[i], 0, matriz.size()).correcto;
        }
    }
    (ret)?cout << "SI\n":cout << "NO\n";
    return true;
}

int main(){
    while(resuelveCaso());
    return 0;
}
