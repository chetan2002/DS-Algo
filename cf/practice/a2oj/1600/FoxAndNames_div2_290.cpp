#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;   
vector<string> v;

int convert(char c) {
	return c-'a';
}
class Graph {
	map<char, vector<char>> graph;
	vector<bool> visited;
	vector<char> Stack;
	unordered_set<char> s;
	bool impossible = false;
public:
	Graph() {
		graph.clear();
		visited.resize(26, false);
	}
	void addEdge(char u, char v) {
		graph[u].push_back(v);
	}
	void dfs(char c) {
		if(s.find(c)!=s.end()) {
			impossible = true;
			return;
		}
		if(visited[convert(c)]) {
			return;
		}
		s.insert(c);
		visited[convert(c)] = true;
		for(auto a: graph[c]) {
			dfs(a);
		}
		s.erase(c);
		Stack.push_back(c);
	}
	string topologicalSort() {
		for(auto c: graph) {
			// for(auto a: visited) {
			// 	cout<<a<<" ";
			// }
			// cout<<endl;
			// print();
			// cout<<visited[convert('r')]<<endl;
			if(!visited[convert(c.first)]) {
				// cout<<c.first<<endl;
				s.clear();
				dfs(c.first);
			}
		}

		string ans = "";
		for(int i=Stack.size()-1; i>=0; i--) {
			ans += Stack[i];
		}
		for(char c = 'a'; c<='z'; c++) {
			if(!visited[convert(c)]) {
				ans+=c;
			}
		}
		if(impossible) {
			return "Impossible";
		}
		return ans;
	}
	void print() {
		for(auto c: graph) {
			cout<<c.first<<" {";
			for(auto a: c.second) {
				cout<<a<<" ";
			}
			cout<<"}"<<endl;
		}
	}
};

pair<char, char> extract(string a, string b) {
	int i=0;
	while(i<a.length() and i<b.length() and a[i]==b[i]) {
		i++;
	}
	if(i==a.length()) {
		return {'0', '1'};
	}
	if(i==b.length()) {
		return {'1', '0'};
	}
	return {a[i], b[i]};
}
string answer() {
	Graph g1;
	for(int i=1; i<v.size(); i++) {
		auto p = extract(v[i-1], v[i]);
		if(p.first=='0') {
			continue;
		}else
		if(p.second=='0') {
			return "Impossible";
		}
		else {
			g1.addEdge(p.first, p.second);
		}
		// cout<<p.first<<" "<<p.second<<endl;
	}
	// g1.print();
	return g1.topologicalSort();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    v.resize(n);
    for(auto &c: v) {
    	cin>>c;
    }
    // Graph g1;
    // for(int i=0; i<n;i++) {
    // 	char c1, c2;
    // 	cin>>c1>>c2;
    // 	g1.addEdge(c1, c2);
    // }
    // g1.print();
    // cout<<g1.topologicalSort();
    cout<<answer()<<endl;
    return 0;
}