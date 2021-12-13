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
    

    bool cyclePresent(int i, vector<bool> &vis) {
    	queue<pair<int,int>> q;
    	vis[i] = true;
    	q.push({i, -1});
    	while(!q.empty()) {
    		int a = q.front().first;	// our node
    		int b = q.front().second;	// parent node
    		q.pop();
    		for(auto c: graph[a]) {
    			if(!vis[c]) {
    				vis[c] = true;
    				q.push({c, a});
    			}else {
    				if(c!=b) {		// if not parent then cycle
    					return true;
    				}
    			}
    		}
    	}
    	return false;
    }

    bool graphHasCycle() {
    	vector<bool> vis(graph.size(), false);;
    	for(int i=0; i<graph.size(); i++) {
    		if(!vis[i]) {
    			if(cyclePresent(i, vis)) {
    				return true;
    			}
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