#include<bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> v , int n){
    if(n==0){
        return true;
    }
    if(n==1){
        return true;
    }
    return (v[n-1]>=v[n-2])&&(isSorted(v , n-1));
}

int main(){
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        v.push_back(val);
    }
    if(isSorted(v , n)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}