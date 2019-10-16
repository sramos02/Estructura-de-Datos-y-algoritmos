#include <iostream>
#include <string>
using namespace std;

bool resuelveCaso(const string palabra){

    int aux, i, j;
    cin >> i >> j;
    
    //I siempre será la posición mínima
    if(i > j) {
        aux = i;
        i = j;
        j = aux;
    }
    
    while(i <= j){
        if(palabra[i] != palabra[j]) return false;
        i++;
    }
    
    return true;
}

int main(){
    
    string palabra;
    int numCasos; 
    int i = 0;
    
    cin >> palabra;
    cin >> numCasos;
        
    while(i < numCasos){
        cout << (resuelveCaso(palabra) ? "SI"  : "NO") << endl;
        i++;
        
        if(i == numCasos){
            cout << endl;
            cin >> palabra;
            cin >> numCasos;
        }
    }
    return 0;
}
