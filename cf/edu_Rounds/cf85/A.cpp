#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n ;
    	cin>>n;
    	bool win = true;
    	ll num1 = 0 , num2 = 0;
    	for(int i=0;i<n;i++){
    		ll val1 , val2;
    		cin>>val1>>val2;
    		int a1 = abs(num1-val1) , a2 = abs(num2-val2);
    		if(val1<num1 || val2<num2 || val1<val2 || a1<a2){
    			win = false;
    		}else{
    			num1 = val1 , num2 = val2;
    		}
    	}
    	if(win){
    		cout<<"YES"<<endl;
    	}else{
    		cout<<"NO"<<endl;
    	}

    }
    return 0;
}