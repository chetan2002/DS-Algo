#include<bits/stdc++.h>
using namespace std;
#define ll long long int
unordered_set<string> s;
vector<string> buffer;

void generate(string a, ll i, ll n, ll &count) {
	if(count == 10000000) {
		return;
	}
	if(i==n) {
		s.insert(a);
		count++;
		return;
	}
	for(auto c: buffer[i]) {
		generate(a+c, i+1, n, count);
	}
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;cin>>n;
 	vector<vector<ll>> v(n);
 	for(ll i=0;i<n;i++) {
 		string a="";
 		ll k;cin>>k;
 		while(k--) {
 			a += to_string(k+1);
 			ll val;
 			cin>>val;
 			v[i].push_back(val);
 		}
 		buffer.push_back(a);
 	}
 	ll count = 0;
 	generate("", 0, n, count);
 	for(auto c: s) {
 		cout<<c<<endl;
 	}
 	ll m;cin>>m;
 	while(m--) {
 		string a="";
 		for(ll i=0;i<n;i++) {
 			string c;
 			cin>>c;
 			a+=c;
 		}
 		s.erase(a);
 	}

 	ll maxi =0;
 	string maxS = "";
 	for(auto c: s) {
 		ll value = 0;
 		for(ll i=0;i<n;i++) {
 			value += v[i][c[i]-'1'];
 		}
 		if(value>maxi) {
 			maxS = c;
 			maxi = value;
 		}
 	}
 	for(auto c: maxS) {
 		cout<<c<<" ";
 	}
    return 0;
}