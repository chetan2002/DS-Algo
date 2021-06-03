#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll n;cin>>n;

 	priority_queue<int> pq;

 	int value = n;
 	for(int i=0;i<n;i++){
 		int val;
 		cin>>val;

 		pq.push(val);
 		while(!pq.empty()){
 			int dig = pq.top();
 			if(dig<value){
 				break;
 			}
            pq.pop();
 			cout<<dig<<" ";
 			value --;
 		}

 		cout<<endl;

 	}
    return 0;
}