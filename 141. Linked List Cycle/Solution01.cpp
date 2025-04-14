#include <bits/stdc++.h>
using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {} 
};


bool hasCycle(ListNode *head) {

    set<ListNode*> hash_set ;

    ListNode* curr = head;
    while (curr){
        if (hash_set.find(curr) != hash_set.end()){
            return true;
            // break;
        }else{
            hash_set.insert(curr);
        }
        curr = curr->next;
    }
    return false;
    
}