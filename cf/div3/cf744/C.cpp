#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<string> vs;
vector<vector<int>> vis;
ll n , m , k;

bool checkR(int i , int j , int len) {
	
	if(len==0){
		return true;
	}
	if(i<0 || j>=m) {
		return false;
	}
	if(vs[i][j] != '*') {
		return false;
	}
	vis[i][j]++;
	bool ans = checkR(i-1, j+1, len-1);
	if(!ans) {
		vis[i][j]--;
	}
	return ans;
}
bool check(int i, int j , int len) {
	if(i>=n || j>=m) {
		return false;
	}
	if(vs[i][j]!='*') {
		return false;
	}
	vis[i][j]++;
	bool ans1 = false,  ans2 = false;
	if(len>k) {
		vis[i][j]++;
		ans1 = checkR(i-1, j+1, len-1);
		if(!ans1) {
			vis[i][j]--;
		}
	}

	ans2 = check(i+1, j+1, len+1);
	if(!ans2) {
		vis[i][j]--;
	}

	return ans1 || ans2;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	cin>>n>>m>>k;
    	vs.clear();
    	for(auto i = 0; i<n;i++) {
    		string s;
    		cin>>s;
    		vs.push_back(s);
    	}
    	vis.clear();
    	vis.resize(n, vector<int>(m,0));
    	for(int i=0;i<n;i++) {
    		for(int j=0;j<m;j++) {
    			if(vs[i][j] == '*') {
    				int len = 1;
    				check(i, j, len);
    			}
    		}
    	}
    	bool ans = true;
    	for(int i=0;i<n;i++) {
    		for(int j=0;j<m;j++) {
    			if(vs[i][j] == '*' and vis[i][j]==0) {
    				ans = false;
    			}
    			if(vis[i][j] !=0 and vs[i][j] !='*') {
    				ans = false;
    			}
    		}
    	}
    	if(ans) {
    		cout<<"YES"<<endl;
    	}else {
    		cout<<"NO"<<endl;
    	}
    }
    return 0;
}