#include <iostream>
using namespace std;

int main(){
    int casos;
    cin >> casos;
    
    for(int i = 0; i < casos; i++){
        int p, n;
        int a[1000];
       
        cin >> n >> p;
        for(int j = 0; j < n; j++) cin >> a[i];
            (resuelveCaso(a, n, p)) ?   cout << "SI" : cout << "NO"; 
            cout << endl;
    }
}

//P = {a != null && 0 <= p < a.length()}
bool resuelveCaso(int a[], int n, int p){
    int i = 0, max = 0;
    while(i <= p){
        if(max < a[i]) max = a[i];
        i++;
    }
    
    int j = p + 1, min = a[j];
    while(j < a.length()){
        if(min > a[i]) min = a[i];
        j++;
    }
    
    return max < min;
}
//Q = {b = (PT u, w : 0 <= u < = p < w < a.length : a[u] < a[w])}
