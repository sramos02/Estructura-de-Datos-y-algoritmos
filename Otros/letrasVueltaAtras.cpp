#include <iostream>
#include <vector>
using namespace std;


//Dada n letras diferentes, diseñar un algoritmo que calcule las palabras con m letras (m <= n) diferentes
//El orden de las letras es importante

bool esValida(vector<int> solucion, int k){
    int i = 0;
    while(i < k && solucion[i] != solucion[k])i++;
    return i==k;
}

bool llegaFin(int m, int k){
    return k == m++;
}

void variaciones(vector<int> solucion, int k, int n, int m){
    for(int letra = 0; letra < n; letra++){
        solucion[k] = letra;
        if(esValida(solucion, k)){
            if(llegaFin(m, k)){
                for(int i = 0; i < solucion.size() - 1; i++)cout << solucion[i] << " ";
                cout << endl;
            }
        }
        else variaciones(solucion, k++, n, m);
    }
}

int main(){
    int casos;
    cin >> casos;

    for(int i = 0; i < casos; i++){
        int n, m;
        vector<int> solucion;

        cin >> n >> m;
        variaciones(solucion, 0, n, m);
    }
    return 0;
}
