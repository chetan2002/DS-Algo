#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	double n;cin>>n;

 	double answer = 0;
 	while(n>0){
 		answer += (1/n);
 		n--;
 	}

 	cout<<answer<<endl;
    return 0;
}