#include <bits/stdc++.h>
using namespace std;
 #define ll long long int 

bool recurring(ll numr, ll denr)
{
    string res; 
    map<ll, ll> mp;
    mp.clear();
    ll rem = numr % denr;
    while ((rem != 0)
           && (mp.find(rem) == mp.end()))
    {
        mp[rem] = res.length();
        rem = rem * 10;
        ll res_part = rem / denr;
        res += to_string(res_part);
        rem = rem % denr;
    }
 
    return (rem == 0) ? false: true;
}
 
// Driver code
int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n , k;
        cin>>n>>k;
        ll ans = n*(n+1)/2;
        cout<<ans<<" "; 
        bool res = recurring(k, ans);
        cout<<res<<endl;
        if(res){
            cout<<"-1"<<endl;
        }else{
            cout<<k/res<<endl;
        }
        
    }
    return 0;
}