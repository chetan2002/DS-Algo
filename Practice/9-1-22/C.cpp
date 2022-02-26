#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;
 	cin>>n;
 	ll ans = 12;
 	for(int i=5; i<=n; i++) {
 		ans = i*(23*(ans) + ans + ans/(i-2));
 		cout<<ans<<endl;
 	}   
 	cout<<ans%mod<<endl;
    return 0;
}