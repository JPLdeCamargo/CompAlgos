#include <bits/stdc++.h>

#define inf 1000000000
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<vector<int> >

using namespace std;

vector<pair<int, ii> > edgeList;
int n, m;
vi p;
vector<bool> valid, used;

int findSet(int u)
{
    if(p[u] == -1) return u;
    return p[u] = findSet(p[u]);
}

int MinimumSpanningTree(bool flag)
{
    p.assign(n+1, -1);
    int sets = n;
    int a, b, c, total = 0;
    for(int i=0; i<edgeList.size(); i++){
        if(valid[i]){
            c = edgeList[i].first;
            a = edgeList[i].second.first;
            b = edgeList[i].second.second;
            if(findSet(a) != findSet(b)){
                if(flag) used[i] = 1;
                p[findSet(a)] = findSet(b);
                sets--;
                total += c;
            }
        }
    }
    if(sets == 1) return total;
    else return inf;
}