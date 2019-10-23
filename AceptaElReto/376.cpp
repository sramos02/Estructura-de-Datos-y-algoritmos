//http://aceptaelreto.com/problem/statement.php?id=376
#include <iostream>
using namespace std;

//P = {2 <= n <= v.length()}
int resuelveCaso(int n, int v[]){
    int picos = 0;
    int i = 0;
    
    if(n == 2){
        if(v[0] != v[1]) picos++; //Si son diferentes alturas siempre tendrá un pico
    }
    else {
        while(i < n){
            int ant = (i - 2) % n;
            int act = (i - 1) % n;
            int sig = i % n;
            
            
            if((v[ant] < v[act]) && (v[act] > v[sig])) picos++;
            i++;
        }
    }
    return picos;
}
//Q = {ret = (#i : 0 <= i < n && (v[(i-2) mod n] <= v[(i-1) mod n] >= v[(i) mod n]) : i)}

int main()
{
    int n;
    int v[1000];
    
    cin >> n;
    while(n != 0){
        for(int i = 0; i < n; i++) cin >> v[i];
        cout << resuelveCaso(n , v) << endl;; 
        cin >> n;
    }
    
    return 0;  
}
