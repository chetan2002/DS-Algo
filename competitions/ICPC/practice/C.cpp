#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n , x , y , k ;
    	cin>>n>>x>>y>>k;
    	set<ll> s;
    	for(int i=0;i<n;i++){
    		ll val;
    		cin>>val;
    		s.insert(val);
    	}

    	ll count = 0 , diffCount=0;
    	for(auto c: s){
    		if(c>=x and c<=y){
    			count++;
    		}else{
    			diffCount++;
    		}
    	}
    	ll total = y-x+1-count;
    	cout<<min(n,diffCount+count+min(k,total))<<endl;
    }
    return 0;
}