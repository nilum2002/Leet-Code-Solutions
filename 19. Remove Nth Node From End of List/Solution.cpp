
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val, ListNode* node = nullptr){
        this->val = val;
        this->next = node;
    }

};





ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new  ListNode(0);


    dummy->next = head;
    ListNode* A = dummy;
    ListNode* B = dummy;
    // move n times 
    for (int i =0; i < n; i++){
        A = A->next;
    }

    while (A->next){
        B = B->next;
        A= A->next;
    }
    ListNode* to_be_deleted = B->next;
    B->next= B->next->next;
    delete to_be_deleted;
    ListNode* res = dummy->next;
    delete dummy;
    return res;


}

int main (){



}