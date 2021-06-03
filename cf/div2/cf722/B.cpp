#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;
    	cin>>n;
    	vector<ll> v(n);
    	ll smallest = INT_MAX;
    	for(ll i=0;i<n;i++){
    		cin>>v[i];
    	}

    	sort(v.begin(),v.end());

    	int pos = 0;
    	for(int i=0;i<n;i++){
    		if(v[i]>0){
    			pos = i;
    			break;
    		}
    		pos = i;
    	}

    	if(pos == n-1 and v[pos]<=0){
    		cout<<n<<endl;
    	}else
    	if(pos == 0){
    		cout<<1<<endl;
    	}else
    	{
    		ll diff = INT_MAX;

    		for(int i=1;i<n;i++){
    			if(v[i]<0 and v[i-1]<0){
    				diff = min(abs(v[i]-v[i-1]) , diff);
    			}
    		}
    		ll smalNeg = INT_MIN;
    		ll neg = 0 , zer =0 , pos = INT_MAX;
    		for(auto c: v){
    			if(c<0){
    				neg++;
    				smalNeg = max(smalNeg,c);
    			}else
    			if(c==0){
    				zer++;
    			}else{
    				pos = min(pos , c);
    			}

    		}

    		ll cas1 = neg+zer;
    		ll cas2 = 0;
    		if(zer>0 and pos<=abs(smalNeg) and pos<=diff){

    			cas2 = neg+1+1;
    		}
    		ll cas3 = 0;
    		if(pos<=diff){
    			cas3 = neg+1;
    		}
    		cout<<max(cas2,max(cas3,cas1))<<endl;;
    	}
    }
    return 0;
}