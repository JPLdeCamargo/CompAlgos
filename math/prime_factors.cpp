#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;

ll n = 1000000; 
vector<bool> prime(n, true);
vi primes;
void sieve(ll n) { 
    bool first = false;
    for (ll p = 2; p * p <= n; p+=1+first) { 
        first = true;
        if (prime[p] == true) { 
            for (ll i = p * p; i <= n; i += 2*p) prime[i] = false; 
        } 
    } 
    for(ll i = 2; i <= n; i++){
        if(prime[i])primes.push_back(i);
    }
} 

vi primeFactors(ll N) { // remember: vi is vector<ll>, ll is long long
    if(N < 2) return {};
    vi factors;
    ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
    while (PF * PF <= N) { // stop at sqrt(N); N can get smaller
        while (N % PF == 0) {
             N /= PF; factors.push_back(PF);
        } // remove PF
        PF = primes[++PF_idx]; // only consider primes!
    }
    if (N != 1) factors.push_back(N); // special case if N is a prime
    return factors; // if N does not fit in 32-bit lleger and is a prime
} // then ‘factors’ will have to be changed to vector<ll>

void update_factors(ll x, unordered_map<ll, ll>& mp){
    vi factors = primeFactors(x);
    for(ll i:factors){
        if(!mp.count(i)) mp[i]= 0;
        mp[i]++;
    }
}
ll get_powers(ll n, ll p){
    ll res = 0;
    for (ll power = p ; power <= n ; power *= p)
        res += n/power;
    return res;
}


int main(){
    sieve(n);
    ll fact, m;
    while(cin >> fact >> m){
        unordered_map<ll, ll> facts_m;
        update_factors(m, facts_m);
        bool div = true;
        for(auto p:facts_m){
            if(p.second > get_powers(fact, p.first)) div = false;
        }
        if(!m) div = true;
        cout << m;
        if(div) cout << " divides ";
        else cout << " does not divide ";
        cout << fact << "!" << endl;

    }
}