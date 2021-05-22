#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n ;cin>>n;
    	ll a , b , c ;
    	cin>>a>>b>>c;
    	string s;
    	cin>>s;

    	string ans(n,'c');

    	for(int i=0;i<n;i++){
    		if(s[i]=='R' and b!=0){
    			ans[i] = 'P';
    			b--;
    		}else
    		if(s[i]=='P' and c!=0){
    			ans[i] = 'S';
    			c--;
    		}else
    		if(s[i]=='S' and a!=0){
    			ans[i] = 'R';
    			a--;
    		}
    	}

		for(int i=0;i<n;i++){
			if(ans[i]!='c'){
				continue;
			}
    		if(s[i]=='R' and a!=0){
    			ans[i] = 'R';
    			a--;
    		}else
    		if(s[i]=='P' and b!=0){
    			ans[i] = 'P';
    			b--;
    		}else
    		if(s[i]=='S' and c!=0){
    			ans[i] = 'S';
    			c--;
    		}
    	}

		for(int i=0;i<n;i++){
			if(ans[i]!='c'){
				continue;
			}
    		if(s[i]=='R' and c!=0){
    			ans[i] = 'S';
    			c--;
    		}else
    		if(s[i]=='P' and a!=0){
    			ans[i] = 'R';
    			a--;
    		}else
    		if(s[i]=='S' and b!=0){
    			ans[i] = 'P';
    			b--;
    		}
    	}

    	ll w = 0 , d = 0 , l = 0 ;
    	for(int i=0;i<n;i++){
    		if(ans[i]=='R'){
    			if(s[i]=='R'){
    				d++;
    			}
    			if(s[i]=='P'){
    				l++;
    			}
    			if(s[i]=='S'){
    				w++;
    			}
    		}
    		if(ans[i]=='P'){
    			if(s[i]=='R'){
    				w++;
    			}
    			if(s[i]=='P'){
    				d++;
    			}
    			if(s[i]=='S'){
    				l++;
    			}
    		}
    		if(ans[i]=='S'){
    			if(s[i]=='R'){
    				l++;
    			}
    			if(s[i]=='P'){
    				w++;
    			}
    			if(s[i]=='S'){
    				d++;
    			}
    		}
    	}

    	// cout<<a<<" "<<b<<" "<<c<<" "<<endl;
    	// cout<<w<<" "<<d<<" "<<l<<endl;

    	if(w>=ceil((double)n/2)){
    		cout<<"YES"<<endl;
    		cout<<ans<<endl;
    	}else{
    		cout<<"NO"<<endl;
    	}
    }
    return 0;
}