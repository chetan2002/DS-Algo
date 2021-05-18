#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(string a , string b){
	int n = a.length();
	int m = b.length();
	if(n>m){
		swap(a,b);
		swap(n,m);
	}
	ll count = 0;
	string c="";
	for(int i=1;i<=a.length();i++){
		c+=a[i-1];
		ll value = n/c.length();

		string newA = "";
		if(m%c.length()!=0 || n%c.length()!=0){
			continue;
		}
		if(c.length()==1){
			char d = c[0];
			string temp(value , d);
			newA = temp;
		}else{

			while(value--){
				newA += c;
			}
		}
		
		if(newA == a){
			value = m/c.length();
			string newB="";
			if(c.length()==1){
				char d = c[0];
				string temp(value , d);
				newB = temp;
			}else{

				while(value--){
					newB += c;
				}
			}
			
			if(newB == b){
				count++;
			}
		}
	}
	return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	string a , b;
 	cin>>a>>b;

 	cout<<solve(a , b)<<endl;   
    return 0;
}