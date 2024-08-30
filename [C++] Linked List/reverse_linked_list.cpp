#include <iostream> 

using namespace std; 

/* -------- Subject --------  
Given the beginning of a singly linked list head, reverse the list, and return the new beginning of the list. */

/* -------- Explanation --------
We will operate through iteration. The structure of the list is:

(head) ---> 1 ---> 2 ---> 3 ---> (nullptr)

We will initialize prev as a null pointer and curr as the pointer equal to head, which is the first arrow from the left. 
Then, as long as we haven't reached the end of the list, we will:
- Initialize temp as curr->next, which will then become the value of curr.
- Replace curr->next with prev, the null pointer.
- Replace prev with curr.
- Replace curr with temp.
Finally, we return prev, the reversed list. */

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

ListNode* reverseList(ListNode* head) 
{ 
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while(curr != nullptr)
    {
        ListNode* temp = curr->next;
        curr->next = prev; 
        prev = curr;
        curr = temp ;
    }
    return prev; 
}

int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);

    node1->next = node2;
    node2->next = node3;

    cout << "Original list : ";
    printList(node1);
    // Output : Original list : 1 2 3 

    ListNode* reversedHead = reverseList(node1);

    std::cout << "Reversed list : ";
    printList(reversedHead);
    // Output :Reversed list : 3 2 1 

    delete node1;
    delete node2;
    delete node3;

    return 0; 
}