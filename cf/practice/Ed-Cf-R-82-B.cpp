#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n, g, b;
    	cin>>n>>g>>b;

    	ll half = (n+1)/2;

    	ll answer = (half/g)*b;
    	if(half%g==0) {
    		answer-=b;
    	}
    	answer += half;
    	if(answer<n) {
    		cout<<n<<endl;
    	}else {
    		cout<<answer<<endl;
    	}

    }
    return 0;
}