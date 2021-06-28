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
    	ll a[n] , b[n];
    	for(int i=0;i<n;i++){
    		cin>>a[i];
    	}
    	for(int i=0;i<n;i++){
    		cin>>b[i];
    	}
    	if(a[0]!=b[0]){
    		cout<<"NO"<<endl;
    		continue;
    	}
    	ll subAr[n];
    	for(int i=0;i<n;i++){
    		subAr[i] = b[i]-a[i];
    	}
    	bool pos=false , neg = false;
    	bool yes=true;
    	for(int i=0;i<n;i++){
    		if(subAr[i]>0){
    			if(!pos){
    				yes = false;
    			}
    		}
    		if(subAr[i]<0){
    			if(!neg){
    				yes = false;
    			}
    		}
    		if(a[i]>0){
    			pos = true;
    		}
    		if(a[i]<0){
    			neg = true;
    		}
    	}
    	if(yes){
    		cout<<"YES"<<endl;
    	}else{
    		cout<<"NO"<<endl;
    	}
    }
    return 0;
}