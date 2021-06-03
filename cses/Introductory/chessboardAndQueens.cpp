#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<string> v;

bool canPlace(int i , int j ){
	if(v[i][j]=='*'){
		return false;
	}
	for(int k=0;k<8;k++){
		if(v[k][j]=='Q'){
			return false;
		}
		if(v[i][k]=='Q'){
			return false;
		}
	}

	int x = i , y = j;
	while(x>=0 and y>=0){
		if(v[x][y]=='Q'){
			return false;
		}
		x-- , y--;
	}
	x= i , y = j;
	while(x>=0 and y<8){
		if(v[x][y]=='Q'){
			return false;
		}
		x-- , y++;
	}
	return true;
}
bool queen(int i , int &count){
	if(i==v.size()){
		count++;
		return false;
	}

	for(int j=0;j<v[i].length();j++){
		if(v[i][j]!='.'){
			continue;
		}
		if(canPlace(i , j )){
			v[i][j] = 'Q';
			bool place = queen(i+1 , count);
			if(place){
				return true;
			}
			v[i][j] = '.';
		}
	}
	return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<8;i++){
    	string s;
    	cin>>s;
    	v.push_back(s);
    }

    int count =0 ;
    queen(0 , count);
    cout<<count<<endl;
    return 0;
}