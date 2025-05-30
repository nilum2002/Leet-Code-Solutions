#include <bits/stdc++.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} 
};


bool hasCycle(ListNode *head) {

    ListNode* slow = head;
    ListNode* fast = head;


    while (fast && fast->next ){
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast){
            return true;
            break;
        }
    }

    return false;
    
}