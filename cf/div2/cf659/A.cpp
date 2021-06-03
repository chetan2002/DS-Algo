#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n ;
    	cin>>n;
    	vector<ll> v(n);
    	ll maxi = 0;
    	for(ll i=0;i<n;i++){
    		cin>>v[i];
    		maxi = max(maxi , v[i]);
    	}
    	string prev ="k";
    	int lastI = 0;
    	char pre = 'b';
    	for(auto c: v){
    		string my = prev.substr(0,lastI);
    		int left = c-lastI;
    		if(left>0){
    			string k(left , 'a');
    			pre = k[0];
    			my+=k;
    		}
    		if(c==0){
    			if(lastI==0){
    				int z= 'z';
    				int pr= pre;
    				char temp;
					temp= 'b'+((pr + 1)%25);
    				pre = temp;
    				my+=temp;
    			}else{
    				my+=pre;
    			}
    		}
    		prev = my;
    		lastI = c;

    		cout<<my<<endl;
    	}
    	if(lastI==0){
			int z= 'z';
			int pr= pre;
			char temp;
			temp= 'b'+((pr + 1)%25);
			pre = temp;
			cout<<temp<<endl;
		}else{
    		cout<<prev.substr(0,lastI)<<endl;
		}

    }
    return 0;
}