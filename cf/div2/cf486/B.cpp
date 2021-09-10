#include<bits/stdc++.h>
using namespace std;
#define ll long long int


bool cmp(string a , string b){
    return a.size()<b.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++){
    	cin>>v[i];
    }

   	sort(v.begin(),v.end(),cmp);
   	bool f = true;
   	for(int i=1;i<n;i++){
   		string a= v[i-1];
   		string b = v[i];
        if(a==b){
            continue;
        }
   		if(b.find(a)!=string::npos){
   		}else{
   			f = false;
   			break;
   		}
   	}
   	if(f){
   		cout<<"YES"<<endl;
   		for(auto c: v){
   			cout<<c<<endl;
   		}
   	}else{
   		cout<<"NO"<<endl;
        
   	}
    return 0;
}