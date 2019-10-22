#include <iostream>
using namespace std;

//P = {0 <= n <= v.length() && k >= 0}
int resuelveCaso(int k, int n, bool a[]){
    int res = n + 1;
    int i = 0;
    
    //I = {}
    while(i < n){        
        int aux = 0;
        for(int j = i; (k < aux) && (j < n); j++) aux++;   
        if(aux != 0) res = min(res, aux);
        i++;
    }
    
    return res;
}
//Q = {res = min(u, w: 0 <= u <= w < n && k == esTramo(u, w, k): w - u)}
//esTramo(u, w, k) = {#c : u <= c <= w : a[c]} //Devuelve el numero de trues que hay en un tramo

int main(){
    int i = 0;
    int k, n;
    bool a[100];


   
    while(n != -1){ 
        cin >> n;
        while(i < n) {
            cin >> a[i]; 
            i++;
        }
        
        cin >> k;
        cout << resuelveCaso(k, n, a) << endl;
        cin >> n;
    }

}
