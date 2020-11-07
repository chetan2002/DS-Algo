#include<bits/stdc++.h>
using namespace std;


//this is the best approach for this question - time complexity O(n) and space complexity O(n)
bool wasMyNumberPresentMap(vector<int> number , int n , int k){
    //for every value , check if (target-value) is present in the map ,
    // if yes return true
    //else insert the value in map in hope to find it's complement afterwards
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

//this is a good approach || time complexity O(n) and space complexity O(1)
bool wasMyNumberPresentTwoPointer(vector<int> number , int n , int k){
    //sort the list and then start moving pointers from both ends , 
    //if sum of the elements pointed by the pointers is equal to target then return true , 
    //if sum is greater then we need a smaller element so move the right pointer towards left 
    //else if our target sum is smaller then move left pointer right
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

//brute force , naive approach || time complexity O(n2) and space complexity O(1)
bool wasMyNumberPresentNaive(vector<int> number , int n , int k){
    //for each element , check all other elements if they hit the target 
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
    //input n- number of element in array 
    int n;
    cin>>n;
    vector<int> v;
    //input the array of n elements
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        v.push_back(val);

    }
    //input the target to search
    int k;
    cin>>k;

    //call for naive approach
    if(wasMyNumberPresentNaive(v,n,k)){
        cout<<"Naive approach says numbers were present"<<endl;
    }else{
        cout<<"Naive approach says numbers weren't present"<<endl;
    }

    //call for two pointer approach
    if(wasMyNumberPresentTwoPointer(v,n,k)){
        cout<<"Two Pointer approach says numbers were present"<<endl;
    }else{
        cout<<"Two Pointer approach says numbers weren't present"<<endl;
    }

    //call for map based solution
    if(wasMyNumberPresentMap(v,n,k)){
        cout<<"Mapping approach says numbers were present"<<endl;
    }else{
        cout<<"Mapping approach says numbers weren't present"<<endl;
    }
    return 0;
}
