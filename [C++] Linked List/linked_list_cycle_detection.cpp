#include <iostream>
#include <map>

using namespace std; 

/* -------- Subject --------  
Given the beginning of a linked list head, return true if there is a cycle in the linked list. Otherwise, return false.
There is a cycle in a linked list if at least one node in the list that can be visited again by following the next pointer.
Internally, index determines the index of the beginning of the cycle, if it exists. The tail node of the list will set it's next pointer to the index-th node.
If index = -1, then the tail node points to null and no cycle exists.
Note: index is not given to you as a parameter. */ 

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

bool hasCycle(ListNode* head) 
{
    // Floyd's algorithm : 
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != nullptr && fast->next != nullptr) 
    {
        fast = fast->next->next;
        slow = slow->next;
            
        if (fast == slow) 
        {
            return true;     
        }
    }
    return false;
}

int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(1);

    node1->next = node2; 
    node2->next = node3; 
    node3->next = node4; 
    node4->next = node2; 

    cout << hasCycle(node1); //Output : 1. 

    delete node1;
    delete node2;
    delete node3; 
    delete node4;

    return 0; 
}