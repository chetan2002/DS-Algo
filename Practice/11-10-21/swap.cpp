#include<bits/stdc++.h>
using namespace std;
#define ll long long int

pair<int,int> swap(pair<int,int> p){
	swap(p.first, p.second);
	return p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	   
    pair<int,int> p;
    cin>>p.first>>p.second;
 	cout<<"Before swapping a = "<<p.first<<" "<<"b="<<p.second<<endl;
 	p = swap(p);
 	cout<<"After swapping a = "<<p.first<<" "<<"b="<<p.second<<endl;
    return 0;
}