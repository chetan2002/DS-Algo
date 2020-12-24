#include<iostream>
using namespace std;

string answer(string s){
	if(s.length()==0){
		return "";
	}
  
  //extract first character
	string a;
	a.push_back(s[0]);
  
  //recurr remaining string
	string ChotiString = answer(s.substr(1));
  
  //if character is x , append to last , else append to start
	if(a=="x"){
		a = ChotiString + a;
	}else{
		a=a + ChotiString;
	}
	return a;
}


int main(){
	string s;
	cin>>s;
	s = answer(s);
	cout<<s<<endl;
	return 0;
}
