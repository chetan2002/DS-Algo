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

	bool colorBipartite(vector<int> &color, int i) {
		if(color[i]==-1) {
			color[i] = 1;
		}

		for(auto c: graph[i]) {
			if(color[c]==-1) {
				color[c] = 1 - color[i];
				if(!colorBipartite(color, c)) {
					return false;
				}
			}else
			if(color[c]==color[i]) {
				return false;
			}
		}
		return true;
	}

	bool coloringBipartiteUsingDFS() {
		vector<int> color(graph.size(), -1);
		for(int i=0; i<graph.size(); i++) {
			if(color[i]==-1) {
				if(!colorBipartite(color, i)) {
					return false;
				}
			}
		}
		return true;
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
    cout<<g1.coloringBipartiteUsingDFS()<<endl;
    return 0;
}