#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,d;
vector<ll> v;

ll answer(){
	ll sum = 0;
	for(auto c: v){
		sum+=c;
		if(c>d){
			return -1;
		}
	}
	if(sum>=0){
		return 0;
	}

	sum = 0;
	stack<ll> s;
	for(auto c: v){
		
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>d;
    v.resize(n);
    for(int i=0;i<n;i++){
    	cin>>v[i];
    }

    cout<<answer()<<endl;
    return 0;
}