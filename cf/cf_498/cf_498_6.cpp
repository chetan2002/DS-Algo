#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n , m  , k , sum;
vector<vector<ll>> v;
unordered_map<ll,ll> mp[21][21];

void down(ll i=0 , ll j =0 , ll cur =0 ,ll step =0){
    cur^=v[i][j];
    if(step==(n+m-2)/2){
        mp[i][j][cur]++;
        return;
    }
    if(i+1<n) down(i+1 , j , cur , step+1);
    if(j+1<m) down(i , j+1 , cur ,step+1);
}
void up(ll i=n-1 , ll j=m-1 , ll cur =0 , ll step=0){
    if(step==n+m-2 - (n+m-2)/2){
        sum+= mp[i][j][cur^k];
        return;
    }
    cur^=v[i][j];
    if(i-1>=0) up(i-1 , j , cur , step+1);
    if(j-1>=0) up(i , j-1 , cur , step+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    v.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ll val;
            cin>>val;
            v[i].push_back(val);
        }
    }

    sum =0 ;
    down();
    up();
    cout<<sum<<endl;
    return 0;
}