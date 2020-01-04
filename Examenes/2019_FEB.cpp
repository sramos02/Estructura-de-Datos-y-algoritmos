#include <iostream>
#include <math.h>
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
