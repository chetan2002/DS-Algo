#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n , m;
    	cin>>n>>m;
    	ll arr[n][m];
    	ll last = 0;
    	for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(last==0){
					arr[i][j] = 1;
					last = 1;
				}else{
					arr[i][j] = 0;
					last =0;
				}
			}
		}
    	if((n*m)%2==0){
    		bool done = false;
    		for(int i=0;i<n;i++){
    			for(int j=0;j<m;j++){
    				if(arr[i][j]==0){
	    				arr[i][j] = 1;
	    				done = true;
	    				break;
	    			}
    			}
    			if(done){
    				break;
    			}
    		}
    	}
    	for(int i=0;i<n;i++){
    		for(int j=0;j<m;j++){
    			int a = arr[i][j];
    			if(a==0){
    				cout<<"W";
    			}else{
    				cout<<"B";
    			}
    		}
    		cout<<endl;
    	}
    }
    return 0;
}