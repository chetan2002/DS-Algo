#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> v;
vector<vector<int>> mp;
vector<bool> visited;

void dfs(int V , ll &mini){
	visited[V] = true;
	for(auto c: mp[V]){
		if(!visited[c]){
			mini = min(mini , v[c]);
			dfs(c , mini);
		}
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll n , m;
 	cin>>n>>m;
 	v.resize(n);
 	for(ll i=0;i<n;i++){
 		cin>>v[i];
 	}
 	mp.resize(n);
 	for(int i=0;i<m;i++){
 		ll val1 , val2;
 		cin>>val1>>val2;
 		val1-- , val2--;
 		mp[val1].push_back(val2);
 		mp[val2].push_back(val1);
 	}
 	visited.resize(n,false);
 	ll sum = 0;
 	for(ll i=0;i<n;i++){
 		if(!visited[i]){
 			ll mini = v[i];
 			dfs(i , mini);
 			sum += mini;
 		}
 	}
 	cout<<sum<<endl;
    return 0;
}