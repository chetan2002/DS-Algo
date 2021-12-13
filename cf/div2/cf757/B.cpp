#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;
    	vector<pair<ll,ll>> v(n);
    	for(int i=0; i<n; i++) {
    		v[i].second = i;
    		cin>>v[i].first;
    	}
    	sort(v.begin(), v.end(), greater<pair<ll,ll>>());
    	vector<ll> ans(n+1);
    	ans[0] = (n+1)/2;
    	ll total =0 ;
    	int value = 1;
    	for(int i=0; i<n; i++) {
    		ans[v[i].second+1] = ans[0]-value;
    		total += 2*abs(ans[v[i].second+1]-ans[0])*v[i].first;
    		i++;
    		if(i<n) {
	    		ans[v[i].second+1] = ans[0]+value;
	    		total+= 2*abs(ans[v[i].second+1]-ans[0])*v[i].first;
    		}
    		value++;
    	}
    	cout<<total<<endl;
    	for(auto c: ans) {
    		cout<<c<<" ";
    	}
    	cout<<endl;

    }
    return 0;
}