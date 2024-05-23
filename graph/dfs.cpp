#include <bits/stdc++.h>
using namespace std;

bool dfs(int v, vector<vector<int>>& adj, vector<bool>& been){
    been[v] = true;

    for(auto n:adj[v]){
        if(n == adj.size() - 1){
            return true;
        }
        if(!been[n] && dfs(n, adj, been)){
            return true;
        }
    }
    return false;
}