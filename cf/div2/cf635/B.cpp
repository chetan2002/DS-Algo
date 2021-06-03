#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll x , n, m ;
    	cin>>x>>n>>m;

    	while(n-- and (x>20)){
    		x = (x/2) + 10;
    	}

    	while(m-- and x>0){
    		x-=10;
    	}

    	if(x>0){
    		cout<<"NO"<<endl;
    	}else{
    		cout<<"YES"<<endl;
    	}
    }
    return 0;
}