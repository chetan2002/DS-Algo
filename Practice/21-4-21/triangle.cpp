#include<bits/stdc++.h>
using namespace std;
int answer(vector<vector<int>> &tr , int i , int j){
    if(i<0 || j<0){
        return 0;
    }
    if(j>=tr.size()){
        cout<<"How is j greater"<<endl;
        return 0;
    }
    if(i>=tr[j].size()){
        cout<<"How is i greater"<<endl;
        return 0;
    }
    
    if(i==0 and j==0){
        return tr[j][i];
    }
    
    if(i==0){
        return tr[j][i] + answer(tr , i , j-1);
    }
    if(i==j){
        return tr[j][i] + answer(tr , i-1 , j-1);
    }
    return tr[j][i] + min(answer(tr , i-1 , j-1) , answer(tr , i , j-1));
}
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        mini = min(mini , answer(triangle , i , n-1));
    }
    return mini;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        vector<int> a;
        for(int j=0;j<=i;j++){
            int val;
            cin>>val;
            a.push_back(val);
        }
        v.push_back(a);
    }
    // for(auto c: v){
    //     for(auto a: c){
    //         cout<<a<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<minimumTotal(v)<<endl;
    return 0;
}