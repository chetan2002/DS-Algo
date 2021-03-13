#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<string> v={"zero" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine" };
void toString(ll n){
    if(n==0){
        return;
    }
    int val = n%10;
    toString(n/10);
    cout<<v[val]<<" ";
}

int main(){
    ll n;
    cin>>n;
    toString(n);
    return 0;
}