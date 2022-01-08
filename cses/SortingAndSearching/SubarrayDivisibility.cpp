#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	   
    ll n;
    cin>>n;
    vector<ll> v(n);
    ll sum =0;
    unordered_map<ll, ll> mp;
    ll count =0;
    mp[0]++;
    for(auto &c: v) {
    	cin>>c;
    	sum= (sum + c + 100000*n)%n;
    	count += mp[sum];
    	mp[sum]++;
    }
    cout<<count<<endl;
    return 0;
}