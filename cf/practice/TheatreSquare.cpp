#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll a , b , c;
 	cin>>a>>b>>c;

 	ll ans = ceil(a/(1.0*c)) * ceil(b/(1.0*c));
 	cout<<ans<<endl;
    return 0;
}