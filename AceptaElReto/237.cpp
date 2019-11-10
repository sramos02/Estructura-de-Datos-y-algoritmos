#include <iostream>
#include <math.h>
using namespace std;


bool solve(long long int n, int l){
    if(l == 1) return true;
    return solve(n/10, l-1) && (n%l == 0);
}

bool solveCase() {
    long long int n;
    
    cin >> n;
    if(!cin) return false;  
    
    int l = floor(log10(n)) + 1;
    solve(n, l)?cout << "POLIDIVISIBLE": cout << "NO POLIDIVISIBLE";
    cout << endl;
    return true;
}

int main() {   
    while(solveCase());
}
