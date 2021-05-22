#include<bits/stdc++.h>
using namespace std;
#define ll long long int




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 	
 	int n;
 	cin>>n;

 	vector<int> v(n);
 	for(int i=0;i<n;i++){
 		cin>>v[i];
 	}   

 	int spectator = 3;
 	bool pos = true;
 	for(auto c: v){
 		if(c==spectator){
 			pos = false;
 			break;
 		}
 		if(c==1){
 			if(spectator==2){
 				spectator = 3;
 			}else{
 				spectator = 2;
 			}
 		}else
 		if(c==2){
 			if(spectator==3){
 				spectator = 1;
 			}else{
 				spectator = 3;
 			}
 		}else
 		if(c==3){
 			if(spectator==2){
 				spectator = 1;
 			}else{
 				spectator = 2;
 			}
 		}

 	}
 	if(pos){
 		cout<<"YES"<<endl;
 	}else{
 		cout<<"NO"<<endl;
 	}
    return 0;
}