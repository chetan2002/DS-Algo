#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	int a , b , c , d;
    	cin>>a>>b>>c>>d;


    	if(a>b){
    		if(c>d){
    			if(a>d and c>b){
    				cout<<"YES"<<endl;
    			}else{
    				cout<<"NO"<<endl;
    			}
    		}else{
    			if(a>c and d>b){
    				cout<<"YES"<<endl;
    			}else{
    				cout<<"NO"<<endl;
    			}
    		}
    	}else{
    		if(c>d){
    			if(b>d and c>a){
    				cout<<"YES"<<endl;
    			}else{
    				cout<<"NO"<<endl;
    			}
    		}else{
    			if(b>c and d>a){
    				cout<<"YES"<<endl;
    			}else{
    				cout<<"NO"<<endl;
    			}
    		}
    	}

    }
    return 0;
}