#include<bits/stdc++.h>
using namespace std;
#define ll long long int


void print(const vector<ll> &b){
	for(auto c: b){
		cout<<c<<" ";
	}
	cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n , k;cin>>n>>k;
 	vector<ll> v(n);
 	for(auto &i: v){
 		cin>>i;i--;
 	}

 	vector<ll> b(n);
 	for(int i=0;i<n;i++){
 		b[v[i]]=i;
 	}
 	ll count = 1;
 	for(int i=1;i<n;i++){
 		if(b[i]<b[i-1]){
 			count++;
 		}
 	}
 	// cout<<count<<endl;
 	set<pair<int,int>> s;
//wrong answer is due to the fact it is subtracting for both -1 and +1 value and on 2,3 it does same check twice and subtracts it
 	while(k--){
 		ll v1 , v2;
 		cin>>v1>>v2; 		
 		v1-- , v2--;
 		if(v[v1]!=0){
 			s.insert({v[v1]-1 , v[v1]});
 		}
 		if(v[v2]!=0){
 			s.insert({v[v2]-1 , v[v2]});
 		}
 		if(v[v1]!=n-1){
 			s.insert({v[v1] , v[v1]+1});
 		}
 		if(v[v2]!=n-1){
 			s.insert({v[v2] , v[v2]+1});
 		}

 		for(auto c: s){
 			if(b[c.first]>b[c.second]){
 				count--;
 			}
 		}
 		// print(v);
 		// print(b);
 		swap(b[v[v1]],b[v[v2]]);
 		swap(v[v1] , v[v2]);
		
		for(auto c: s){
 			if(b[c.first]>b[c.second]){
 				count++;
 			}
 		}
		s.clear();
		// print(v);
 		// print(b);
 		cout<<count<<endl;
 	}

    return 0;
}