#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m;
vector<string> grid;
string ans = "";
vector<int> pos = {-1, 0, 1, 0, -1};



bool isValid(int x, int y) {
    if(x<0 or x>=n or y<0 or y>=m) {
        return false;
    }
    if(grid[x][y]=='#') {
        return false;
    }
    if(grid[x][y]>='0' and grid[x][y]<='9') {
        return false;
    }
    return true;
}
char dir(int a) {
    vector<char> v = {'U', 'R', 'D', 'L'};
    return v[a-1];
}

void backtrack(int x, int y) {
    ans = "";
    while(grid[x][y]!='0') {
        int val = grid[x][y]-'0';
        ans+=dir(val);
        x-=pos[val-1];
        y-=pos[val];
    }
    reverse(ans.begin(), ans.end());
}
bool answer() {
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 'A') {
                grid[i][j] = '0';
                q.push({i,j});
            }
        }
    }
    while(!q.empty()) {
        auto o = q.front();
        q.pop();
        for(int i=1; i<5; i++) {
            int x = o.first+pos[i-1], y = o.second+pos[i];
            if(isValid(x, y)) {
                q.push({x,y});
                if(grid[x][y] == 'B') {
                    grid[x][y] = '0'+i;
                    backtrack(x, y);
                    return true;
                }
                grid[x][y] = '0'+i;
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
    for(auto &c: grid) {
        cin>>c;
    }
    if(answer()) {
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }else {
        cout<<"NO"<<endl;
    }
    return 0;
}