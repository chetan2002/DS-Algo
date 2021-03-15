#include<iostream>
using namespace std;

int elephantWays(int n , int m){
    if(n==0 and m==0){
        return 1;
    }
    if(n<0 or m<0){
        return 0;
    }
    int ans = 0;
    for(int i=0;i<m;i++){
        ans+=elephantWays(n,i);
    }
    for(int i=0;i<n;i++){
        ans+=elephantWays(i,m);
    }
    return ans;
    
}

int main(){
    int n;
    cin>>n;
    cout<<elephantWays(n , n)<<endl;
    return 0 ;
}