#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n , k;cin>>n>>k;
    	vector<ll> ac(k);
    	vector<ll> tem(k);
    	for(auto &i: ac){cin>>i;i-=1;}
    	for(auto &i: tem){cin>>i;}
        unordered_map<ll,ll> mp;
    	for(int i=0;i<k;i++){
            mp[ac[i]]=tem[i];
        }
        // for(auto c: mp){
        //     cout<<c.first<<" "<<c.second<<endl;;
        // }
        vector<ll> v(n,INT_MAX);
        for(int i=0;i<n;i++){
            if(mp.find(i)!=mp.end()){
                v[i] = mp[i];
            }
        }


        for(int i=1;i<n;i++){
            v[i] = min(v[i],v[i-1]+1);
        }
        for(int i=n-2;i>=0;i--){
            v[i] = min(v[i] , v[i+1]+1);
        }

        for(auto c: v){
            cout<<c<<" ";
        }
        cout<<endl;
    }
    return 0;
}