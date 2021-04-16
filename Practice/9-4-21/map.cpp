#include<bits/stdc++.h>
using namespace std;


bool comp(int a , int b){
    return a<b;
}

void print(vector<int> v){
    for(auto c: v){
        cout<<c<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> v = {1 ,2 , 13 ,4 ,5};
    sort(v.begin() , v.end() , comp);

    print(v);
    return 0 ;
}