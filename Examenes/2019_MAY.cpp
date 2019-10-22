#include <iostream>
using namespace std;




//P = {0 <= n <= v.length() && k >= 0}
int resuelveCaso(int k, int n, bool a[]){
    int res = n + 1;
    int aux = 0;
    int i = 0;
    
    //I = {}
    while(i < n){
        
        for(int j = i; k < aux; j++){
            if(a[i]) aux++;   
        }
    
        
        res = min(res, aux);
        i++;
    }
    
    //aux//

    return res;
}
//Q = {res = min(u, w: 0 <= u <= w < n && k == esTramo(u, w, k): w - u)}
//esTramo(u, w, k) = {#c : u <= c <= w : a[c]} //Devuelve el numero de trues que hay en un tramo

int main(){
    int i = 0;
    int k, n;
    bool a[100];


    cin >> n;

    while(n != -1){
        while(i < n)
            (cin.get() == 0) ? a[i]= false : a[i] = true;
            
        cin >> k;
        cout << resuelveCaso(k, n, a) << endl;
        cin >> n;
    }

}
