#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

void answer(ll n){
    ll total = (n*(n+1))/2;
    if(total%2!=0){
        cout<<"NO"<<endl;
        return;
    }
    total = total/2;
    set<ll> s1;
    set<ll> s2;
    ll sum1 = 0;
    for(int i=1;i<=n;i++){
        if(sum1==total){
            s2.insert(i);
        }else
        if(sum1+i>total){
            ll sumFake = sum1+i-total;
            s2.insert(sumFake);
            s1.erase(sumFake);
            s1.insert(i);
            sum1-=sumFake;
            sum1+=i;
        }else{
            sum1+=i;
            s1.insert(i);
        }
    }
    cout<<"YES"<<endl;
    cout<<s1.size()<<endl;
    for(auto c: s1){
        cout<<c<<" ";
    }
    cout<<endl<<s2.size()<<endl;
    for(auto c: s2){
        cout<<c<<" ";
    }
}    
int main(){
   ll n;
   cin>>n;
   answer(n);
   return 0;
}