#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

vector<int> dijkstra(vector<vector<ii>>& graph, int start){
    vector<int> dist(graph.size(), INT_MAX/10);
    dist[start] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, start});
    while(!pq.empty()){
        auto t = pq.top(); pq.pop();
        int d = t.first, u = t.second;
        if (d > dist[u]) continue;
        for(auto v:graph[u]){
            if(dist[u] + v.first < dist[v.second]){
                dist[v.second] = dist[u] + v.first;
                pq.push({dist[v.second], v.second});
            }
        }
    }
    return dist;
}