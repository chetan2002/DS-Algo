#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
     int data;
     Node* next;
     Node* prev;

     Node(int d){
         data = d;
         next = nullptr;
         prev = nullptr;
     }
};

//printing the linkedlist
void print(const Node* head){
    if(head==nullptr){
        return;
    }
    while(head->next!=nullptr){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    if(head!=nullptr){
        cout<<head->data<<endl;
        head=head->next;
    }
}

//FINDING LENGTH OF A LINKEDLIST
int length(const Node* head){
    if(head == NULL){
        return 0;
    }
    return 1+length(head->next);
}

//INSERTING IN A LINKED LIST

//insert at the beginning of doubly linkedlist
void insertAtHead(Node* &head , int d){
    if(head==NULL){
        head = new Node(d);
        return;
    }
    Node* temp = new Node(d);
    head->prev = temp;
    temp->next = head ;
    head = temp;
}

//insert at the tail
void insertAtTail(Node* &head , int d){
    if(head == NULL){
        head = new Node(d);
        return ;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* n = new Node(d);
    n->prev = temp;
    temp->next = n;
}
//insert at any place 
void insertANode(Node* &head , int d , int p){
    if(p==0 or head==NULL){
        insertAtHead(head , d);
        return;
    }else
    if(p>length(head)){
        insertAtTail(head , d);
        return;
    }else{
        //take p-1 steps
        int jump = 1 ; 
        Node* temp = head ; 
        while(jump<p){
            temp = temp->next;
            jump++;
        }
        Node* n  = new Node(d);
        n->next = temp->next;
        temp->next->prev = n;
        temp->next = n;
        n->prev = temp;
    }
}

//DELETING IN A LINKED LIST

//deleting the head
void deleteAtHead(Node* &head){
    if(head==NULL){
        return;
    }
    Node* temp = head->next;
    temp->prev = NULL;
    delete head;
    head = temp;
}
//deleting the tail
void deleteAtTail(Node* &head){
    if(head==NULL){
        return ;
    }
    Node* temp = head;
    while(temp->next->next !=NULL){
        temp = temp->next;
    }
    Node* tail = temp->next;
    temp->next = NULL;
    delete tail;
}
//deleting at any position
void deleteAtPos(Node* &head , int p){
    if(head == NULL){
        return;
    }
    if(p==0 ){
        deleteAtHead(head);
    }else
    if(p>length(head)){
        deleteAtTail(head);
    }else{
        int i=1;
        Node* temp = head ;
        while(i<p){
            temp = temp->next;
            i++;
        }
        Node* temp2 = temp->next;
        temp2->next->prev = temp;
        temp->next = temp2->next;
        delete temp2;
    }
}

//taking input
Node* take_input(){
    int d;
    cin>>d;
    Node* head=NULL;
    while(d!=-1){
        insertAtHead(head , d);
        cin>>d;
    }
    return head;
}

//overloading operator <<
ostream& operator<<(ostream &os , Node* head ){
    print(head);
    return os;
}
istream& operator>>(istream &is , Node* &head){
    head=take_input();
    return is;
}


//Searching in a linkedlist
bool search(Node* head , int key){
    Node* temp = head;
    while(temp!=nullptr){
        if(temp->data==key){
            return true;
        }
        temp = temp->next;
    }
    return false;
    
}
//search recursively
bool searchRecursive(Node* head , int key){
    if(head == nullptr){
        return false;
    }
    if(key==head->data){
        return true;
    }
    return searchRecursive(head->next , key);
}

//Reverse a doubly linkedlist
void reverse(Node* &head){
    if(head == NULL){
        return;
    }
    Node * temp2=NULL;
    Node* temp = head;
    while(temp!=NULL){
        temp2 = temp ->prev;
        temp->prev = temp->next;
        temp->next = temp2;
        temp = temp->prev;
    }
    if(temp2!=NULL){
        head = temp2->prev;
    }
}

//Mid-point
Node* midpoint(Node* head){
    if(head == NULL || head->next == NULL){
        return head ;
    }

    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL and fast->next!=NULL ){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;

}

int main(){
    Node* head;
    //using overloaded operator to take input
    cin>>head;
    //using overloaded operator to print
    cout<<head;
    deleteAtPos(head , 3);
    cout<<head;

    //reversing the linkedlist
    reverse(head);;
    cout<<head;
    
    
    return 0;
}
