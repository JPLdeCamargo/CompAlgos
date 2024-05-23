#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

vector<int> dijkstra(vector<vector<ii>>& graph, int start){
    vector<int> dist(graph.size(), INT_MAX);
    dist[start] = 0;
    priority_queue<ii> pq;
    pq.push({0, start});
    while(!pq.empty()){
        auto t = pq.top(); pq.pop();
        int d = t.first, u = t.second;
        if(d == dist[u]){
            for(auto e:graph[u]){
                int v = e.second, weight = e.first;
                if(dist[v] > dist[u] + weight){
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    return dist;

}