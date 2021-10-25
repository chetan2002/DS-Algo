#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int fun(int a) {
	a+=10;
	cout<<"hello"<<endl;
	return a;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a = 5;
    fun(a);
    cout<<a<<endl;

    return 0;
}