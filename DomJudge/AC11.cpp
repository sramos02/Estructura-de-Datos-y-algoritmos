#include <iostream>
#include <math.h>
using namespace std;

void comp(int n, int & complementario, int & complementarioInv){
   if(n < 10) {
       complementario = 9-n;
       complementarioInv = complementario;
   }
   else{
        comp(n/10, complementario, complementarioInv);
        complementario    = complementario * pow(10, log10(n)) + ((9 - (n%10)));
        complementarioInv = ((9 -(n%10))) * pow(10, log10(n)) + complementarioInv;  
    }
}


int main(){
   int casos;
   cin >> casos;
   for(int i = 0; i < casos; i++){
        long int n;
        cin >> n;
        
        int res, resInv;
        comp(n, res, resInv);
        cout << res << " " << resInv << endl;
   }
  return 0;
}
