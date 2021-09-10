#include<bits/stdc++.h>
using namespace std;
#define ll long long int


bool isPow10(ll a){
	ll i =1;
	while(i<=a){
		if(i==a) return true;
		i*=10;
	}
	return false;
}
ll split(ll a){
	ll i=1;
	while(i<=a){
		if(i==a) return i/10;

		i*=10;
	}
	return (i/10);
}
void breakVec(vector<ll> &v , ll n){
	while(v.size()<n){
		ll el = -1;
		for(int i=0;i<v.size();i++){
			ll c = v[i];
			if(!isPow10(c)){
				el = c;
				v.erase(v.begin()+i);
				break;
			}
		}
		if(el==-1){
			ll mn = 1000000000007ll;
			for(int i=0;i<v.size();i++){
				if(v[i]!=1){
					mn = min(mn,v[i]);
				}
			}

			for(int i=0;i<v.size();i++){
				if(v[i]==mn){
					el = v[i];
					v.erase(v.begin()+i);
					break;
				}
			}
		}
		ll x = split(el);
		v.push_back(x);
		v.push_back(el-x);
	
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll s , n;cin>>s>>n;
    	vector<ll> v;
    	v.push_back(s);

    	breakVec(v , n);
    	for(auto c: v){
    		cout<<c<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}