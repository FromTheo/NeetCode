#include <iostream>

using namespace std; 

/* -------- Subject --------  
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted linked list and return the head of the new sorted linked list.
The new list should be made up of nodes from list1 and list2. */

/* -------- Explanation --------
We will operate using recursion. If the value pointed to by list1 is less than the value pointed to by list2,
we call the function mergeTwoLists with list1->next and list2, then we return list1. */

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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    if (list1->val < list2->val) 
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } 
    else 
    {
        list2->next = mergeTwoLists(list2->next, list1);
        return list2;
    }
}

int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(1);
    ListNode* node5 = new ListNode(3);
    ListNode* node6 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;

    node4->next = node5; 
    node5->next = node6; 

    cout << "list1 : ";
    printList(node1);
    // Output : list1 : 1 2 4 
    cout << "list2 : ";
    printList(node4); 
    // Output : list 2 : 1 3 5 

    ListNode* mergedList = mergeTwoLists(node1, node4);

    cout << "mergedList : ";
    printList(mergedList);
    // Output : mergedList : 1 1 2 3 4 5 

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;

    return 0; 
}