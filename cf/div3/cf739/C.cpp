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
    	ll sqN = sqrt(n);
    	ll numberOfElInNext = sqN+1;
    	ll diff = n-pow(sqN,2);
    	if(diff==0){
    		cout<<sqN<<" "<<1<<endl;
    	}else
    	if(diff<=numberOfElInNext){
    		cout<<diff<<" "<<numberOfElInNext<<endl;
    	}else{
    		cout<<numberOfElInNext<<" "<<numberOfElInNext-(diff-numberOfElInNext)<<endl;

    	}
    }
    return 0;
}