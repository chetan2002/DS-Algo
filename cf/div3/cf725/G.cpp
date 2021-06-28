#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll a , b, c , d;
    	cin>>a>>b>>c>>d;

    	ll count =0 ;
    	if(a>b){
    		swap(a,b);
    	}
    	if(c>d){
    		swap(c,d);
    	}

    	while(a>c and b>d){
    		a-=c , b-=d;
    		count++;
    		if(a>b){
	    		swap(a,b);
	    	}
	    	if(c>d){
	    		swap(c,d);
	    	}
    	}

    	cout<<count<<endl;
    }
    return 0;
}