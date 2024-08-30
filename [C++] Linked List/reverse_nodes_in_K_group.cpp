#include <iostream>
#include <vector>

using namespace std; 

/* -------- Subject --------  
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.*/

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head) 
{
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

ListNode* createList(const std::vector<int>& values) 
{
    ListNode temp;
    ListNode* tail = &temp;
    for (int val : values) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return temp.next;
}

ListNode* reverseKGroup(ListNode* head, int k) 
{
    if (head == nullptr || k == 1) return head;

    ListNode temp(0);
    temp.next = head;
    ListNode* prev = &temp, *curr = &temp, *next = &temp;
    int count = 0;

    // On compte le nombre de noeuds dans la liste.
    while (curr->next != nullptr) 
    {
        curr = curr->next;
        count++;
    }

    // Tant qu'il reste au moins k noeuds à traier : 
    while (count >= k) 
    {
        curr = prev->next;  // Début du morceau de la chaine à inverser. 
        next = curr->next;  

        for (int i = 1; i < k; ++i) 
        {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        // On met le pointeur à la fin du groupe inversé pour préparer au suivant. 
        prev = curr;
        count -= k;
    }
    return temp.next;
}


int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);

    node1 -> next = node2; 
    node2 -> next = node3; 
    node3 -> next = node4; 
    node4 -> next = node5; 
    node5 -> next = node6; 

    ListNode* res = reverseKGroup(node1, 3); 
    printList(res); //Output : 3 2 1 6 5 4 

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;

    return 0; 
}