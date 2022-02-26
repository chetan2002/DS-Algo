#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> v; 


ll lis() {
	vector<ll> dp;
	for(auto c: v) {
		int i=0, j=dp.size();
		while(i<j) {
			int mid = i + (j-i)/2;
			if(dp[mid]<c) {
				i = mid+1;
			}else {
				j = mid;
			}
		}
		if(i==dp.size()) dp.push_back(c);
		dp[i] = c;
	}
	return dp.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n; cin>>n;
 	v.resize(n);
	for(auto &c: v) {
		cin>>c;
	}   
	cout<<lis()<<endl;
    return 0;
}