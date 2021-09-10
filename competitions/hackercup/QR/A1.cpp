#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isVowelFunction(char);


int myCallerFunction(int abra , int b , int cVar){
	return 2*(abra-b) + cVar;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    for(int i=1;i<=t;i++){
    	string myString;cin>>myString;
    	unordered_map<char, int> myMap;
    	int vow = 0 , cons = 0;
    	int myMinAns = INT_MAX;
    	for(auto cVar: myString){
    		myMap[cVar]++;
    		if(isVowelFunction(cVar)){
    			vow++;
    		}else{
    			cons++;
    		}
    	}

    	for(auto cVar: myMap){
    		int sum = 0;
    		if(isVowelFunction(cVar.first)){
    			sum = myCallerFunction(vow , cVar.second , cons);
    		}else{
    			sum  = myCallerFunction(cons , cVar.second , vow);
    		}
    		myMinAns = min(sum , myMinAns);
    	}
    	if(vow==0){
    		int sum = myCallerFunction(vow , 0 , cons);
    		myMinAns = min(sum , myMinAns);
    	}
    	if(cons == 0){
    		int sum = myCallerFunction(cons , 0 , vow);
    		myMinAns = min(sum , myMinAns);
    	}
    	cout<<"Case #"<<i<<": "<<myMinAns<<endl;
    }
    return 0;
}

bool isVowelFunction(char cVar){
	switch(cVar){
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U': return true;
	}
	return false;
}

