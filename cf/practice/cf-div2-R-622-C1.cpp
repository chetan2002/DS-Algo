#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll n;
    cin>>n;
    vector<ll> v(n);
    for(auto &c: v) {
        cin>>c;
    }
    ll maxi = 0;
    vector<ll> ans(n);
    for(int i=0; i<n; i++) {
        ll left = 0;
        ll leftMin = v[i];
        vector<ll> ans2(n);
        for(int j=i-1; j>=0; j--) {
            leftMin = min(leftMin, v[j]);
            left+=leftMin;
            ans2[j] = leftMin;
        }
        ll right = 0;
        ll rightMin = v[i];
        for(int j=i+1; j<n; j++) {
            rightMin = min(rightMin, v[j]);
            right += rightMin;
            ans2[j] = rightMin;
        }
        ans2[i]= v[i];
        if(left + right + v[i] > maxi) {
            ans = ans2;
            maxi = left+right+v[i];
        }
    }
    for(auto c: ans) {
        cout<<c<<" ";
    }
    cout<<endl;

    return 0;
}