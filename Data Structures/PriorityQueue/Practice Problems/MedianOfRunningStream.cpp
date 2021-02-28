//https://hack.codingblocks.com/app/contests/2022/1351/problem
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void findMed(ll *arr , ll n){
    //max heap
    priority_queue<double> small;
    //min heap
    priority_queue<double , vector<double> , greater<double>> big;

    double median = arr[0];
    small.push(arr[0]);
    cout<<arr[0]<<" ";

    for(int i=1;i<n;i++){
        int x = arr[i];
        if(small.size()>big.size()){
            if(x>median){
                big.push(x);
            }else{
                big.push(small.top());
                small.pop();
                small.push(x);
            }
            median = (small.top()+big.top())/2;
        }else
        if(small.size()==big.size()){
            if(x>median){
                big.push(x);
                median = big.top();
            }else{
                small.push(x);
                median = small.top();
            }
        }else{
            if(x>median){
                big.push(x);
                small.push(big.top());
                big.pop();
            }else{
                small.push(x);
            }
            median = (small.top()+big.top())/2;
        }
        cout<<median<<" ";
    }

}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        findMed(arr , n);
        cout<<endl;
    }
    return 0;
}