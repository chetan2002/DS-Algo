//https://hack.codingblocks.com/app/contests/2022/437/problem
#include<bits/stdc++.h>
using namespace std;

void lcs(string s1 , string s2){
	int n=s1.size();
	int m = s2.size();
	int arr[n+1][m+1]={0};
    for(int i=0;i<=n;i++){
        arr[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        arr[0][j]=0;
    }
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				arr[i][j] = 1+arr[i-1][j-1];
			}else{
				arr[i][j]=max(arr[i-1][j] , arr[i][j-1]);
			}
		}
	}
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
	// cout<<arr[n][m]<<endl;

    string s="";
    int i=n , j=m;
    while(i>0 and j>0){
        if(arr[i][j]==arr[i-1][j-1]+1 and s1[i-1]==s2[j-1]){
            s+=s1[i-1];
            i--;j--;
        }else{
            if(arr[i][j-1]==arr[i][j]){
                j--;
            }else{
                i--;
            }
        }
    }
    reverse(s.begin() , s.end());
    cout<<s<<endl;
}

int main(){
	string s1 , s2;
	cin>>s1>>s2;

	lcs(s1 , s2);

	return 0;
}