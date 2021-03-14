#include<bits/stdc++.h>
using namespace std;
#define ll long long 

double power(ll n , ll k){
    if(k==0){
        return 1;
    }
    return power(n , k-1)*n;
}

double powerFast(ll n , ll k){
    if(k==0){
        return 1;
    }
   
    double a = powerFast(n , k/2);
    double ans = 1;
    if(k%2==0){
        ans = a*a;
    }else{
        if(k>0){
            ans = a*a*n;
        }else{
            ans = (a*a)/n;
        }
    }
    return ans;
}
int main(){
    ll n , k;
    cin>>n>>k;

    // cout<<power(n , k)<<endl;
    cout<<powerFast(n , k)<<endl;
    return 0;
}