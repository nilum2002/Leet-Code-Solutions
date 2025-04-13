#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        this->next = nullptr;

    }

};


ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr;

    ListNode* curr = head;

    while (curr){
        ListNode* next_= curr->next;
        curr->next = pre;
        pre = curr;
        curr = next_;
    }

    return pre;
    
}