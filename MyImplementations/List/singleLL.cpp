#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = nullptr;
    }
};

class List{
    node* head;
    node* tail;

    friend ostream& operator<<(ostream &os , List &ob);
    //return kth node from start
    node* nodeAtPos(int k){
        if(head==nullptr){
            return nullptr;
        }
        node* temp = head;
        while(temp!=nullptr and k--){
            temp=temp->next;
        }
        return temp;
    }
    
    //destroy nodes
    void destroy(node* temp){
        if(temp == nullptr){
            return;
        }
        destroy(temp->next);
        delete temp;
    }
public:
    //constructor
    List(){
        head = nullptr;
        tail = nullptr;
    }
    //copy constructor from object
    List(List& ob){
        if(ob.head!=nullptr){ 
            node* temp = head;
            temp = new node(ob.head->data);
            head = temp;
            node* obtemp= ob.head;
            obtemp = obtemp->next;
            while(obtemp!=nullptr){
                node* nn = new node(obtemp->data);
                temp->next = nn;
                temp = temp->next;
                obtemp =obtemp->next;
            }
            
            tail = temp;

        }else{
            head = nullptr;
            tail = nullptr;
        }
    }
   
   //list from node
    List(node* ob , int k){
        if(ob==nullptr){
            head=nullptr;
            tail = nullptr;
            return;
        }

        node* tempf = ob;
        head = new node(tempf->data) ;
        node* temp = head;
        tempf = tempf->next;
        while(tempf!=nullptr and k--){
            node* n = new node(tempf->data);
            temp->next = n;
            temp = temp->next;
            tempf = tempf->next;
            tail = temp;
        }
    }


    //find length
    int length(){
       node* temp = head;
       int len = 0;
       while(temp!=nullptr){
           len++;
           temp = temp->next;
       }
       return len;
    }

    //insert at beginning
    void push_front(int d){
        if(head==nullptr){
            head = new node(d);
            tail = head;
            return;
        }
        node* n = new node(d);
        n->next = head;
        head = n; 
    }

    //insert at end
    void push_back(int d){
        if(head==nullptr){
            push_front(d);
            return;
        }
        node* n = new node(d);
        tail->next  = n;
        tail = tail->next;
    }

    //insert at kth pos
    void emplace(int d , int k){
        if(head == nullptr || k==0){
            push_front(d);
            return; 
        }
        node* temp = head;
        while(temp->next!=nullptr and --k){
            temp = temp->next;
        }
        node* n = new node(d);
        n->next = temp->next;
        temp->next = n;
        if(n->next == nullptr){
            tail =n;
        }
    }

    //delete front
    int pop_front(){
        if(head==nullptr){
            return -1;
        }
        node* temp = head;
        head= head->next;
        int val = temp->data;
        delete [] temp;
        return val;
    }

    //delete end
    int pop_back(){
        if(head==nullptr){
            return -1;
        }
        node* temp = head;
        while(temp->next->next!=nullptr){
            temp = temp->next;
        }
        int val= tail->data;
        delete [] tail;
        temp->next = nullptr;
        tail = temp;
        return val;
    }


    //delete in mid
    void erase(int pos){
        if(pos ==0){
            pop_front();
            return;
        }
        node* temp = nodeAtPos(pos-1);
        if(temp==nullptr){
            //nothing can be done 
            //throw error
            return;
        }
        if(temp->next == nullptr){
            return;
        }
        node* temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
        if(temp->next == nullptr){
            tail = temp;
        }
    }
    
    //delete a range
    void erase(int pos1 , int len){
        node* first = nodeAtPos(pos1-1);
        node* second = nodeAtPos(pos1+len-1);

        if(first == nullptr){
            //error
            return;
        }
        if(second == nullptr || second->next == nullptr){
            node* temp = first->next;
            first->next = nullptr;
            tail = first;
            destroy(temp);
            return;
        }

        node* temp = first->next;
        first->next = second->next;
        second->next = nullptr;
        destroy(temp);
    } 

    //print 
    void print(){
        node* temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    
   //operator[]
    int operator[](int i){
        node* temp = nodeAtPos(i);
        return temp->data;
    }


  
};

 //"<<" overload
 ostream& operator<<(ostream &os , List &l){
     l.print();
     return os;
 }

int main(){
    List l1 ;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        l1.push_front(val);
    }
    cout<<l1<<endl;
    return 0;
}