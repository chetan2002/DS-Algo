#include<bits/stdc++.h>
using namespace std;

//in this question we have to find the maximum value of the sum of non adjacent elements

//Time: O(n) , extra space : constant
//dynamic programming
long long int maximumNotAdjacentSum(int n , vector<long long int> v){
    if(n==1){
        return v[0];
    }
    if(n==2){
        return max(v[0],v[1]);
    }
    if(n==3){
        v[2] = max(v[2] , v[0]+v[2]);
        long long int max = v[0];
        for(auto c: v){
            if(max<c){
                max = c;
            }
        }
        return max;
    }else{
        v[2] = max(v[2] , v[0]+v[2]);
        for(int i=3;i<n;i++){
            v[i] = max(max(v[i], v[i]+v[i-2]) , v[i]+v[i-3]);
        }
        long long int max = v[0];
        for(auto c: v){
            if(max<c){
                max=c;
            }
        }
        return max;
    }
}

int main(){
    int n;
    cin>>n;
    vector<long long int> v;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        v.push_back(val);
    }
    cout<<maximumNotAdjacentSum(n , v)<<endl;

    return 0 ;
}
