#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
		ll a, b;
		cin>>a>>b;
		int i=0;
		while(a!=b) {
			if(i==10) {
				break;
			}
		    string binary = std::bitset<20>(a).to_string();
		    binary+="1";
		    reverse(binary.begin(), binary.end());
		    ll decimal = std::bitset<20>(binary).to_ullong();
		    cout<<decimal<<" "<<endl;
		    a = decimal;
		    if(a>b) {
		    	break;
		    }
		    i++;
		}
		if(a==b) {
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
    
    return 0;
}