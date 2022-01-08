#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MOD=1e9+7;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n; cin>>n;   
 	ll sum =0;
 	list<ll> l;
 	l.push_back(1);
 	for(int i=1; i<=n; i++) {
 		if(i>6) {
 			sum-=l.front();
 			l.pop_front();
 		}
 		sum+=MOD + l.back();
 		sum%=MOD;
 		l.push_back(sum);
 	}
 	cout<<l.back()<<endl;
    return 0;
}