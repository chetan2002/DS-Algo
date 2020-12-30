#include<bits/stdc++.h>
using namespace std;


// no. of ways to pair up when n people can either go alone or go in pair with someone else

int noOfWays( int n ){
    if( n==1 || n==2 ){
        return n;
    }

    int ans = 0 ;

    ans += noOfWays(n-1);

    ans += (n-1)*noOfWays(n-2);

    return ans ;
}

int main(){
    int n;
    cin>>n;

    cout << noOfWays(n) << endl;
    return 0;
}
