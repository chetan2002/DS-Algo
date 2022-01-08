#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> pos;
vector<ll> v;

void reorder(int j, int i) {
    int k;
    if(j==i+1) {
        k = i+2;
    }else {
        k= i+1;
    }

    int temp = v[i]; 
    v[i] = v[j];  pos[v[i]] = i;
    v[j] = v[k];  pos[v[j]] = j;
    v[k] = temp;  pos[v[k]] = k;
}
bool check() {
    if(v.size()==1) {
        return true;
    }
    int n = v.size();
    
    pos.clear();
    pos.resize(n+1, -1);

    for(int i=0; i<n; i++) {
        if(pos[v[i]]!=-1) {
            return true;
        }
        pos[v[i]] = i;
    }
    for(int i=0; i<n; i++) {
        if(v[i]!=i+1) {
            if(i>=n-2) {
                return false;
            }
            reorder(pos[i+1], i);
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;cin>>n;
        v.resize(n);
    	for(auto &c: v) {
    		cin>>c;
    	}
    	
        if(check()) {
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}