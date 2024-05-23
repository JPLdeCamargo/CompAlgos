#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;


void floyd(vector<vector<float>>& graph){
    for(int k = 0; k < graph.size(); k++){
        for(int i = 0; i < graph.size(); i++){
            for(int j = 0; j <= i; j++){
                graph[i][j] = min(graph[i][j], max(graph[i][k], graph[k][j]));
                graph[j][i] = graph[i][j];
            }
        }
    }
}