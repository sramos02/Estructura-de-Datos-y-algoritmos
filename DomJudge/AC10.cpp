#include <iostream>
#include <math.h>
using namespace std;

int invertir(int n){   
   if(n < 10) return n;
   else{
        int aux = invertir(n/10);
        int pot = pow(10, (int)log10(n));
        return (n%10) * pot + aux;
   }
   
}

int main(){
  int n;
  cin >> n;
  while(n !=0){
    cout << invertir(n) << endl;
    cin >> n;
  }
  return 0;
}
