#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n, k;
    	cin>>n>>k;
    	n--;
    	set<ll> s;

    	if(n<=3 and k==n) {
    		cout<<-1<<endl;
    		continue;
    	}else{
	    	if(n==k) {
		    	for(int i=2; i<n-2; i++) {
		    		s.insert(i);
		    	}
		    	s.insert(0);
	    		cout<<n<<" "<<n-1<<endl;
	    		cout<<1<<" "<<n-2<<endl;
	    		while(s.size()>1) {
	    			auto it = s.begin();
	    			auto it2 = s.end();
	    			it2 = prev(it2);
	    			cout<<*it<<" "<<*it2<<endl;
	    			s.erase(it);
	    			s.erase(it2);
	    		}
	    		continue;
	    	}    		
    	}

    	for(int i=0; i<=n/2; i++) {
    		if(i==k or n-i == k) {
    			cout<<k<<" "<<n<<endl;
    		}else {
    			if(i==0) {
    				cout<<n-k<<" "<<0<<endl;
    			}else {
    				cout<<i<<" "<<n-i<<endl;
    			}
    		}
    	}
    }
    return 0;
}