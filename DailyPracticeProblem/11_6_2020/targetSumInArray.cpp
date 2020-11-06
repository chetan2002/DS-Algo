#include<bits/stdc++.h>
using namespace std;

bool wasMyNumberPresentMap(vector<int> number , int n , int k){
    unordered_map<int,int> mp;
    for(auto c: number){
        if(mp.find(k-c)!=mp.end()){
            return true;
        }else{
            mp.insert({c,1});
        }
    }
    return false;
}

bool wasMyNumberPresentTwoPointer(vector<int> number , int n , int k){
    sort(number.begin() , number.end());
    int i=0;int j=n-1;
    while(i<j){
        int val=number[i]+number[j];
        if(val==k){
            return true;
        }else
        if(val<k){
            i++;
        }else{
            j--;
        }
    }
    return false;
}

bool wasMyNumberPresentNaive(vector<int> number , int n , int k){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(number[i]+number[j]==k){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        v.push_back(val);

    }
    int k;
    cin>>k;
    if(wasMyNumberPresentNaive(v,n,k)){
        cout<<"Naive approach says numbers were present"<<endl;
    }else{
        cout<<"Naive approach says numbers weren't present"<<endl;
    }

    if(wasMyNumberPresentTwoPointer(v,n,k)){
        cout<<"Two Pointer approach says numbers were present"<<endl;
    }else{
        cout<<"Two Pointer approach says numbers weren't present"<<endl;
    }

    if(wasMyNumberPresentMap(v,n,k)){
        cout<<"Mapping approach says numbers were present"<<endl;
    }else{
        cout<<"Mapping approach says numbers weren't present"<<endl;
    }
    return 0;
}
