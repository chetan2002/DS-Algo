#include<bits/stdc++.h>
using namespace std;
 
#define IO    ios::sync_with_stdio(false);cin.tie(0);
#define int   long long
#define endl  '\n'
 
mt19937 rnd(time(0));
 
 
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
 
 
vector<int> g[N];
int c[N];
 
void dfs(int u, int p){
	for(auto i : g[u]){
		if(i == p)
			continue;
 
		dfs(i, u);
		c[u] += c[i];
	}
}
 
int32_t main(){
 
	IO
 
	int n;
	cin >> n;
 
	int p;
	for(int i = 2 ; i <= n ; i++){
		cin >> p;
		g[p].push_back(i);
		g[i].push_back(p);
	}
 
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
 
	for(int i = 2 ; i <= n; i++){
		if((int)g[i].size() == 1)
			c[i] = 1;
	}
 
	dfs(1, 0);
 
	// for(int i = 1 ; i <= n ; i++) cout << c[i] << ' '; cout << endl;
 
	sort(c + 1, c + n + 1);
 
	for(int i = 1 ; i <= n ; i++)
		cout << c[i] << ' ';
	cout << endl;
 
	return 0;
}