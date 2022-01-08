#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n, k;
 	cin>>n>>k;
 	vector<ll> v(n);
 	for(auto &c: v) {
 		cin>>c;
 	}   
 	multiset<ll> s(v.begin(), v.begin()+k);
 	vector<ll> ans;
 	auto it = next(s.begin(), (k-1)/2);
 	ans.push_back(*it);
 	for(int i=k; i<n; i++) {
 		s.insert(v[i]);
 		if(v[i]<*it) {
 			it--;
 		}
 		if(v[i-k]<=*it) {
 			it++;
 		}
 		s.erase(s.lower_bound(v[i-k]));
 		ans.push_back(*it);
 	}
 	for(auto c: ans) {
 		cout<<c<<" ";
 	}
 	cout<<endl;
    return 0;
}