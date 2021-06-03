#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n , s , k;
    	cin>>n>>s>>k;
    	unordered_set<ll> v;
    	for(int i=0;i<k;i++){
    		int val;
    		cin>>val;
    		v.insert(val);
    	}
    	ll answer = n;
    	for(ll i=s;i>=1;i--){
    		if(v.find(i)==v.end()){
    			answer = min(answer , abs(s-i));
    			break;
    		}
    	}

    	for(ll i=s;i<=n;i++){
    		if(v.find(i)==v.end()){
    			answer = min(answer , abs(s-i));
    			break;
    		}
    	}

    	cout<<answer<<endl;

    }
    return 0;
}