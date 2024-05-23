// Euler’s Totient function Φ(n) for an input n is the count of numbers in {1, 2, 3, …, n-1} 
// that are relatively prime to n, i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1.

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll phi(ll n){
    ll res = n;
  
    for(ll p = 2; p * p <= n; p++){
        if (n % p == 0){
            while (n % p == 0) n /= p;
            res -= res / p;
        }
    }
    if (n > 1) res -= res / n;
    return res;
}
int main(){

    ll t;
    while(cin >> t && t > 0){
        cout << phi(t) << endl;
    }
}