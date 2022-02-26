// https://www.spoj.com/problems/TOPOSORT/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll n, m;


class Graph {
	vector<priority_queue<ll>> graph;

	vector<bool> vis;
	vector<ll> Stack;
	unordered_set<ll> s;
public:
	Graph(int n) {
		graph.resize(n+1);
	}
	void addEdge(ll u, ll v) {
		graph[u].push(v);
	}

	bool dfs(int i) {
		if(s.find(i)!=s.end()) {
			return false;
		}
		if(vis[i]) {
			return true;
		}
		s.insert(i);
		vis[i] = true;
		while(!graph[i].empty()) {
			auto c = graph[i].top();
			graph[i].pop();
			if(!dfs(c)) {
				return false;
			}
		}
		s.erase(i);
		Stack.push_back(i);
		return true;
	}
	void topologicalSort() {
		int n= graph.size()-1;
		vis.assign(n+1, false);
		for(int i=n; i>=1; i--) {
			if(!vis[i]) {
				s.clear();
				if(!dfs(i)) {
					cout<<"Sandro fails."<<endl;
					return;
				}
			}
		}
		for(int i=Stack.size()-1; i>=0; i--) {
			cout<<Stack[i]<<" ";
		}
		cout<<endl;
		return;
	}
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;

    Graph g(n);
    for(int i=0; i<m; i++) {
    	ll u, v;
    	cin>>u>>v;
    	g.addEdge(u, v);
    }
    g.topologicalSort();
    return 0;
}