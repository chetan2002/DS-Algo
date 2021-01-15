//Rat in a maze print all solutions
//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> findPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
int solution[MAX][MAX]={0};
bool findWay(int m[][MAX] , int n , int i , int j , vector<string> &v , string s){
    if(i==n-1 and j==n-1){
        solution[i][j]=2;

        v.push_back(s);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<solution[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<m[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        
        solution[i][j]=0;
        return false;
    }
    
    
    
    if(i>=n || j>=n){
        return false;
    }
    if(i<0 || j<0){
        return false;
    }
    if(m[i][j]==0 || solution[i][j]==2){
        return false;
    }
    
    
    solution[i][j] = 2;
    
    
    
    bool down = false;
    if(i<=n-2 and solution[i+1][j]!=2 and m[i+1][j]!=0){
       down= findWay(m , n , i+1 , j , v , s+"D");
    }
    bool left=false;
    if(j>0 and solution[i][j-1]!=2 and m[i][j-1]!=0){
       left = findWay(m , n , i , j-1 , v , s+"L");
    }
    bool right = false;
    if(j<=n-2 and solution[i][j+1]!=2 and m[i][j+1]!=0){
        right = findWay(m , n , i , j+1 , v , s+"R");    
    }
    bool up=false;
    if(i>0 and solution[i-1][j]!=2 and m[i-1][j]!=0){
        up = findWay(m , n , i-1 , j , v , s+"U");
    }

    
    
    
    solution[i][j]=0;
    
    if(down || right || left || up){
        return true;
    }
    
    return false;
}
vector<string> findPath(int m[MAX][MAX], int n) {
    // Your code goes here
    vector<string> v;
    findWay(m , n , 0 , 0 , v , "");
    return v;
}
