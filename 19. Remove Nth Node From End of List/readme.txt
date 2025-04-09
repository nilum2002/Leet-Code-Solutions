In this problem first I use a dummy node wich is a pointer to head node. then I have already defined two other Node varables to track the position.
First I iterate n positions Node A. Then I check the Node A's next pointer goes to nullptr and I Iterate node B till satisfy the Node A->next condiition.
then I get the deletion process.



Here is the Algorithm;



deletion_from_tail(Node* head, int pos):
    Node* Dummy = head;
    Node* A = Dummy;
    Node* B = Dummy;



    for i in range(pos):
        A = A->next
    
    # here check the next pointer to be nullptr
    while (A->next):
        A = A->next
        B = B->next
    Node* del = B->next
    B->next = B->next->next;
    delete del
    return dummy->next