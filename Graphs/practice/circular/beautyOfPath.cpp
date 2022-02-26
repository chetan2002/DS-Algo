#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class Graph {
    vector<vector<int>> graph;
    string s;
public:
    Graph(int n, string s) {
        graph.resize(n);
        this->s = s;
    }
    void push(int u, int v) {
        graph[u].push_back(v);
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

    void dfs(int i, int &maxi, vector<int> freq) {
    	freq[s[i]-'a']++;
    	for(auto c: freq) {
    		maxi = max(c, maxi);
    	}
    	for(auto c: graph[i]) {
    		dfs(c, maxi, freq);
    	}
    }
    int answer() {
    	vector<int> freq(26, 0);
    	int maxi =0;
    	for(int i=0; i<graph.size(); i++) {
			dfs(i, maxi, freq);
    	}
    	return maxi;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n, m;   
 	cin>>n>>m;
 	string s;
 	cin>>s;
 	vector<int> x;
 	vector<int> y;
 	for(int i=0; i<m; i++) {
 		int val;
 		cin>>val;
 		x.push_back(val);
 	}
 	for(int i=0; i<m; i++) {
 		int val;
 		cin>>val;
 		y.push_back(val);
 	}
 	Graph g1(n, s);
    for(int i=0; i<m; i++) {
    	g1.push(x[i]-1, y[i]-1);
    }

    if(g1.graphHasCycle()) {
    	cout<<"-1"<<endl;
    }else {
    	cout<<g1.answer()<<endl;
    }
    return 0;
}