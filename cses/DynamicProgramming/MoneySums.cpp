#include<bits/stdc++.h>
using namespace std;
#define ll long long int
set<int> Set;
vector<ll> v;

void moneySum(ll target) {
	vector<bool> dp(target+1, 0);
	dp[0] = true;
	for(auto c: v) {
		for(int i=target; i>=0; i--) {
			if(i-c>=0) {
				dp[i] = dp[i] or dp[i-c];
				if(dp[i]) {
					Set.insert(i);
				}
			}
		}
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;
 	cin>>n;
 	v.resize(n);
 	ll sum =0;
 	for(auto &c: v) {
 		cin>>c;
 		sum+=c;
 	}
 	sort(v.begin(), v.end());
 	moneySum(sum);
 	cout<<Set.size()<<endl;
 	for(auto c: Set) {
 		cout<<c<<" ";
 	}
 	cout<<endl;
    return 0;
}