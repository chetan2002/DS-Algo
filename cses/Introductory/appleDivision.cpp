#include<bits/stdc++.h>
using namespace std;
#define ll long long int


void answer(ll i , vector<ll> v , ll sum1 , ll sum2 , ll &mini){
	if(i==v.size()){
		mini = min(abs(sum1-sum2) , mini);
		// cout<<sum1<<" "<<sum2<<endl;
		return;
	}

	answer(i+1 , v , sum1+v[i] , sum2 , mini);
	answer(i+1 , v , sum1 , sum2+v[i] , mini);
	return;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll n;cin>>n;

 	vector<ll> v(n);
 	for(ll i=0;i<n;i++){
 		cin>>v[i];
 	}   
 	ll mini = INT_MAX;
 	answer(0 , v , 0 , 0 , mini);
 	cout<<mini<<endl;
    return 0;
}