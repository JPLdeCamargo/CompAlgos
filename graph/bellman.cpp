#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

bool bellman(vector<vector<ii>>& adj, int s){
    vector<int> dist(adj.size(), INT_MAX); dist[s] = 0;
    for (int i = 0; i < adj.size() - 1; i++){
        for (int u = 0; u < adj.size(); u++){
            for (int j = 0; j < adj[u].size(); j++) {
                ii v = adj[u][j]; // record SP spanning here if needed
                dist[v.first] = min(dist[v.first], dist[u] + v.second); // relax
            }

        }
    }
    // after running the O(VE) Bellman Ford’s algorithm shown above
    bool hasNegativeCycle = false;
    for (int u = 0; u < adj.size(); u++) // one more pass to check
        for (int j = 0; j < adj[u].size(); j++) {
            ii v = adj[u][j];
            if (dist[v.first] > dist[u] + v.second) // if this is still possible
            hasNegativeCycle = true; // then negative cycle exists!
        }

    return hasNegativeCycle;
}
