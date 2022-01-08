#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;cin>>n;   
 	vector<vector<ll>> vp(n);
 	for(int i=0; i<n; i++){
        ll a, b;
 		cin>>a;
 		cin>>b;
        vp[i] = {a, b, i};
 	}
 	sort(vp.begin(),vp.end());
    unordered_set<ll> s;
    int value =0 ;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<int> v(n);
    for(auto c: vp) {
        while(!pq.empty() and pq.top().first<c[0]) {
            s.insert(pq.top().second);
            pq.pop();
        }
        if(s.size()==0) {
            s.insert(value+1);
            value++;
        }
        v[c[2]] = *s.begin();
        pq.push({c[1], *(s.begin())});
        s.erase(s.begin());
    }
    cout<<value<<endl;
    for(auto c: v) {
        cout<<c<<" ";
    }
    cout<<endl;
    return 0;
}