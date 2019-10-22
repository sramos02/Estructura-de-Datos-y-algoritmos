#include <iostream>
using namespace std;

void resuelveCaso(){
    int i = 0;   //Auxiliares
    int arriba = 0, abajo = 0; //Salidas
    long long n; int v[1000000000]; //Entradas 10^9 como maximo según el enunciado
    
    cin >> n;
    if(n > 1) {
        cin >> v[0]; i++;
        
        while(i < n){
            cin >> v[i];
            if(v[i - 1] < v[i]) arriba++;
            else if (v[i - 1] > v[i]) abajo++;
            i++;
        }
        cout << arriba << " " << abajo << endl;
    }
    else cout << "0 0" << endl;
}

int main(){
    int numCasos; 
    int i = 0;

    cin >> numCasos;
        
    while(i < numCasos){
        resuelveCaso();
        i++;
    }
    
    return 0;
}
