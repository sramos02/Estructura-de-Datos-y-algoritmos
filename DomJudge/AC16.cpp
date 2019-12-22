#include <iostream>
#include <vector>
using namespace std;

bool elDegradado(const vector<vector<int>> matriz, int ini, int fin){
    //SIN TERMINAR
}

bool resuelveCaso(){
    int n, m;
    while(cin >> n >> m){

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

        elDegradado(matriz, 0, matriz.size() - 1)?cout << "SI\n":cout << "NO\n";
    }
}

int main(){
    while(resuelveCaso());
    return 0;
}
