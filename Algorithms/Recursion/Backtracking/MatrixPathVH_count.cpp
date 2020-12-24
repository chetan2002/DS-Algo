//https://hack.codingblocks.com/app/contests/2022/494/problem

#include<bits/stdc++.h>
using namespace std;

char sol[100];
void path(int m , int n , int i , int j ,int k, int& count){

	if(i==m and j==n){
		sol[k]='\0';
		cout<<sol<<" ";
		count++;
		return;
	}
	if(i>m || j>n){
		return;
	}

	sol[k]='V';
	path(m,n,i+1,j,k+1,count);


	sol[k]='H';
	path(m,n,i,j+1,k+1,count);

	return;

}

int main(){
	int m,n;
	cin>>m>>n;
	int count = 0;
	path(m , n , 1 , 1 , 0, count);
	cout<<endl<<count<<endl;
	return 0;
}
