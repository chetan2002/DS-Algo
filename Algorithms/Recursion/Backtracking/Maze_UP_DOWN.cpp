#include<bits/stdc++.h>
using namespace std;

int sol[1002][1002]={0};
bool ratInMaze(char arr[][1002] , int r , int c , int i , int j){
	if(i==r-1 and j==c-1){
		sol[i][j]=1;
		for(int k=0;k<r;k++){
			for(int l=0;l<c;l++){
				cout<<sol[k][l]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	if(i>r-1 || j>c-1){
		return false;
	}

	sol[i][j] =1;
	if(j<c and arr[i][j]!='X'){
		bool path = ratInMaze(arr , r , c , i , j+1 );
		if(path){
			return true;
		}
	}
	if(i<r and arr[i][j]!='X'){
		bool path = ratInMaze(arr , r , c , i+1 , j );
		if(path){
			return true;
		}
	}

	sol[i][j] = 0;
	return false;
	
}

int main(){
	int r , c;
	cin>>r>>c;
	char arr[1002][1002];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>arr[i][j];
		}
	}
	bool ans = ratInMaze(arr , r , c , 0 ,0 );
	if(!ans){
		cout<<"-1"<<endl;
	}
	return 0;
}
