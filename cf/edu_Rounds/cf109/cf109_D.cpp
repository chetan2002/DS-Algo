#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	ll n;
 	cin>>n;
 	vector<int> v(n);
 	for(int i=0;i<n;i++){
 		cin>>v[i];
 	}   
 	ll sum = 0;
 	for(int i=0;i<n;i++){
 		if(v[i]==1){
 			ll left =-1;
 			for(int j=i;j>=0;j--){
 				if(v[j]==0){
 					left = j;
 					break;
 				}
 			}
 			ll right = -1;
 			for(int j=i;j<n;j++){
 				if(v[j]==0){
 					right = j;
 					break;
 				}
 			}
 			if(left!=-1 and right!=-1){
 				ll absL = abs(left-i);
 				ll absR = abs(right - i);
 				if(absL<=absR){
 					v[left] = 2;
 					sum+=absL;
 				}else{
 					v[right] = 2;
 					sum += absR;
 				}
 			}else
 			if(left!=-1){
 				v[left] = 2;
 				sum+=abs(left-i);
 			}else{
 				v[right] = 2;
 				sum+= abs(right-i);
 			}
 		}
 	}
 	cout<<sum<<endl;
    return 0;
}