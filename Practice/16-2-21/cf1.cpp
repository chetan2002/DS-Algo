#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v;
        for(int i=0;i<n;i++){
            ll val;
            cin>>val;
            v.push_back(val);
        }
        vector<ll> a(10,0);

        for(int i=0;i<n;i++){
            a[(v[i]%3)]++;
        }
        int target = n/3;
        ll count = 0;
        if(a[0]==target and a[1]==target and a[2]==target){
            cout<<"0"<<endl;
            continue;
        }
        for(int i=0; i<5;i++){
            ll extra = 0;

            if(a[i]==target){
                continue;
            }
            if(a[i]<target){
                a[i+3] = a[i];
                a[i]= 0;
            }else{
                extra = a[i]-target;
                a[i] = target;
                a[i+1] +=extra;
                count+=extra;
            }
    
        }

        cout<<count<<endl;

    }

    return 0;
}