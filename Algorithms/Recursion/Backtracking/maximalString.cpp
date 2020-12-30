#include<bits/stdc++.h>
using namespace std;

string ans;
void maximalString(string s , int k , int i){
    //base case
    if(k==0 || i==s.length()){
        ans = max(ans , s);
        return;
    }


    //recursive
    for(int j=i+1;j<s.length();j++){
        swap(s[i],s[j]);
        maximalString(s,k-1,i+1);
        swap(s[i],s[j]);
    }
    maximalString(s,k,i+1);
}

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    ans = s;
    maximalString(s,k,0);
    cout<<ans<<endl;
    return 0;
}
