#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int reverse(int n){
	int value = 0;
	while(n>0){
		value = (value*10)+n%10;
		n/=10;
	}
	return value;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	int x ;
 	cin>>x;
	int pro = 1;

	reverse(x);
 	if(x<0){
		x*=-1;
		pro++;
	}
	int sum = 0;
	while(x>0){
		int val = x%10;
		cout<<sum<<" + "<<val<<" * "<<pro<<" = ";
		sum += val*pro;
		cout<<sum<<endl;
		pro++;
		x = x/10;
	}
	cout<<sum<<endl;
    return 0;
}