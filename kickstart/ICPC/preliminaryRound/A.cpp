#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<ll>> divi;

bool comp(vector<ll> a , vector<ll> b){
	return a.size()<=b.size();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	divi.clear();
    	ll n;cin>>n;
    	vector<vector<ll>> v;
    	for(int i=0;i<n;i++){
    		int k;cin>>k;
    		vector<ll> l(k);
    		for(int j=0;j<k;j++){
    			cin>>l[j];
    		}
    		v.push_back(l);
    	}
    	ll total = 0;
    	for(int i=0;i<n;i++){
    		vector<ll> k;
    		int prev = 0;
    		for(int j=0;j<n;j++){
    			if(prev<v[i][j]){
    				k.push_back(v[i][j]);
    			}else{
    				total += min((ll)(k.size()) , (ll)(n-j+1));
    				divi.push_back(k);
    				k.clear();
    				k.push_back(v[i][j]);
    			}
    		}
    		if(k.size()!=0){
    			divi.push_back(k);
    		}
    	}

    	sort(divi.begin(),divi.end() , comp);
    	ll sum = 0;
    	for(auto c: divi){
    		sum += sum+(c.size());
    	}
    	cout<<total+sum<<endl;

    }
    return 0;
}