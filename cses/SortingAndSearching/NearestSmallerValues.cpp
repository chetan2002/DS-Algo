#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;cin>>n;
 	vector<ll> v(n);
 	for(auto &c: v) {
 		cin>>c;
 	}
 	stack<ll> s;
 	for(int i=0; i<n; i++) {
		while(!s.empty() and v[s.top()-1]>=v[i]) {
			s.pop();
		}
 		
 		if(s.empty()) {
 			cout<<"0"<<" ";
 		}else {
 			cout<<s.top()<<" ";
 		}
		s.push(i+1);
 	}

    return 0;
}