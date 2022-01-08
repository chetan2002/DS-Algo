#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
 	ll n, a, b;
 	cin>>n>>a>>b;
 	vector<ll> v(n+1);
 	ll sum = 0;
 	for(ll i=1; i<=n; i++) {
 		cin>>v[i];
 		sum+=v[i];
 		v[i] = sum;
 	}
 	multiset<ll> left;
 	ll answer = LLONG_MIN;
 	for(ll i=a; i<=b; i++) {
 		left.insert(v[i-a]);
 		answer = max(answer, v[i] - *left.begin());
 	}
 	for(ll i=b+1; i<=n; i++) {
 		left.erase(left.find(v[i-b-1]));
 		left.insert(v[i-a]);
 		answer = max(answer, v[i] - *left.begin());
 	}
 	cout<<answer<<endl;
    return 0;
}