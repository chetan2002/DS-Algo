#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    vector<int> xo(1,0);
    for(int i=1;i<=300000;i++){
    	xo.push_back(xo.back()^i);
    }
    while(t--){
    	ll a;cin>>a;	// ex element
    	ll b; cin>>b;	// xor of all

    	// if(a==1 and b==1){
    	// 	cout<<3<<endl;
    	// 	continue;
    	// }
    	int xorP= 0;
    	int ans = a;
    	// for(int i=1;i<a;i++){
    	// 	xorP=xorP^i;
    	// }
    	xorP = xo[a-1];
    	// cout<<xorP<<" "<<a<<" "<<b<<endl;
    	if(xorP==b){
    		cout<<ans<<endl;
    		continue;
    	}
    	int xorR = xorP^b;
    	ans++;
    	if(xorR==a){
    		ans++;
    	}
    	cout<<ans<<endl;
    }
    return 0;
}