#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll histogram(vector<ll> v , ll n){
	stack<ll> s;
	ll top ;
	ll maxAr = 0;
	ll areaTop = 0;
	ll i= 0;
	while(i<n){
		if(s.empty() || v[s.top()]<=v[i]){
			s.push(i);
			i++;
		}else{

			top = s.top();
			s.pop();

			if(s.empty()){
				areaTop = v[top]*i;
			}else{
				areaTop = v[top]*(i-s.top()-1);
			}
			maxAr = max(maxAr , areaTop);
		}
	}
	while(!s.empty()){
		top = s.top();
		s.pop();

		if(s.empty()){
			areaTop = v[top]*i;
		}else{
			areaTop = v[top]*(i-s.top()-1);
		}
		maxAr = max(maxAr , areaTop);
	}

	return maxAr;

}

int main(){
	ll n;
	cin>>n;
	vector<ll> v;
	for(ll i=0;i<n; i++){
		ll val ;
		cin>>val;
		v.push_back(val);
	}
	cout<<histogram(v , n)<<endl;
	return 0 ;
}