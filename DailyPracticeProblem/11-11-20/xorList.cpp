/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

An XOR linked list is a more memory efficient doubly linked list. 
Instead of each node holding next and prev fields, it holds a 
field named both, which is an XOR of the next node and the previous node. 
Implement an XOR linked list; it has an add(element) which adds the element to the end,
 and a get(index) which returns the node at index.

If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and dereference_pointer functions that converts between nodes and memory addresses.
*/
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* npx;
    Node(int data){
        this->data = data;
        this->npx = nullptr;
    }
};

Node* XOR(Node* a , Node* b){
    if(a==nullptr){
        return b;
    }
    if(b==nullptr){
        return a;
    }
    return reinterpret_cast<Node *>(
        (reinterpret_cast<uintptr_t> (a))^(reinterpret_cast<uintptr_t> (b)) 
    );
}

void insertAtBeginning(Node* &head , int data){
    if(head == nullptr){
        Node* n = new Node(data);
        head =n;
        return;
    }
    Node* n = new Node(data);
    n->npx = head;
    head->npx = XOR(head->npx , n);
    head = n;
}

void insertAtEnd(Node* &head, int data){
    if(head==nullptr){
        insertAtBeginning(head , data);
        return ;
    }
    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    while(curr!=nullptr){
        next = XOR(prev , curr->npx);
        prev = curr;
        curr = next;     
    }
    Node* n = new Node(data);
    prev->npx = XOR(prev->npx , n);
    n->npx = prev;

}
void print(Node* head){
    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        next = XOR(prev , curr->npx);
        prev = curr;
        curr = next;     
    }
    cout<<endl;
}

Node* getNode(Node* head , int i){
    if(head == nullptr){
        return nullptr;
    }
    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    for(int j=0;j<i and curr!=nullptr;j++){
        next = XOR(prev , curr->npx);
        prev = curr ;
        curr = next;
    }
    return curr;
}

int main(){
    Node* head = nullptr;
    insertAtBeginning(head , 10);
    insertAtBeginning(head , 20);
    insertAtBeginning(head , 30);
    insertAtBeginning(head , 40);
    insertAtEnd(head , 100);
    insertAtEnd(head , 200);
    insertAtEnd(head , 300);
    insertAtEnd(head , 400);
    
    print(head);
    Node* a = getNode(head , 0);
    cout<<a->data<<endl;
    return 0;
}
