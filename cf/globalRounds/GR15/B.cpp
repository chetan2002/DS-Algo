#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int answer(vector<vector<int>> &v , int i , int j){
	int count = 0;
	for(int k=0;k<5;k++){
		if(v[k][i]<v[k][j]){
			count++;
		}
	}
	if(count>=3){
		return i;
	}
	return j;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	ll n;cin>>n;
    	vector<vector<int>> v(5,vector<int>(n,0));
    	for(int i=0;i<n;i++){
    		for(int j=0;j<5;j++){
    			cin>>v[j][i];
    		}
    	}
    	int prev= 0;
    	for(int i=1;i<n;i++){
    		int check = answer(v , i , prev);
    		if(check==i){
    			prev = i;
    		}
    	}


    	for(int i=0;i<n;i++){
    		if(i==prev){
    			continue;
    		}
    		int check = answer(v , i , prev);
    		if(check!=prev){
    			prev = -2;
    			break;
    		}
    	}

    	cout<<prev+1<<endl;
    }
    return 0;
}