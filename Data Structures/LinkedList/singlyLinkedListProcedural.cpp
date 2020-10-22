//https://ide.codingblocks.com/s/360442

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        
        Node(int d){
            data=d;
            next = nullptr;
        }
};


//finding length of linkedlist
int length(const Node* head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}


//Printting the linkedlist
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

//INserting elements in Linkedlist
//Inserting at head
void insertAtHead(Node* &head , int d){
    if(head==NULL){
        head=new Node(d);
        return;
    }
    Node* temp = new Node(d);
    temp->next=head;
    head=temp;
}



//Inserting at end
void insertAtTail(Node* &head , int d){
    if(head==nullptr){
        head = new Node(d);
        return ;
    }
    Node* temp = head;
    while(temp->next!=nullptr){
        temp=temp->next;

    }
    Node* n = new Node(d);
    temp->next = n;
}

//Inserting in middle
void insertInMiddle(Node* &head , int d , int p){
    if(head==NULL || p==0){
        insertAtHead(head , d);
    }else
    if(p>length(head)){
        insertAtTail(head, d);
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
        temp->next = n;
    }

}
//Deleting in linkedlist
//Deleting head
void deleteHead(Node* &head){
    if(head==nullptr){
        return;
    }
    Node* temp = head->next;
    delete head;
    head = temp;
}
//Deleting in end
void deleteTail(Node* &head){
    if(head == nullptr) {
        return;
    }
    Node* temp = head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    Node* temp2 = temp->next;
    temp->next = nullptr;
    delete temp2;
}
//Deleting in middle
void deleteInMid(Node* head , int p){
    if(head == nullptr){
        return ;
    }
    if(p==0){
        deleteHead(head);
    }
    else if(p>length(head)){
        deleteTail(head);
    }else{
        int i=1;
        Node* temp = head ;
        while(i<p){
            temp = temp->next;
            i++;
        }
        Node* temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
    }
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

//Overloading << operator
//is we use void as a return type , it won't let us cascade the operator
//because the cout<<head will return void and void<<head2 is not a valid expression
//so is we return the type ostream& then it would help us cascade
//cout; is a valid statement in cpp and doesn't do anything
// cout is object of ostream class
ostream& operator<<(ostream &os , Node* head){
    print(head);
    return os;
}

//overloading >> operator
istream& operator>>(istream &is , Node* &head){
    head = take_input();
    return is;
}

// to reverse the linkedlist 
void reverse(Node*&head){
    //C points to present node , P to previous and N to next node
    Node* C=head;
    Node* P = NULL;
    Node* N;
    while(C!=NULL){
        N = C->next;
        C->next = P;
        P=C;
        C = N;
    }
    head  =  P;
}
//reverse recursively
Node* recursiveReverse(Node* head){
    //smallestLL
    if(head->next==NULL or head==NULL){
        return head;
    }
    //rec case
    Node* shead = recursiveReverse(head->next);
    Node* temp = shead;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    head->next = NULL;
    temp->next = head;
    return shead;
}

//REcursive reverse optimised 
Node* recursiveReverseOptimised(Node* head){
    if(head->next == NULL or head==NULL){
        return head;
    }
    Node* shead = recursiveReverseOptimised(head->next);

    Node* temp = head->next;
    temp->next = head;
    head->next = NULL;
    return shead;
}

//finding mid-point of linkedlist
//using fast-runner technique

Node* midpoint(Node* head){
    if(head==NULL or head->next == NULL){
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

//Find kth node from the last
Node* kPointFromLast(Node* head , int k){
    if(head==NULL or head->next == NULL or k>=length(head)){
        return head;
    }
    Node* slow = head;
    Node* fast = head;
    while(k--){
        fast=fast->next;
    }
    while(fast!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

//MergeSort
//Merging two linkedlist 
Node* merge(Node* a , Node* b){
    //base case
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
     
     //take a head pointer
     Node* c;
     if(a->data < b->data){
         c = a;
         c->next = merge(a->next , b);
     }else{
         c=b;
         c->next = merge(a , b->next);
     }
     return c;

}
//mergeSort function
Node* mergeSort(Node* head){
    //base case
    if(head == NULL or head->next == NULL){
        return head;
    }

    //rec case
    //1.Break
    Node* mid = midpoint(head);
    Node* a = head;
    Node* b = mid->next;
    mid->next = NULL;

    //2.sort the two parts
    a = mergeSort(a);
    b = mergeSort(b);

    //3. merge them
    Node* c = merge(a,b);
    return c; 
}
// create a ll with a cycle
Node* createLinkedListWithCycle(int p){
    Node* head = take_input();
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* common = kPointFromLast(head , length(head)-p);
    tail->next = common;
    return head;
}


//cycle Detection and removal(Floyd's cycle)

bool cycleDetection(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    bool cycle=false;
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            cycle = true;   
            break;
        }
    }
    if(cycle){
        slow = head;
        while(slow->next!=fast->next){
            slow=slow->next;
            fast = fast->next;
        }
        fast->next = NULL;        
        return true;
    }else{
        return false;
    }
}

int main(){
    Node* head=take_input();
    // insertAtHead(head,3);
    // insertAtHead(head,2);
    // insertAtHead(head,1);
    // insertAtHead(head,0);
    // insertAtTail(head , 7);
    // insertAtTail(head , 8);
    // insertInMiddle(head , 5 , 4);
    // insertInMiddle(head , 4 , 4);

    deleteInMid(head, 3);    
    print(head);

    //searching in  linkedlist
    cout<<(search(head , 6)?"Yes , Element is Present":"No , Element is not present")<<endl;;
    cout<<(searchRecursive(head , 4)?"Yes , Element is Present":"No , Element is not present")<<endl;;
    
    //overloading 
    cout<<head<<head;  //overloading << operator //cascading is working in our << operator 
   
   //creating a new linkedlist
    Node* head2;    //creating a new linkedlist
    cin>>head2;      //overloading the >> operator
    cout<<head2;

    //reverse of linkedlist
    reverse(head2);
    cout<<head2;

    //REVERSE RECURSIVE O(n2)
    head2 = recursiveReverse(head2);
    cout<<head2;

    //Reverse recursive optimised O(N)
    head2 = recursiveReverseOptimised(head2);
    cout<<head2;

    //Finding mid-point of linkedlist
    Node* mid = midpoint(head2);
    cout<<mid->data<<endl;

    //Finding kth node from last
    Node* k = kPointFromLast(head2 , 3);
    cout<<k->data<<endl;

    //Sorting the linkedlist
    Node* c = mergeSort(head2);
    cout<<c<<endl;

    //Cycle Detection

    //create a ll with cycle
    Node* linkedListWithCycle = createLinkedListWithCycle(3);
    //Detection and removal of cycle using Floyd algo
    if(cycleDetection(linkedListWithCycle)){
        cout<<"A cycle was detected ,which was removed"<<endl;
        cout<<linkedListWithCycle<<endl;
    }else{
        cout<<"No cycle was detected "<<endl;
        cout<<linkedListWithCycle<<endl;
    }

    return 0;
}
