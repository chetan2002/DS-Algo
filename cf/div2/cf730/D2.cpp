#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int knxor(int x , int y , int k){
	int z= 0 , p = 1;
	while(x>0 or y>0){
		int a = x%k;
		x = x/k;
		int b = y%k;
		y = y/k;
		int c = (a-b+k)%k;
		z = z+p*c;
		p = p*k;
	}
	return z;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll t;
 	cin>>t;
 	while(t--){
 		ll n , k;
 		cin>>n>>k;

 		for(int i=0;i<n;i++){
 			if(i==0){
 				cout<<0<<endl;
 			}else
 			if(i%2==0){
 				cout<<knxor(i,i-1,k)<<endl;
 			}else{
 				cout<<knxor(i-1 , i , k)<<endl;
 			}

 			int val;cin>>val;
 			if(val==1){
 				break;
 			}
 		}
 	}   

    return 0;
}