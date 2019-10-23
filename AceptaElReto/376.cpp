//http://aceptaelreto.com/problem/statement.php?id=376
#include <iostream>
using namespace std;

//P = {2 <= n <= v.length()}
int resuelveCaso(int n, int v[]){
    int p = 0;
    int i = 0;
    
    if (v[0] > v[1] && v[n-1] < v[0]) p++;
    if (v[n-1] > v[n-2] && v[n-1] > v[0]) p++;
    
    for(int i = 1; i <= n - 2; i++) {
        if (v[i-1] < v[i] && v[i] > v[i+1]) p++;
    }
    
    return p;
}
//Q = {ret = (#i: 0 <= i < n : ??)}

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
