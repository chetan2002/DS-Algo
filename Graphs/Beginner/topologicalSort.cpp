#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class Graph {
public:
	unordered_map<ll, vector<ll>> graph;
	Graph() {
		graph.clear();
	}
	void addEdge(ll u, ll v, bool und) {
		graph[u].push_back(v);
		if(und) {
			graph[v].push_back(u);
		}
	}
};

class topologicalSort {
	unordered_set<ll> visited;
	vector<ll> Stack;
	Graph g;
public:
	topologicalSort(Graph &a) {
		g = a;
	}

	void dfs(ll val) {
		if(visited.find(val)!=visited.end()) {
			return;
		}
		visited.insert(val);
		for(auto c: g.graph[val]) {
			dfs(c);
		}
		Stack.push_back(val);
	}
	void iterateAndCheck() {
		for(auto c: g.graph) {
			if(visited.find(c.first)==visited.end()) {
				dfs(c.first);
			}
		}
		reverse(Stack.begin(), Stack.end());
		for(auto c: Stack) {
			cout<<c<<" ";
		}
		cout<<endl;
	}
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n, m;  
 	cin>>n>>m;
 	Graph g;
 	for(int i=0; i<m; i++) {
 		int u, v;
 		cin>>u>>v;
 		g.addEdge(u, v, 0);
 	}
 	topologicalSort t1(g);
 	t1.iterateAndCheck();
    return 0;
}