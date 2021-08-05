#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int FindCount(int n ){
	int count = 0;
	for(int i=0;i<=n;i++){
		string s = to_string(i);
		for(auto c: s){
			if(c=='3'){
				count++;
			}
		}
	}
	return count;
}

int main(){
 	int n;
 	cin>>n;   
 	cout<<FindCount(n)<<endl;
    return 0;
}