//https://practice.geeksforgeeks.org/problems/union-of-two-arrays/0
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n , m;
        cin>>n>>m;
        int arr1[n] , arr2[m];
        for(int i=0;i<n;i++){
            cin>>arr1[i];
        }
        for(int j=0;j<m;j++){
            cin>>arr2[j];
        }
        
        unordered_set<int> first;
        for(int i=0;i<n;i++){
            first.insert(arr1[i]);
        }
        
        for(int j=0;j<m;j++){
            first.insert(arr2[j]);
        }
        cout<<first.size()<<endl;
        
    }
    return 0 ;
}