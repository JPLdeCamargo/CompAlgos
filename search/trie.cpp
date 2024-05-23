#include <bits/stdc++.h>
using namespace std;

string s;
int best;
unordered_map<string, int> found;
vector<string> big_subs;

struct node{
    int cont;
    node *link[4];
    
    node(){
        cont = 0;
        
        for(int i = 0;i < 4;i++)
            link[i] = NULL;
    }
};

struct trie{
    node *root;
    
    trie(){
        root = new node();
    }
    
    void insert(int pos){
        node *p = root;
        string crt;
        
        for(int i = pos;i < s.size();i++){
            crt.push_back(s[i]);
            int nxt;
            if(s[i] == 'A') nxt = 0;
            else if(s[i] == 'C') nxt = 1;
            else if(s[i] == 'G') nxt = 2;
            else nxt = 3;
            
            if(p->link[nxt] == NULL) p->link[nxt] = new node();
            p = p->link[nxt];
            p->cont++;
            
            if(p->cont > 1){
                if(crt.size() > best){
                    big_subs.clear();
                    best = crt.size();
                }
                
                if(crt.size() == best){
                    big_subs.push_back(crt);
                    found[crt] = p->cont;
                }
            }
        }
    }
};

int main(){
    int t; cin >> t;
    
    while(t--){
        cin >> s;
        
        best = 0;
        
        trie trie_o = trie();
        big_subs.clear();
        
        for(int i = 0;i < s.size();++i)
            trie_o.insert(i);
        

        if(best == 0) cout << "No repetitions found!" << endl;
        else{
            sort(big_subs.begin(), big_subs.end());
            cout << big_subs[0] << " " << found[big_subs[0]] << endl;
        }
    }
    
    return 0;
}