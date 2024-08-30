#include <iostream>
#include <vector> 

using namespace std; 

/* -------- Subject --------  
You are given two non-empty linked lists, l1 and l2, where each represents a non-negative integer.
The digits are stored in reverse order, e.g. the number 123 is represented as 3 -> 2 -> 1 -> in the linked list.
Each of the nodes contains a single digit. You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Return the sum of the two numbers as a linked list. */

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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode* rep = new ListNode(); 
    ListNode* curr = rep;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) 
    {
        int sum = carry;
        if (l1 != nullptr) 
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) 
        {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        ListNode* node = new ListNode(sum % 10);
        curr->next = node;
        curr = curr->next;
    }

    return rep->next; 
}

int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);

    node1->next = node2;
    node2->next = node3;

    cout << "list1 : ";
    printList(node1);
    // Output : list1 : 1 2 3 

    ListNode* sum = addTwoNumbers(node1,node1);

    std::cout << "Sum : "; 
    printList(sum);
    // Output : Sum : 2 4 6

    delete node1;
    delete node2;
    delete node3;

    return 0; 
}