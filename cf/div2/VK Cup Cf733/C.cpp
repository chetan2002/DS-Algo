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
    	vector<ll> vm(n) , vl(n);
    	for(auto &i: vm){
    		cin>>i;
    	}
    	for(auto &i: vl){
    		cin>>i;
    	}

    	sort(vm.begin(),vm.end(),greater<ll>());
    	sort(vl.begin(),vl.end(),greater<ll>());

    	ll start = n- (n/4);
    	ll mySum = 0;
    	mySum = accumulate(vm.begin(),vm.begin()+start,mySum);
    	ll herSum = 0;
    	herSum = accumulate(vl.begin(),vl.begin()+start,herSum);

    	// cout<<mySum<<" "<<herSum<<endl;
    	ll count = 0;
    	ll startM = start-1;
    	ll startH = start;
    	start = n;
    	while(mySum<herSum){
    		start++;
    		mySum+=100;
    		count++;
    		if(start%4==0 and startM>=0){
    			mySum-=vm[startM--];
    		}
    		if(start%4!=0 and startH<n){
    			herSum+=vl[startH++];
    		}
    	}
    	// cout<<mySum<<" "<<herSum<<endl;
    	cout<<count<<endl;


    }
    return 0;
}