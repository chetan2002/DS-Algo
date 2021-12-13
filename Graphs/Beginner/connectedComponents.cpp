#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class Graph {
    vector<vector<int>> graph;
public:
    Graph(int n) {
        graph.resize(n);
    }
    void push(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    void dfs(vector<bool> &vis, int i) {
        if(vis[i]) {
            return;
        }
        vis[i] = true;
        for(auto c: graph[i]) {
            dfs(vis, c);
        }
    }
    int countConnected() {
        vector<bool> vis(graph.size(), false);
        int count =0;
        for(int i=0; i<graph.size(); i++) {
            if(!vis[i]) {
                dfs(vis, i);
                count++;
            }
        }
        return count;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;

    Graph g1(n);
    for(int i=0; i<m; i++) {
    	int u, v;
    	cin>>u>>v;
    	g1.push(u, v);
    }
    cout<<g1.countConnected()<<endl;
    return 0;
}