#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n , k;
    	cin>>n>>k;
    	k = (n*(n-1)/2)-k+1;
    	ll count = 1;
    	ll value = n-1;

    	while(k>value){
    		k-=value;
    		value--;count++;
    	}

    	string s="";
    	// cout<<count<<" "<<k<<endl;
    	for(int i=1;i<=n;i++){
    		if(i==count){
    			s+='b';
    		}else
    		if(i==count+k){
    			s+='b';
    		}else{
    			s+='a';
    		}
    	}
    	// reverse(s.begin(),s.end());
    	cout<<s<<endl;
    }
    return 0;
}