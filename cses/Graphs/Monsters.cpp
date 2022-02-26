#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll n, m;
vector<string> grid;
string ans = "";

bool isBorder(int x, int y) {
	if(x==0 or y==0 or x==n-1 or y==m-1) {
		return true;
	}
	return false;
}

bool isValidPos(int x, int y) {
	if(x<0 or y<0 or x>=n or y>=m) {
		return false;
	}
	return true;
}
bool isValidForMe(int x, int y) {
	if(!isValidPos(x, y)) {
		return false;
	}
	if(grid[x][y]!='.') {
		return false;
	}
	return true;
}

bool isValidForMonster(int x, int y) {
	if(!isValidPos(x, y)) {
		return false;
	}
	if(grid[x][y]!='.' and grid[x][y]!='A') {
		return false;
	}
	return true;
}

string convert(int i, int j) {
	if(i==0) {
		if(j==1) {
			return "R";
		}else {
			return "L";
		}
	}else {
		if(i==1) {
			return "D";
		}else{
			return "U";
		}
	}
}
class obj {
public:
	int x, y;
	bool isMonster;
	string movement;
	obj() {
		x = 0, y =0, isMonster = true, movement = "";
	}
	obj(int i, int j, bool M, string mov) {
		x = i, y = j, isMonster = M, movement = mov;
	}
};
bool possible() {
	queue<obj*> q;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(grid[i][j] == 'M') {
				q.push(new obj(i, j, true, ""));
			}
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(grid[i][j] == 'A') {
				q.push(new obj(i, j, false, ""));
			}
		}
	}
	vector<int> pos = {-1, 0, 1, 0, -1};
	while(!q.empty()) {
		obj* o = q.front();
		q.pop();
		if(!o->isMonster) {
			if(isBorder(o->x, o->y)) {
				ans = o->movement;
				return true;
			}
		}
		for(int i=1; i<5; i++) {
			if(o->isMonster) {
				int x = o->x + pos[i-1];
				int y = o->y + pos[i];
				if(isValidForMonster(x, y)) {
					grid[x][y] = 'M';
					q.push(new obj(x, y, true, ""));
				}
			}else {
				int x = o->x + pos[i-1];
				int y = o->y + pos[i];
				if(isValidForMe(x, y)) {
					grid[x][y] = 'A';
					q.push(new obj(x, y, false, o->movement+convert(pos[i-1], pos[i])));
				}
			}
		}
	}

	return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	cin>>n>>m;
 	grid.resize(n);
 	for(int i=0; i<n; i++) {
 		cin>>grid[i];
 	}
 	if(possible()) {
 		cout<<"YES"<<endl;
 		cout<<ans.length()<<endl;
 		cout<<ans<<endl;
 	}else{
 		cout<<"NO"<<endl;
 	}
    return 0;
}