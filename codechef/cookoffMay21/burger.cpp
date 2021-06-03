#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x , y;
        cin>>x>>y;
        ll value = x;
        ll sum = value;
        vector<ll> v;
        v.push_back(value);
        for(int i=0;sum<=y;i++){
            value = value<<1;
            sum+=value;
            v.push_back(sum);
        }
        // for(auto c: v){
        //     cout<<c<<" ";
        // }
        // cout<<endl;
        ll ans = -1;
        sum = 0;
        bool onePass = false;
        bool twoPass = false;
        for(int i=0;i<v.size();i++){
            if(v[i]==y){
                ans = i+1;
                onePass=true;
                break;
            }
            if(v[i]>y){
                break;
            }
            sum = v[i];
            ans = i+1;
        }
        if(!onePass){
            int j=ans;
            while(j>=0){
                if(v[j]+sum == y){
                    sum+=v[j];
                    ans = ans + j+2;
                    twoPass=true;
                    break;
                }
                if(v[j]+sum<y){
                    sum+=v[j];
                    ans = ans + j+2;
                }
                j--;
            }
        }

        if(onePass || twoPass){
            cout<<ans<<endl;
        }else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}