#include <iostream>
#include <cmath>
using namespace std;

//Ejercicio 1

//Ejercicio 2
bool sumdivisible(const int n){
    int numDigitos = (int)log10(n) + 1;

    if(numDigitos == 1) return true;
    else{
        int sum = 0, aux = n;

        while(aux > 0){
            sum += aux%10;
            aux /= 10;
        }
        if(sum % numDigitos == 0) return sumdivisible(n/10);
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    while(n != 0){
        sumdivisible(n)?cout <<"SI\n":cout << "NO\n";
        cin >> n;
    }
    return 0;
}

//Ejercicio 3

bool sumdivisible(const int n){
    int numDigitos = (int)log10(n) + 1;
    if(numDigitos == 1) return true;

    int ultimoDigito = (n/(10*numDigitos - 1));
    return (ultimoDigito % numDigitos == 0);
}

void cuantoSumdivisible(const int primera, const int longitud, int nivel, int solAct, int & ret){
    int k = 0;

    while(k < longitud){
        if(sumdivisible(solAct*10 + k)) {
            if (nivel == longitud) ret++;
            else cuantoSumdivisible(primera, longitud, nivel + 1, solAct*10 + k, ret);
        }
        k++;
    }
}

int main(){
    int d, k;
    cin >> d;
    while(d != 0){
        cin >> k;
        int ret = 0;
        cuantoSumdivisible(d, k, 1, d, ret);
        cout << ret << endl;
        cin >> d;
    }
}
