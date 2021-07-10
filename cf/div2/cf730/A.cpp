#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll a , b;
    	cin>>a>>b;

    	if(a==b){
    		cout<<"0 0"<<endl;
    		continue;
    	}
    	if(b<a){
    		swap(a,b);
    	}
    	ll diff = b-a;

    	ll val = b%diff;
    	if(val>diff/2){
    		cout<<diff<<" "<<diff-val<<endl;
    	}else{
    		cout<<diff<<" "<<val<<endl;
    	}
    }
    return 0;
}