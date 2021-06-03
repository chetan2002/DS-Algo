#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	vector<string> v;

    	for(int i=0;i<9;i++){
    		string s;
    		cin>>s;
    		v.push_back(s);
    	}

    	v[0][0] = v[0][1];
    	v[1][3] = v[1][4];
    	v[2][6] = v[2][7];

    	v[3][1] = v[3][2];
    	v[4][4] = v[4][5];
    	v[5][7] = v[5][8];

    	v[6][2] = v[6][0];
    	v[7][5] = v[7][3];
    	v[8][8] = v[8][6];

    	for(auto c: v){
    		cout<<c<<endl;
    	}

    }
    return 0;
}