#include <iostream>
#include <math.h>
using namespace std;

int invertir(int n){
   int length = log10(n) + 1;
   
   if(n < 10) return n;
   else{
        int aux = invertir(n/10);
        return 10*n + aux    
   }
   
   return n;
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
