#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> ans;


int fill(int i ,int start, int count , vector<ll> &v){
	if(i==start){
		return count;
	}
	if(ans[i]!=-1){
		return ans[i];
	}
	return ans[i] = fill(v[i] , start , count+1 , v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;cin>>n;
    	vector<ll> v(n);
    	for(auto &i: v){
    		cin>>i;
    		i = i-1;
    	}
    	ans.clear();
    	ans.resize(n , -1);
    	for(int i=0;i<n;i++){
    		if(ans[i]!=-1){
    			continue;
    		}else{
    			ans[i]=fill(v[i] , i , 1 , v);
    		}
    	}
    	for(auto c: ans){
    		cout<<c<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}