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
    	ll w = ceil(log2(n)-1);
    	vector<int> v;

        long long int p=pow(2,w);

        for(int i=0; i<p; i++){
            v.push_back(i^(i/2));
        }
        reverse(v.begin(), v.end());
        for(ll i=p; i<n; i++) {
        	v.push_back(i);
        }
        for(auto c: v) {
        	cout<<c<<" ";
        }
        cout<<endl;
    }
    return 0;
}