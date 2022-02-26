#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m;
vector<vector<ll>> graph;
vector<ll> inDegree;
vector<ll> dp;
ll mod = 1e9+7;

ll answer() {
	queue<ll> q;
	dp.assign(n+1, 0);
	dp[1] = 1;
	for(int i=1; i<=n; i++) {
		if(inDegree[i]==0) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		ll f = q.front();
		q.pop();
		for(auto c: graph[f]) {
			inDegree[c]--;
			dp[c]+=dp[f];
			dp[c] = dp[c]%mod;
			if(inDegree[c]==0) {
				q.push(c);
			}
		}
	}
	return dp[n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	cin>>n>>m;   
 	graph.resize(n+1);
 	inDegree.resize(n+1);
 	for(ll i=0; i<m; i++) {
 		ll u, v;
 		cin>>u>>v;
 		graph[u].push_back(v);
 		inDegree[v]++;
 	}
 	cout<<answer()<<endl;
    return 0;
}