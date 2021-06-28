#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ll test;
    cin>>test;
    while(test--){
    	ll number , startGap , t;
    	cin>>number>>startGap>>t;
    	ll ans = (t-0+startGap)/startGap;
    	ll finalAnswer = 0;
    	if(ans<number){
	    	finalAnswer += (number-ans+1)*(ans-1);
	    	
	    	ll k = (ans-2);
	    	finalAnswer += (k*(k+1))/2;
	    	cout<<finalAnswer<<endl;
    	}else{
    		finalAnswer = (number*(number-1))/2;
    		cout<<finalAnswer<<endl;
    	}
    }
    return 0;
}