#include <bits/stdc++.h> 
using namespace std; 

int n = 20000000; 
vector<bool> prime(n, true);
using ii = pair<int, int>;
void sieve(int n) { 
    bool first = false;
    for (int p = 2; p * p <= n; p+=1+first) { 
        first = true;
        if (prime[p] == true) { 
            for (int i = p * p; i <= n; i += 2*p) prime[i] = false; 
        } 
    } 
} 