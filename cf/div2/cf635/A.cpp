#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll a , b , c, d;
    	cin>>a>>b>>c>>d;

    	if(a==b){
    		if(c==d){
    			cout<<a<<" "<<c<<" "<<c<<endl;
    		}else{
    			cout<<a<<" "<<c<<" "<<c<<endl;
    		}
    	}else
    	{
    		if(b==c){
    			cout<<b<<" "<<b<<" "<<b<<endl;
    		}else
    		if(c==d){
    			cout<<b<<" "<<c-1<<" "<<c<<endl;
    		}else{
    			cout<<b<<" "<<c<<" "<<c<<endl;
    		}
    	}

    }
    return 0;
}