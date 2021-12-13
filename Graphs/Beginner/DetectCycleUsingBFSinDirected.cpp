#include<bits/stdc++.h>
using namespace std;
#define ll long long int


class Graph {
	vector<vector<ll>> graph;
	bool directed;
public:
	Graph(int n, bool d = false) {
		graph.resize(n);
		directed = d;
	}

	void push(ll u, ll v) {
		graph[u].push_back(v);
		if(!directed) {
			graph[v].push_back(u);
		}
	}

	bool 
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    Graph g1(n, true);
    for(int i=0; i<m; i++) {
    	int u, v;
    	cin>>u>>v;
    	g1.push(u, v);
    }

    
    return 0;
}