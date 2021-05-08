#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll answer(string s){
    int n = s.length();
    char prev = 'a';
    ll maxC = 0 , count = 0;
    for(auto c: s){
        if(prev==c){
            count++;
        }else{
            count = 1;
            prev = c;
        }
        maxC = max(maxC , count);
    }
    return maxC;
}

int main(){
    string s;
    cin>>s;
    cout<<answer(s)<<endl;
    return 0;
}