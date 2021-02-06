//https://hack.codingblocks.com/app/contests/2022/401/problem

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	priority_queue<ll> pq;
	ll q, k;
	cin>>q>>k;
	while(q--){
		ll val;
		cin>>val;
		if(val==1){
			ll x , y;
			cin>>x>>y;
			ll value = (x*x)+(y*y);
			if(pq.size()<k){
				pq.push(value);
			}else{
				if(pq.top()>value){
					pq.pop();
					pq.push(value);
				}
			}
		}else{
			cout<<pq.top()<<endl;
		}
	}
	return 0;
}