#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	ll n , m , p;
 	cin>>n>>m>>p;

 	string s;
 	vector<int> vm(m,0);
 	for(int i=0;i<n;i++){
 		cin>>s;
 		for(int j=0;j<m;j++){
 			if(s[j]=='1'){
 				vm[j]++;
 			}
 		}
 	}

 	s="";
 	int value = (n+1)/2;
 	int count = m/2;
 	for(auto c: vm){
		if(c>=value){
			if(count>0){
				s+='1';
				count--;
			}else{
				s+='0';
			}
		}else{
			s+='0';
		}
 	}
 	cout<<s<<endl;


    return 0;
}