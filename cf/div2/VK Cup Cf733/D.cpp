#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;cin>>n;
    	vector<ll> v(n);
    	set<ll,greater<ll>> s;
    	for(auto &c: v){
    		cin>>c;
    		c--;
    		s.insert(c);
    	}
    	vector<bool> cou(n , false);
    	vector<ll> ans(n , -1);
    	unordered_map<ll,ll> mp;
    	ll count = 0;
    	for(int i=0;i<n and !s.empty();i++){
    		ll value = v[i];;
    		if(s.find(value)!=s.end()){
    			count++;
    			ans[i]= value+1;
    			mp[value]=i;
    			cou[value] = true;
    			s.erase(value);
    		}
    	}
    	s.clear();
    	for(ll i=0;i<n;i++){
    		if(cou[i]==false){
    			s.insert(i);
    		}
    	}

    	ll i=0;
    	for(auto c: s){
			while(i<n and ans[i]!=-1){
				i++;
			}
			ll value = c;
			if(c==i){
				ll val2 = mp[v[c]];
				ans[val2] = c+1;
				value = v[c];
			}
			ans[i]=value+1;
    		i++;
    	}
    	cout<<count<<endl;
    	for(auto c: ans){
    		cout<<c<<" ";
    	}
    	cout<<endl;

    }
    return 0;
}