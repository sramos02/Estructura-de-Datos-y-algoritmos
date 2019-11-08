#include <iostream>
using namespace std;

void resuelveCaso(long long int n){
    int i = 1, v[2];           //Auxiliares
    int arriba = 0, abajo = 0; //Salidas

    cin >> v[0]; 
    
    while(i < n){
        cin >> v[i%2];
        if(v[(i - 1)%2] < v[i%2]) arriba++;
        else if (v[(i - 1)%2] > v[i%2]) abajo++;
        i++;
    }
    
    cout << arriba << " " << abajo << endl;
}

int main(){
    int numCasos; 
    int i = 0;

    cin >> numCasos;
        
    while(i < numCasos){
        long long int n;
        cin >> n;
        resuelveCaso(n);
        i++;
    }
    
    return 0;
}
