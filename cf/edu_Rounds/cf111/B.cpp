#include<bits/stdc++.h>
using namespace std;
#define ll long long int


ll answer(ll n ,ll a ,ll b){
	ll ans = 0;
	if(a>=0 and b>=0){
		ans = n*(a+b);
	}else
	if(a>=0 and b<=0){
		ans = (a*n) + b;
	}else
	if(a<=0 and b>=0){
		ans = n*(a+b);
	}else{
		ans = (a*n)+b;
	}
	return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n , a , b;
    	cin>>n>>a>>b;
    	string s;
    	cin>>s;
    	ll ans = 0;
    	while(n>0){
    		string Ns0(n , '0');
    		string Ns1(n , '1');
    		if(s==Ns0 || s== Ns1){
    			ans+=answer(n,a,b);
    			n = 0;
    			break;
    		}else{
    			int i = 0, j= n;
    			for(int k=1;k<n;k++){
    				if(s[k]!=s[k-1]){
    					if(i==0){
    						i = k;
    					}else{
    						j = k;
    						break;
    					}
    				}
    			}
    			int size = j-i;
    			s.erase(i,size);
    			n = n-size;
    			ans+=answer(size , a , b);
    		}
    	}
    	cout<<ans<<endl;
    }
    return 0;
}