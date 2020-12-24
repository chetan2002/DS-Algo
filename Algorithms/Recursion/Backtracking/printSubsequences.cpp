#include<bits/stdc++.h>
using namespace std;

void sub(string s , string a , int i , set<string> &se){
	if(i==s.length()){
		se.insert(a);
		return;
	}
  //leave the character
	sub(s,a,i+1 , se);
  
  //take the character
	char c = s[i];
	a+=c;
	sub(s,a,i+1 , se);
}


int main(){
	int t;
	cin>>t;
	while(t--){
		set<string> se;
		string s;
		cin>>s;
		sub(s ,"" , 0 , se);
		for(auto c: se){
			cout<<c<<endl;
		}
	}
	return 0;
}
