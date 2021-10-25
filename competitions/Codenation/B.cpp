#include<bits/stdc++.h>
using namespace std;
#define ll long long int


ll ans(ll A, ll B) {
    if(A==0 and B==0) {
        return 2;
    }
    if(A==0 || B==0) {
        return 2;
    }
    int count = 0;
    int val1 = log2(A)+1, val2 = log2(B)+1;
    return min(min(val1, val2) + 2, val1+val2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll a , b;
 	cin>>a>>b;   
 	cout<<ans(a,b)<<endl;
    return 0;
}