#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    string s;
    cin>>s;

    vector<int> vS(26,0);
    vector<int> vC(26 , 0);
    for(int i=0;i<s.length() ; i++){
        char c = s[i];
        if(c>='A' and c<='Z'){
            vC[c-'A']++;
        }else{
            vS[c-'a']++;
        }
    }

    int count = 0;
    for(int i=0;i<26;i++){
        if(vS==1){
            count++;
        }
        if(vC==1){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}