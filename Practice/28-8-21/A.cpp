Node* kPointFromLast(struct Node* head , int k){
    if(head==NULL or head->next == NULL or k>=length(head)){
        return head;
    }
    struct Node* slow = head;
    struct Node* fast = head;
    while(k--){
        fast=fast->next;
    }
    while(fast!=NULL){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

struct Node* MoveNodes(struct Node* head , int k , int n){
	if(head==nullptr){
		return head;
	}
	struct Node* kth = kPointFromLast(head , k+1);
	struct Node* tail = kPointFromLast(head , 1);
	struct Node* nth = kPointFromLast(head , n);
	tail->next = nth->next;
	nth->next = kth->next;
	kth->next = nullptr;
	return head;
}