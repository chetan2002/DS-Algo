#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n , q;
vector<ll> preorder;
vector<ll> sorted;
vector<vector<ll>> v;
vector<ll> maxInd;
int currentInd ;
void dfs(int i){
	sorted[currentInd] = i;
	preorder[i] = currentInd++;
	for(auto c: v[i]){
		dfs(c);
	}
	maxInd[i] = currentInd-1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    v.resize(n);
    for(int i=1;i<n;i++){
    	ll val;
    	cin>>val;
    	val--;
    	v[val].push_back(i);
    }
    preorder.resize(n);
    sorted.resize(n);
    maxInd.resize(n);
    currentInd = 0;
    dfs(0);

    for(int i=0;i<q;i++){
    	ll u ,k;
    	cin>>u>>k;
    	u-- , k--;
    	k += preorder[u];
    	int ans = -1;
    	if(k<=maxInd[u]){
    		ans = sorted[k]+1;
    	}
    	cout<<ans<<endl;
    }
    return 0;
}