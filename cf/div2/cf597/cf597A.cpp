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

    	if(a==1 || b==1){
    		cout<<"Finite"<<endl;
    	}else{
    		if(__gcd(a,b)==1){
    			cout<<"Finite"<<endl;
    		}else{
    			cout<<"Infinite"<<endl;
    		}
    	}

    }
    return 0;
}