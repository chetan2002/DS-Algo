#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin>>n;
    string a , b;
    cin>>a>>b;
    ll count =0;
    for(int i=0;i<n/2;i++){
        unordered_map<char , int> mp;
        mp[a[i]]++;
        mp[b[i]]++;
        mp[a[n-1-i]]++;
        mp[b[n-1-i]]++;

        if(mp.size()==2){
            int value =0;
            for(auto c: mp){
                value += (c.second%2);
            }
            if(value==0){
                continue;
            }
            count++;
        }else
        if(mp.size()==3){
            if(a[i]==a[n-1-i]){
                count+=2;
                continue;
            }
            count++;
        }else
        if(mp.size()==4){
            count+=2;
        }
    }
    if(n%2==1){
        if(a[n/2]!=b[n/2]){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}