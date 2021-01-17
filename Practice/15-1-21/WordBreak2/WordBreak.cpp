//https://practice.geeksforgeeks.org/problems/word-break-part-2/0
/*
Example:
Input:
1
5
lr m lrm hcdar wk
hcdarlrm

Output:
(hcdar lr m)(hcdar lrm)

*/
#include <bits/stdc++.h>
using namespace std;

void wordBreak(string s , unordered_set<string> &mp , int i , string c , vector<string> v , bool &count){
    //base case
    if(i==s.length()){
        if(mp.find(c)!=mp.end()){
            count=true;
            v.push_back(c);
            cout<<"(";
            for(int j=0;j<v.size();j++){
                cout<<v[j];
                if(j!=v.size()-1){
                    cout<<" ";
                }
            }
            cout<<")";
        }
        return;
    }
    c+=s[i];
    bool found = false;
    if(mp.find(c)!=mp.end()){
        v.push_back(c);
        wordBreak(s , mp , i+1 , "" , v , count );
        v.pop_back();
    }
    
    wordBreak(s , mp , i+1 , c , v , count);
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    unordered_set<string> mp; 
	    for(int i=0;i<n;i++){
	        string s;
	        cin>>s;
	        mp.insert(s);
	    }
	    string s;
	    cin>>s;
	    bool count = false;
	    wordBreak(s , mp , 0 , "" , {} , count);
	    mp.clear();
	    if(count){
	        cout<<endl;
	    }else{
	        cout<<"Empty"<<endl;
	    }
	}
	return 0;
}