#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool ans(string A) {
    int n = A.size();
    for(int i=0;i<n-1;i++) {
        if(A[i] == A[i+1]) {
            return true;
        }
        if(i<n-2 and A[i]==A[i+2]){
            return true;
        }
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    cout<<ans(s)<<endl;
    return 0;
}