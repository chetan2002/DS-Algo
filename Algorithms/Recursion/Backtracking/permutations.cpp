#include<bits/stdc++.h>
using namespace std;

void permutate(char *arr , int i){
	if(arr[i]=='\0'){
		cout<<arr<<" ";
		return;
	}

	//make permutations keeping each character at first pos 
	for(int j=i;arr[j]!='\0';j++){
		swap(arr[i],arr[j]);
		permutate(arr , i+1);

		//backtrack otherwise won;t work for all values 
		swap(arr[i] , arr[j]);
	}
}

int main(){
	char arr[10];
	cin>>arr;
	permutate(arr , 0);
	return 0;
}
