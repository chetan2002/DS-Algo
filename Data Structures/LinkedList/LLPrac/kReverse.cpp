//https://hack.codingblocks.com/app/contests/2022/1326/problem
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = nullptr;
    }
};

void insertAtTail(Node* &head , Node* &tail , int val){
    if(head==nullptr){
        head=new Node(val);
        tail = head;
        return;
    }
    Node* n = new Node(val);
    tail->next = n;
    tail = n;
}

void print(Node* head){
    if(head==nullptr){
        return;
    }
    cout<<head->data<<" ";
    print(head->next);
}

void reverse(Node* &head , Node* &tail , Node* &rest){
    Node* prev = head;
    Node* curr = head->next;
    prev->next = rest;
    Node* temp = nullptr;
    while(prev!=tail){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
}

Node* KReverse(Node* head , int k){
    if(head==nullptr || head->next==nullptr || k<2){
        return head;
    }

    Node* start = head;
    Node* end = head;
    bool first=true;
    int i=1;
    Node* lastStart = nullptr;
    while(end!=nullptr){
        if(i<k){
            i++;
            end=end->next;
        }else{
            i=1;
            if(first){
                head = end;
                first = false;
            }
            reverse(start , end , end->next);

            if(lastStart!=nullptr){
                lastStart->next = end;
            }
            lastStart = start;
            start = start->next;
            end = start;

        }
    }
    return head;
}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        insertAtTail(head , tail , val);
    }
    // print(head);
    // cout<<endl;
    head = KReverse(head , k);
    print(head);
    return 0;
}