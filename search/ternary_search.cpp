#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double get_dist(vector<vector<ll>>& points, ll a, ll b, ll c, double x) {
    double dist = 0.0;
    double y = (-c - a * x) / b;
    for (auto& i:points) {
        dist += sqrt(pow(x - i[0], 2) + pow(y - i[1], 2));
    }
    return dist;
}

double ternary_search(vector<vector<ll>>& points, ll a, ll b, ll c) {
    double low = -10000000.0, high = 10000000.0;
    while (high - low > 0.0000001) {
        double crt_slice = (high - low) / 3.0;
        double m1 = high - crt_slice;
        double m2 = low + crt_slice;
        double d1 = get_dist(points, a, b, c, m1);
        double d2 = get_dist(points, a, b, c, m2);
        if (d1 > d2) high = m1;
        else low = m2;
    }
    return get_dist(points, a, b, c, (high + low) / 2.0);
}

int main() {
	ll t; cin>>t;
	while(t--){
	    ll n,a,b,c; cin >> n >> a >> b >> c;

	    vector<vector<ll>> points(n, vector<ll>(2));

	    for(ll i=0; i<n; i++) cin >> points[i][0] >> points[i][1];

	    cout << fixed << setprecision(6) << ternary_search(points, a, b, c) << endl;
	}
	return 0;
}
