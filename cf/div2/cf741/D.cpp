#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n,q;cin>>n>>q;
    	string s;
    	cin>>s;
    	vector<int> vp(n+1);
    	for(int i=1;i<=n;i++){
    		vp[i] = vp[i-1];
    		int value = 0;
    		if(i%2==0){
				if(s[i-1]=='+'){
					value++;
				}else{
					value--;
				}
			}else{
				if(s[i-1]=='-'){
					value++;
				}else{
					value--;
				}
			}
			vp[i] +=value;
    	}
    	while(q--){
    		ll l , r;cin>>l>>r;
  			int count = vp[r] - vp[l-1];			
  			if(count == 0){
  				cout<<0<<endl;
  			}else
  			if(count%2==0){
  				cout<<2<<endl;
  			}else{
  				cout<<1<<endl;
  			}
    	}
    }
    return 0;
}