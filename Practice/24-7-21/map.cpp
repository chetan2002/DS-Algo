#include<bits/stdc++.h>
using namespace std;
#define ll long long int


void print(vector<ll> v){
	for(auto c: v){
		cout<<c<<" ";
	}
	cout<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	//pair <val1 , val2> ->   val1 = p.first , val2  = p.second
 	int n;cin>>n;
 	int a[n];
 	for(auto &i: a){
 		cin>>i;
 	}
 	int m;cin>>m;
 	vector<ll> b(m);
 	for(auto &i: b){
 		cin>>i;
 	}
 	vector<ll> unio;
 	vector<ll> inter;
 	unordered_map<ll,ll> mp;
 	for(auto c: a){
 		mp[c]++;
 	}

 	for(auto c: b){
 		if(mp[c]!=0){
 			inter.push_back(c);
 			mp[c]--;
 		}
		unio.push_back(c);
 	}

 	for(auto c: mp){
 		while(c.second!=0){
 			unio.push_back(c.first);
 			c.second--;
 		}
 	}
 	cout<<"union"<<endl;
 	print(unio);
 	cout<<"Intersection"<<endl;
 	print(inter);
    return 0;
}