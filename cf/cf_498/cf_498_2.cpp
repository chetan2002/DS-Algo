#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n , k;
    cin>>n>>k;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<ll> a = v;
    sort(a.begin() , a.end(),greater<int>());
    multiset<ll> s;
    for(int i=0;i<k;i++){
        s.insert(a[i]);
    }
    ll sum = 0;
    for(int i=0;i<k;i++){
        sum+=a[i];
    }
    cout<<sum<<endl;
    int prev = 0;
    for(int i=0;i<k;i++){
        int j=prev;
        for(;j<n;j++){
            if(s.find(v[j])!=s.end()){
                break;
            }
        }
        if(s.size()==1){
            cout<<n-prev<<" ";
            break;
        }
        s.erase(s.find(v[j]));
        cout<<j-prev+1<<" ";
        prev = j+1;

    }
    return 0;
}