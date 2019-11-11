#include <iostream>
using namespace std;


bool solve(long long n, int & l){
    if(n < 10){
        l = 1;
        return true;
    }
    
    bool end = solve(n/10, l);
    l++;
    return end && (n%l == 0);
}

bool solveCase() {
    long long n;
    int l;
    
    cin >> n;
    if(!cin) return false;  
    solve(n, l)?cout << "POLIDIVISIBLE": cout << "NO POLIDIVISIBLE";
    cout << endl;
    return true;
}

int main() {   
    while(solveCase());
}
