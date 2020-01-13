#include <iostream>
#include <vector>
using namespace std;

//0 < l <= n <= long(datos)
int elProblema(const int n, const int l, const vector<int> datos){

    //A0
    int cont = 0;
    int i = 1;

    //I1 = {0 <= i <= n && cont = #k: 0 <= k < i: (PT u, w : 0 <= u < w : (max u, w : 0 <= u <= w < i && (PT p, q : u <= p < q < w : datos[p] = datos[q]) : w - u) >= l}
    while(i < n){
        //A1
        int aux = 0;
        //I2 = {0 <= i <= n && aux = (#k: 0 <= k < i: (PT u, w : 0 <= u < w : (max u, w : 0 <= u <= w < i && (PT p, q : u <= p < q < w : datos[p] = datos[q]) : w - u))
        // && cont = 0 <= i <= n && cont = #k: 0 <= k < i: (PT u, w : 0 <= u < w : (max u, w : 0 <= u <= w < i && (PT p, q : u <= p < q < w : datos[p] = datos[q]) : w - u) >= l}
        while(datos[i] == datos[i - 1]){
            aux++;
            i++;
        }
        if(aux > l)cont++;
        //R = {0 <= i+1 <= n && cont = #k: 0 <= k < i+1: (PT u, w : 0 <= u < w : (max u, w : 0 <= u <= w < i+1 && (PT p, q : u <= p < q < w : datos[p] = datos[q]) : w - u) >= l}
        //A2
        i++;
    }
    return cont;
}
//Q: cont = {#k: 0 <= k < n: (PT u, w : 0 <= u < w : (max u, w : 0 <= u <= w < n && tramoValido(u, w) : w - u) >= l}
//tramoValido(u, w): {PT p, q : u <= p < q < w : datos[p] = datos[q]}

//num de cadenas posibles dentro del vector

int main(){
    int n, l;
    cin >> n >> l;
    while(n > 0){
        vector<int> datos;
        for(int i = 0; i < n; i++){
            int aux;
            cin >> aux;
            datos.push_back(aux);
        }
        cout << elProblema(n, datos) << endl;
        cin >> n >> l;
    }
}
