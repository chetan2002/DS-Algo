#include<bits/stdc++.h>
using namespace std;
#define ll long long int


void rotate(vector<ll> &v , vector<ll> &v2 , ll n , ll k){
	for(int i=0;i<n;i++){
		v2[i] = v[(i+k)%n];
	}
}
void print(vector<ll> &v){
	for(auto c: v){
		cout<<c<<" ";
	}
	cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;
    	vector<ll> v(n);
    	for(auto &c: v){
    		cin>>c;
    	}

    	sort(v.begin(),v.end());
    	ll k=0;
    	for(int i=1;i<n;i++){
    		if(v[i]==v[i-1]){
    			k=i;
    			break;
    		}
    	}
    	if(k>0){
    		vector<ll> v2(n);
    		rotate(v,v2,n,k);
    		print(v2);
    	}else{
    		int dif = v[n-1]-v[0];
    		for(int i=1;i<n;i++){
    			if(v[i]-v[i-1] <dif){
    				dif = v[i]-v[i-1];
    				k=i;
    			}
    		}
    		vector<ll> v2(n);
    		rotate(v,v2,n,k);
    		print(v2);
    	}
    }
    return 0;
}