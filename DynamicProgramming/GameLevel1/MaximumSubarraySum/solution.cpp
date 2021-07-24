#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//given an array , find maximum subarray sum

ll kadane(vector<ll> &v){
	ll sum = 0 , maximum = INT_MIN;
	for(auto c: v){
		sum = max(sum+c , c);
		maximum = max(maximum , sum);
	}
	return maximum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll n; cin>>n;
 	vector<ll> v(n);
 	for(auto &i: v) cin>>i;

 	cout<<kadane(v)<<endl;

    return 0;
}