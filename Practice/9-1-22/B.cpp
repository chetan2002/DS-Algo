#include<iostream>
#include<string>
using namespace std;

string answer(string s) {
	if(s.length()==0) {
		return 0;
	}
	string ans = "";
	for(int i=0; i<s.length(); i++) {
		string w = "";
		int arr[26] = {0};
		for(int j=i; j<s.length(); j++) {
			if(arr[s[j]-'a']!=0) {
				break;
			}
			w+=s[j];
			arr[s[j]-'a'] = 1;
		}
		if(w.length()>ans.length()) {
			ans = w;
		}
	}
	return ans;
}

int main() {
	string s;
	cin>>s;

	cout<<answer(s)<<endl;
	return 0;
}