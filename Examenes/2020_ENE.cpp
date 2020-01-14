#include <iostream>
#include <cmath>
using namespace std;

//Ejercicio 1
//P: {0 <= n}
bool entretenido(unsigned long long n){
    
    //A0
    bool ret = true;
    int i = log10(n) - 1;
    
    //I: {log(10)n -1 >= i >= 0 && ret = (PT u : 0 <= u < i : v[u] != v[u+1])}
    while(i >= 0 && ret){ /*B*/
        //A1
        if((long long int)(n%10) == (long long int)(n%100/10)) ret = false;
        //R: {{log(10)n -1 >= i-1 >= 0 && ret = (PT u : 0 <= u < i-1 : v[u] != v[u+1])}}
        //A2
        n = n/10;
        i--;
    }
    //I && !B
    return ret;
}
//Q : {ret = PT u : 0 <= u < log10(n) - 1 : v[u] != v[u+1]}

//fdc(): La función de cota de este algoritmo es log10(n) - 1 - i ya que a ese valor se inicializa la variable, que decrementa en cada 
//iteración del bucle finalmente anulandose, tanto por el booleano como por su igualación a 0

//La función tiene una complejidad O(log(N)), es decir, el bucle se ejecuta el numero de dígitos de N, el resto de instrucciones son de coste constante O(1)
//por lo que la complejidad total queda a la del mayor ya mencionada. 

int main(){
    unsigned long long n;
    cin >> n;
    while(n != -1){
        entretenido(n)?cout<<"":cout << "NO ";
        cout << "ENTRETENIDO\n";
        cin >> n;   
    }
}

//Ejercicio 2

//La complejidad de este algoritmo es O(N) ya que se crean N iteraciones, cada una de ellas
//de coste constante O(1), el parametro k inicializado a 0 aumenta hasta llegar a N (caso base)

int cuantosEntretenidos(const unsigned long long n, unsigned long long k){
    int act = 0, sig = 0;
    
    if(k == n) {
        if(entretenido(n)) return 1;
        else return 0;
    }
    else{
        if(entretenido(k))act=1;
        if(cuantosEntretenidos(n, k+1))sig=1;
    }
    
    return act + sig;
}

int main(){
    unsigned long long n;
    cin >> n;
    while(n =! -1){
        cout << cuantosEntretenidos(n, 0) << endl;
        cin >> n;   
    }
}

//Ejercicio 3
void entretenidosExquisitos(const int n, const int d, const int k, int nivel, int solAct, int & ret){
    int i = 0;
    
    //Empezamos en nivel 2 porque el 1 es D
    
    while(i < 10) { //Numeros de 0 a 9
        if(solAct*10+i < k && (i != solAct%10)) {
            if(nivel == n) ret++;
            else {
                entretenidosExquisitos(n, d, k, nivel + 1, solAct, ret);
            }
        }
        i++;
    }
}



int main(){
    int n, d, k;
    cin >> n;
    while(n =! -1){
        cin >> d >> k;
        int ret = 0;
        n = 2; d = 2; k = 5;
        entretenidosExquisitos(n, d, k, 2, d, ret);
        cout << ret << endl;
        cin >> n;   
    }
    return 0;
}

