#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9 + 7;
vector<string> grid;
vector<vector<int>> dp;

void answer() {
	int n = grid.size();
	dp.resize(n, vector<int>(n, 0));
	dp[0][0] = 1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(grid[i][j] == '*') {
				dp[i][j] = 0;
				continue;
			}
			if(i>0) {
				dp[i][j] += (dp[i-1][j]%MOD);
			}
			if(j>0) {
				dp[i][j] += (dp[i][j-1]%MOD);
			}
			dp[i][j] = dp[i][j]%MOD;
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;cin>>n;
 	grid.resize(n);
 	for(auto &c: grid) {
 		cin>>c;
 	}
 	answer();
 	cout<<dp[n-1][n-1]<<endl;
    return 0;
}