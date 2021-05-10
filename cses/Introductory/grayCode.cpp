#include<bits/stdc++.h>
using namespace std;
#define ll long long

// void answer(ll n , vector<string> &v ){
//     if(n==0){
//         return ;
//     }
//     v.push_back("0");
//     v.push_back("1");
//     for(ll i=2; i< (1<<n) ;i = i<<1){
//         //push elements in v in reverse order
//         for(int j=i-1;j>=0;j--){
//             v.push_back(v[j]);
//         }

//         //append 0 before elements in first half
//         for(int j=0;j<i;j++){
//             v[j] = "0" + v[j];
//         }
//         //append 1 before elements in remaining
//         for(int j=i;j<2*i;j++){
//             v[j] = "1" + v[j];
//         }
//     }
// }

void call(ll n , vector<string> &v){
    if(n==0){
        return;
    }
    if(v.size()==0){
        v.push_back("0");
        v.push_back("1");
        call(n-1 , v);
        return;
    }
    int a = v.size();
    for(int i=a-1;i>=0;i--){
        v.push_back(v[i]);
    }
    for(int i=0;i<a;i++){
        v[i] = "0" + v[i];
    }
    for(int i=a;i<v.size();i++){
        v[i] = "1" + v[i];
    }
    call(n-1 , v);
}

int main(){
    ll n;
    cin>>n;
    vector<string> v;
    // answer(n , v);
    call(n , v);
    for(auto c: v){
        cout<<c<<endl;
    }   
    return 0;
}


