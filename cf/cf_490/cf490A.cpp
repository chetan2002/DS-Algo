#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;
 	cin>>n;
 	ll k;
 	cin>>k;
 	vector<ll> v(n);
 	for(ll i=0;i<n;i++){
 		cin>>v[i];
 	}
    int countL = 0;
    for(int i=0;i<n;i++){
    	if(v[i]<=k){
    		countL++;
    	}else{
    		break;
    	}
    }
    int countR=0;
    for(int i=n-1;i>=0;i--){
    	if(v[i]<=k){
    		countR++;
    	}else{
    		break;
    	}
    }
    if(countR==n){
    	cout<<n<<endl;
    }else{
    	cout<<countR+countL<<endl;
    }
    return 0;
}