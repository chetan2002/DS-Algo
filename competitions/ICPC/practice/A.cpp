#include<bits/stdc++.h>
using namespace std;
#define ll long long int


bool pos(int w , int l , int m , int x , int y){
	if(w<=m-y and w<=m-x){
		return true;
	}
	return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll w , l , m , x , y;
    	cin>>w>>l>>m>>x>>y;

    	if(pos(w,l,m,x,y)){
    		cout<<"JUMP"<<endl;
    	}else{
    		cout<<"FALL"<<endl;
    	}

    }
    return 0;
}