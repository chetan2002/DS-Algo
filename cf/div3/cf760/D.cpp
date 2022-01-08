#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n, k;
    	cin>>n>>k;
    	vector<ll> v(n);
    	for(auto &c: v) {
    		cin>>c;
    	}
        ll sum =0;
    	sort(v.begin(), v.end(), greater<ll>());
        ll rem = n-2*k;
        while(rem) {
            sum+=v.back();
            rem--;
            v.pop_back();
        }
        unordered_map<ll, ll> mp;
        for(auto c: v) {
            mp[c]++;
        }
        // cout<<sum<<endl;
        for(auto c: mp) {
            if(c.second > k) {
                ll val = c.second;
                ll val2 = v.size()-val;
                val = val-val2;
                sum+=val/2;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}