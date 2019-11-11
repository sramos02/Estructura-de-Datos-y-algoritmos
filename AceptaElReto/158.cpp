#include <iostream>
using namespace std;

//P = {0 < n < 10^9}
void solve(long long int n, int & up, int & down){
    int i = 1, v[2];
    cin >> v[0]; 
    
    while(i < n){
        cin >> v[i%2];
        if(v[(i - 1)%2] < v[i%2]) up++;
        else if (v[(i - 1)%2] > v[i%2]) down++;
        i++;
    }
}
//Q = {up = #u : 1 <= u < n : v[u-1] < v[u] && down = #u : 1 <= u < n : v[u-1] > v[u]}

int main(){
    int cases;

    cin >> cases;
    for(int i = 0; i < cases; i++){
        long long int n;
        int up = 0, down = 0; 
        
        cin >> n;
        solve(n, up, down);
        cout << up <<  " " << down << endl;
    }
    
    return 0;
}
