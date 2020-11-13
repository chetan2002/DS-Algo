#include<bits/stdc++.h>
using namespace std;

//using backtracking and map to solve the question
map<string , char> mp{{"1" , 'a'} , {"2" , 'b'} , {"3" , 'c'} , {"4" , 'd'} , {"5" , 'e'} , {"6" , 'f'} , {"7" , 'g'} , {"8" , 'h'} , {"9" , 'i'} , {"10" , 'j'} , {"11" , 'k'} , {"12" , 'l'} , {"13" , 'm'} , {"14" , 'n'} , {"15" , 'o'} , {"16" , 'p'} , {"17" , 'q'} , {"18" , 'r'} , {"19" , 's'} , {"20" , 't'} , {"21" , 'u'} , {"22" , 'v'} , {"23" , 'w'} , {"24" , 'x'} , {"25" , 'y'} , {"26" , 'z'}};

void DecodeMap(char* s , char* a , int i , int j , int n){
    if(i==n){
        a[j]='\0';
        cout<<string(a)<<endl;
        return;
    }
    string v = "";
    v =s[i];
    if(mp.find(v)!=mp.end()){
        a[j]=mp.at(v);
        DecodeMap(s , a , i+1 , j+1 , n);
    }
    if(i+1!=n){
        v =  s[i];
        v = v + s[i+1];
        if(mp.find(v)!=mp.end()){
            a[j]=mp[v];
            DecodeMap(s , a , i+2 , j+1 , n);
        }
        
    }
}

int main(){
    char s[1000] ;
    cin>>s;
    string v = (string)s;
    int n = v.size();
    char a[1000];
    DecodeMap(s,a,0,0,n);
    return 0;
}
