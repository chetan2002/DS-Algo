#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    string s , t;
    cin>>s>>t;
    ll ans = 0;
    int i=s.length()-1 , j = t.length()-1;
    while(i>=0 and j>=0 and s[i]==t[j]){
        i--;j--;
    }
    cout<<i+2+j<<endl;
    return 0;
}