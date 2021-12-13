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

    bool checkForCycle(int node, int parent, vector<bool> &vis) {
        vis[node] = true;
        for(auto c: graph[node]) {
            if(!vis[c]) {
                if(checkForCycle(c, node, vis)) return true;
            } else 
            if(c != parent) {
                return true;
            }
        }
        return false;
    }
    bool graphHasCycle() {
        vector<bool> vis(graph.size(), false);
        for(int i=0; i<graph.size(); i++) {
            if(!vis[i]) {
                if(checkForCycle(i, -1, vis)) return true;
            }
        }
        return false;
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
    cout<<g1.graphHasCycle()<<endl;
    return 0;
}