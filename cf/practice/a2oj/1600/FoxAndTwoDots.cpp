#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m;
vector<string> v;
vector<vector<bool>> vis;
vector<int> pos = {-1, 0, 1, 0, -1};

bool isValid(int i, int j) {
	if(i<0 or j<0 or i>=n or j>=m) {
		return false;
	}
	return true;
}
bool dfs(int i, int j, int a, int b) {
	if(vis[i][j]) {
		return true;
	}
	bool ans =false;
	vis[i][j]= true;
	for(int k=1; k<5; k++) {
		int x = i+pos[k-1], y = j+pos[k];
		if(isValid(x, y) and v[x][y]==v[i][j]) {
			if(x==a and y==b) {
				continue;
			}
			ans = ans or dfs(x,y, i, j);
		}
	}
	return ans;
}
bool checkChain() {
	vis.resize(n, vector<bool>(m, false));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(!vis[i][j]) {
				bool ans = dfs(i, j, -1, -1);
				if(ans) {
					return true;
				}
			}
		}
	}
	return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    v.resize(n);
    for(auto &c: v){ 
    	cin>>c;
    }
    if(checkChain()) {
    	cout<<"Yes"<<endl;
    }else {
    	cout<<"No"<<endl;
    }
    return 0;
}