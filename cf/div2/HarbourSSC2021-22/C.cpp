#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void recursive(string s , int i , int fi , int se , int& mini){
	if(i==10){
		return ;
	}
	int sL = (10-i+1)/2;
	int fL = (10-i)/2;
	if(fi>sL+se){
		mini = min(mini , i);
		return;
	}
	if(se>fL+fi){
		mini = min(mini , i);
		return;
	}
	if(i%2==0){
		if(s[i]=='1'){
			fi++;
		}else
		if(s[i]=='?'){
			recursive(s,i+1,fi+1,se,mini);
		}
	}else{
		if(s[i]=='1'){
			se++;
		}else
		if(s[i]=='?'){
			recursive(s,i+1,fi,se+1,mini);
		}
	}
	recursive(s , i+1 , fi , se , mini);
	
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	string s;
    	cin>>s;

    	int mini=10;
    	recursive(s , 0 , 0 , 0 , mini);

    	cout<<mini<<endl;
    }
    return 0;
}