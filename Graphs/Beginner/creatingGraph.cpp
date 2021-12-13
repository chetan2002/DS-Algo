#include<bits/stdc++.h>
using namespace std;


// using adjacency matrix
// O(n^2) space
class adjacencyMatrixGraph {
	vector<vector<int>> graph;
public:
	adjacencyMatrixGraph(int n) {
		graph.resize(n+1,vector<int>(n+1, 0));
	}
	void push(int u, int v, int wt) {
		graph[u][v] = wt;
		// if undirected
		graph[v][u] = wt;
	}
};


// using adjacency list
// O(n + 2E) space
class Graph {
	vector<vector<pair<int,int>>> graph;	//for edge + weight
public:
	Graph(int n) {
		graph.resize(n+1);
	}
	void push(int u, int v, int wt) {
		graph[u].push_back({v, wt});
		graph[v].push_back({u, wt});
	}
};

int main(){ 
	int n, m;	// vert , edge
	cin>>n>>m;
	Graph g1(n);
	for(int i=0; i<m; i++) {
		int u, v, wt;
		cin>>u>>v>>wt;
		g1.push(u, v, wt);
	}

}