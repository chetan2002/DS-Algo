//https://hack.codingblocks.com/app/contests/2022/173/problem

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	unordered_map<int , int> mp;
	for(int i=0 ; i<n; i++){
		int val;
		cin>>val;
		mp[val]++;
	}
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr , arr+n);
	bool tog = false;
	cout<<"[";
	for(int i=0 ; i<n;i++){
		if(mp.find(arr[i])!=mp.end()){
			if(mp[arr[i]]<=0){
				continue;
			}else{
				if(!tog){
					tog = true;
					
				}else{
					cout<<", ";
				}
				mp[arr[i]]--;
				cout<<arr[i];
			}
		}
	}
	cout<<"]";
	return 0;
}