#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;
    	ll countO= 0 , countE = 0;
    	for(int i=0;i<2*n;i++){
    		ll val;
    		cin>>val;
    		if(val%2==0){
    			countE++;
    		}else
    		if(val%2==1){
    			countO++;
    		}
    	}	
    	// cout<<countO<<" "<<countE<<endl;
    	if(countO==countE){
    		cout<<"Yes"<<endl;
    	}else{
    		cout<<"No"<<endl;
    	}
    }
    return 0;
}