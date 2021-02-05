#include<iostream>
using namespace std;

class node{
    public:
        int val;
        node* next;
        string key;
        node(string k , int v){
            key = k;
            val = v;
        }
};

class hashmap{
    int ts;
    node** arr;
    int cs;     //current size

    void rehashing(){
        node** oldarr = arr;
        int oldts = ts;
        //1. Double the size of the hashtable
        arr = new node*[2*ts];
        ts = 2 * ts;
        cs = 0;
        for( int i = 0 ; i < ts ; i++ ){
            arr[i] = nullptr;
        }

        //2. Now copy the old table key , values into the new hashtable
        for ( int i = 0 ; i < oldts ; i ++ ){
            node* head = oldarr[i];
            while (head){
                insert(head -> key  , head -> val);
                head = head ->next;
            }
        }

        //now we have copied the data so delete the arr
        delete []oldarr;
    }

    int hashFunction(string key){
        int mul = 1;
        int ans = 0 ;

        for( int i = 0 ; i < key.length() ; i++){
            ans += key[i];
            mul *= 29;
        }
        ans %= ts ; 
        return ans ; 
    }
public: 
    hashmap(int size = 7){
        arr = new node*[size];
        cs = 0;
        ts = size;
        //because arr is of pointer type that's why initialize every value as nullptr as it shouldn't be garbage
        for(int i=0 ; i<ts ; i++){
            arr[i] = nullptr;
        }
    }

    void insert(string key , int val){
        cs++;
        int indx = hashFunction(key);
        node* n = new node(key ,val);
        n->next = arr[indx];
        arr[indx] = n;
        if( cs/(ts*1.0) > 0.6){
            rehashing();
        }
    }

    node* search(string key){
        int indx = hashFunction(key);
        node* head = arr[indx];
        while(head != nullptr){
            if(head->key == key){
                return head;
            }
            head = head->next;
        }
        return nullptr;
    }

    void Print(){
        for(int i = 0 ; i < ts ; i++ ){
            cout << i <<"-->";
            node* head = arr[i];
            while(head){
                cout<<"(" << head->key <<") , ";
                head = head->next ;
            }
            cout<<endl;
        }
    }

    int& operator[](string key){
        node* ans = search(key);
        if(ans == nullptr){
            //key is not present
            //in this case value have to be inserted
            int garbage = -1;
            insert(key , garbage);
            ans = search(key);
            return ans->val;

        }else{
            //key is present
            //ans->key and ans->val
            return ans->val;
        }
    }

};

int main(){
    hashmap h1 ;
    h1.insert("hello" , 22);
    h1.insert("Apple" , 333);
    h1.insert("Tomato" , 11);

    h1["Yellow"] = 93;  //insertion
    h1["Yellow"] = 100;  //updation
    cout<<h1["Yellow"]<<endl;   //searching
   //h1.Print();
    return 0;
}