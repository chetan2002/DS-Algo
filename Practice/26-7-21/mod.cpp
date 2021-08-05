#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	int n , k;
 	cin>>n>>k;
 	cout<<((n%k +k)%k)<<endl;   
 	cout<<(n%k + k)<<endl;
    return 0;
}