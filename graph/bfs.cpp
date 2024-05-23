#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>>& graph, int s, int e){
    if(s == e) return 0;
    queue<pair<int, int>> q;
    vector<bool> done(graph.size(), false);
    done[s] = true;
    q.push({s, 0});
    while(!q.empty()){
        int u = q.front().first;
        int length = q.front().second;
        q.pop();
        for(int n:graph[u]){
            if(n == e){
                return length + 1;
            }
            if (!done[n]){
                done[n]  = true;
                q.push({n, length+1});
            }
        }
    }
    return -1;
}