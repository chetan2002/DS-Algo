#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    vector<ll> powertwo(34,0);
    ll ans = 1 , sum = 1;
    for(auto &c: powertwo){
    	c = sum;
    	ans = ans*2;
    	sum += ans;
    }
    // for(auto c: powertwo){
    // 	cout<<c<<" ";
    // }
    while(t--){
    	ll n; 
    	cin>>n;
    	vector<ll> v(n);
    	ll last = LLONG_MIN;
    	ll mini = LLONG_MAX;
    	for(auto &c: v){
    		cin>>c;
    		if(c>=last){
    			last = c;
    		}else{
    			mini = min(c-last , mini);
    		}
    		// cout<<last<<" "<<mini<<endl;
    	}

    	if(mini==LLONG_MAX){
    		cout<<"0"<<endl;
    		continue;
    	}
    	mini = abs(mini);
    	for(int i=0;i<=33;i++){
    		if(powertwo[i]>=mini){
    			cout<<i+1<<endl;
    			break;
    		}
    	}

    }
    return 0;
}