/*
We are given a circular array, print the next greater number for every element. If it is not found print -1 for that number. To find the next greater number for element Ai , start from index i + 1 and go uptil the last index after which we start looking for the greater number from the starting index of the array since array is circular.

Input Format
First line contains the length of the array n. Second line contains the n space separated integers.

Constraints
1 <= n <= 10^6
-10^8 <= Ai <= 10^8 , 0<= i< n

Output Format
Print n space separated integers each representing the next greater element.

Sample Input
3
1 2 3
Sample Output
2 3 -1
Explanation
Next greater element for 1 is 2,
for 2 is 3 but not present for 3 therefore -1

*/

//Solution: https://ide.codingblocks.com/s/371879

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin>>n;
    vector<ll> v;
    for(int i=0;i<n;i++){
        ll val;
        cin>>val;
        v.push_back(val);
    }
    stack<ll> s;
    s.push(v[0]);
    for(int i=n-1;i>=0;i--){
        ll c = v[i];
        while(!s.empty() and s.top()<=c){
            s.pop();
        }
        s.push(c);
    }
    vector<ll> ans(n,-1);
    for(int i=n-1;i>=0;i--){
        ll c = v[i];
        while(!s.empty() and s.top()<=c){
            s.pop();
        }
        if(!s.empty()){
            ans[i] = s.top();
        }else{
            ans[i] = -1;
        }
        s.push(c);
    }
    for(auto c: ans){
        cout<<c<<" ";
    }

    return 0;
}
