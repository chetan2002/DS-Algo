#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n, k;
 	cin>>n>>k;
 	vector<pair<ll,ll>> v(n);
 	for(int i=0; i<n; i++) {
 		cin>>v[i].first;
 		v[i].second = i; 
 	}
 	sort(v.begin(), v.end());
 	bool found = false;
 	for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int s = j+1, e = n-1;
            while(s<e) {
                ll sum = v[i].first + v[s].first + v[e].first + v[j].first;
                if(sum==k) {
                    cout<<v[i].second+1<<" "<<v[s].second+1<<" "<<v[e].second+1<<" "<<1 + v[j].second<<endl;
                    found = true;
                    break;
                }else
                if(sum<k) {
                    s++;
                }else {
                    e--;
                }
            }
            if(found) {
                break;
            }
        }
        if(found) {
            break;
        }
 	}
 	if(!found) {
 		cout<<"IMPOSSIBLE"<<endl;
 	}
    return 0;
}