#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<int>> v;
ll n;
string s;

bool f(){
	vector<int> w;
	unordered_set<int> d;
	for(int i=0;i<n;i++){
		char c= s[i];
		if(c=='2'){
			w.push_back(i);
		}else
		if(c=='1'){
			d.insert(i);
		}
	}
	if(w.size()<3 and w.size()>0){
		return false;
	}

	for(int i=0;i<n;i++){
		bool winning = false;
		for(int j=i;j<n;j++){
			if(i==j){
				v[i][j] = 4;
			}else{
				if(d.find(i)!=d.end()){
					v[i][j] = 3;
					v[j][i] = 3;
				}else
				if(d.find(j)!=d.end()){
					v[i][j] = 3;
					v[j][i] = 3;
				}else{
					if(winning){
						v[i][j] = 2;
						v[j][i] = 1;
					}else{
						v[i][j] = 1;
						v[j][i] = 2;
						winning =true;
					}
				}
			}
		}
	}
	return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	cin>>n;
    	cin>>s;
		v.clear();
		v.resize(n, vector<int>(n));
		bool pos = f();
		if(!pos){
			cout<<"NO"<<endl;
			continue;
		}else{
			cout<<"YES"<<endl;
		}
		for(auto c: v){
			for(auto a: c){
				if(a==1){
					cout<<"+";
				}else
				if(a==2){
					cout<<"-";
				}else
				if(a==3){
					cout<<"=";
				}else{
					cout<<"X";
				}
			}
			cout<<endl;
		}
    }
    return 0;
}