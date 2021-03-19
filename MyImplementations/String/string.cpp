#include<iostream>
#include<cstring>
using namespace std;

class String{
    char *str;

    friend ostream& operator<<(ostream& os ,const String&  ob);
    friend istream& operator>>(istream& is ,String&  ob);
    friend String operator+(const String& s1 ,const String& s2);
    friend bool operator==(const String& s1 , const String& s2);
    friend void operator+=(String&s1 , const String&s2);

    void merge(int s , int e , char* c){
        int mid = (s+e)/2;
        char buffer[e-s+1];
        int i=s , j = mid+1 , k = 0;
        while(i<=mid and j<=e){
            if(c[i]<=c[j]){
                buffer[k++] = c[i++];
            }else{
                buffer[k++] = c[j++];
            }
        }

        while(i<=mid){
            buffer[k++] = c[i++];
        }
        while(j<=e){
            buffer[k++] = c[j++];
        }
        k=0;
        for(i=s;i<=e;i++){
            c[i] = buffer[k++];
        }
    }

    void mergeSort(int s , int e , char* c){
        if(s>=e){
            return ;
        }
        int mid = (s+e)/2;
        mergeSort(s , mid ,c);
        mergeSort(mid+1 , e , c);
        merge(s , e , c);
    }
public: 
    //constuctor
    String(){
        str = nullptr;
        str = new char[1];
        str[0] = '\0';
    }
    
    //having value as an arguement of object
    String(char *s){
        if(s == nullptr){
            str = new char[1];
            str[0] = '\0';
        }else{
            str = new char[strlen(s) + 1];
            strcpy(str , s); 
        }
    }

    //copy constructor
    String(String &anotherString){
        str = new char[strlen(anotherString.str)+1];
        strcpy(str , anotherString.str);
    }

    String& operator=(const String& s){
        if(this == &s){
            return *this;
        }

        delete [] str;
        str = new char[strlen(s.str) + 1];
        strcpy(str , s.str);
        return *this;
    }

    void push_back(char c){
        char* buffer = new char[strlen(str)+2];
        strcpy(buffer , str);
        buffer[strlen(str)] = c;
        buffer[strlen(str)+1] = '\0';
        delete []str;
        str = buffer;
    }

    void push_back(const String& a){
        *this = *this + a;
    }

    void push_back(char* s){
        int length = strlen(str) + strlen(s);
        char* buffer = new char[length+1];
        strcpy(buffer , str);
        strcat(buffer , s);

        delete [] str;
        str = buffer;

    }
    void pop_back(){
        int length = strlen(str);
        str[length-1] = '\0';
    }

    int length(){
        return strlen(str);
    }

    void reverse(){
        int len = strlen(str);
        for(int i=0; i<len/2; i++){
            swap(str[i] , str[len-i-1]);
        }        
    }

    bool isPalindrome(){
        int len = strlen(str);
        for(int i=0 ;i<len/2 ; i++){
            if(str[i] != str[len-i-1]){
                return false;
            }
        }
        return true;
    }

    void sort(){
        int n = strlen(str);
        char* buffer = new char[n+1];
        strcpy(buffer , str);

        mergeSort(0 , n-1 , buffer);
        delete [] str;
        str = buffer;
    }

};

ostream& operator<<(ostream& os  , const String& s){
    os<<s.str;
    return os;
}

istream& operator>>(istream& is , String& s){
    char* store = new char[1000];
    is>>store;

    s = String(store);

    delete[] store;
    return is;
}

bool operator==(const String& s1 ,const String& s2){
    int val = strcmp(s1.str , s2.str);
    if(val==0){
        return true;
    }

    return false;

}

String operator+(const String& s1 , const String& s2){
    int length = strlen(s1.str) + strlen(s2.str);

    char* store = new char[length + 1];

    strcpy(store , s1.str);
    strcat(store , s2.str);

    String aa(store);
    delete[] store;

    return aa;
}

void operator+=(String& s1 , const String& s2){
    s1 = s1+s2;
}

int main(){
    // String s1("Hello");
    // String s2;
    // cin>>s2;
    // // cout<<s2<<endl;
    // // cout<<(s1+s2)<<endl;
    // s1.push_back('!');
    // cout<<s1<<endl;
    // // s1.pop_back();
    // // cout<<s1<<endl;
    // s1.push_back(s2);
    // cout<<s1<<endl;
    // s1.push_back("Why do You keep saying hello");
    // cout<<s1<<endl;

    String s1("hello");
    // String s2("Hello");
    // if(s1==s2){
    //     cout<<"Same"<<endl;
    // }else{
    //     cout<<"Not Same"<<endl;
    // }
    cout<<s1<<endl;
    s1.pop_back();
    cout<<s1<<endl;
    s1.sort();
    cout<<s1<<endl;
    String s2("well");
    s1 += s2;
    cout<<s1<<endl;
    return 0;
} 