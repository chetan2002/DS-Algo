#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m;
vector<string> v;
const ll MOD = 1e9+7;

ll answer() {
	ll ans = 1;
	for(int i=0; i<m; i++) {
		unordered_set<char> s;
		for(int j=0; j<n; j++) {
			s.insert(v[j][i]);
		}
		ans = ans*(ll)s.size();
		ans = ans%MOD;
	}
	return ans%MOD;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	cin>>n>>m;   
 	v.resize(n);
 	for(auto &c: v) {
 		cin>>c;
 	}
	cout<<answer()<<endl; 	
    return 0;
}