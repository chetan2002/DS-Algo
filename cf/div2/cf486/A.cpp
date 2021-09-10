#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n , k;
    cin>>n>>k;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
    	cin>>v[i];
    }

    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
    	if(mp.find(v[i])!=mp.end()){
    		continue;
    	}
    	mp[v[i]]=i+1;
    }
    if(mp.size()<k){
    	cout<<"NO"<<endl;
    }else{
    	cout<<"YES"<<endl;
        int i=0;
    	for(auto c: mp){
            if(i==k){
                break;
            }
            i++;
    		cout<<c.second<<" ";
    	}
    }
    return 0;
}