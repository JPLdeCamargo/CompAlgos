#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define MAX_N 2 // Fibonacci matrix, increase/decrease this value as needed
struct Matrix { ll mat[MAX_N][MAX_N]; }; // we will return a 2D array
Matrix matMul(Matrix a, Matrix b, ll mod) { // O(n^3)
    Matrix ans; ll i, j, k;
    for (i = 0; i < MAX_N; i++)
        for (j = 0; j < MAX_N; j++){
            ll res = 0;
            for (ans.mat[i][j] = k = 0; k < MAX_N; k++){
                res += (a.mat[i][k] * b.mat[k][j]) % mod; // modulo arithmetic
            } // if necessary, use
            ans.mat[i][j] = res % mod;
        }
    return ans;
}
Matrix matPow(Matrix base, ll p, ll mod) { // O(n^3 log p)
    Matrix ans; ll i, j;
    for (i = 0; i < MAX_N; i++) for (j = 0; j < MAX_N; j++)
        ans.mat[i][j] = (i == j); // prepare identity matrix
    while (p) { // iterative version of Divide & Conquer exponentiation
        if (p & 1) ans = matMul(ans, base, mod); // if p is odd (last bit is on)
        base = matMul(base, base, mod); // square the base
        p >>= 1; // divide p by 2
    }
    return ans;
}
ll fastExp(ll base, ll p) { // O(log p)
    if (p == 0) return 1;
    else if (p == 1) return base; // See the Exercise below
    else { 
        ll res = fastExp(base, p / 2); res *= res;
        if (p % 2 == 1) res *= base;
        return res; 
    }
}
int main(){
    ll n, m;
    Matrix fibo;
    fibo.mat[0][0] = 1; fibo.mat[0][1] = 1; fibo.mat[1][0] = 1; fibo.mat[1][1] = 0;
    while(cin >> n >> m){
        ll p = fastExp(2, m);
        Matrix fibo_res_m = matPow(fibo, n, p);
        ll fibo_res = fibo_res_m.mat[0][1];

        cout << fibo_res << endl;
    }
}