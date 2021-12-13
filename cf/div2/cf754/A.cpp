#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	int a, b, c; cin>>a>>b>>c;
    	int value1 = b-a;
    	int value2 = c-b;

        int value = abs(value1-value2);
        if(value%3==0) {
            cout<<0<<endl;
        }else{
            cout<<1<<endl;
        }
    }
    return 0;
}


// 5, -1 => 4, 1 => 3, 3
// 0, 4 => 

// a-- => b++ => diff+=3
// a++ => b-- => diff-=3