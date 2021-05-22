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
    	string s;
    	cin>>s;
    		
    	ll noOfUnsetBits = 0;
    	for(auto c: s){
    		if(c=='0'){
    			noOfUnsetBits++;
    		}
    	}
    	if(noOfUnsetBits==1){
    		cout<<"BOB"<<endl;
    	}else
    	if(noOfUnsetBits%2==1){
    		cout<<"ALICE"<<endl;
    	}else{
    		cout<<"BOB"<<endl;
    	}
    }
    return 0;
}