#include <iostream>
#include <vector>

using namespace std; 

/* -------- Subject --------  
You are given an array of k linked lists lists, where each list is sorted in ascending order.
Return the sorted linked list that is the result of merging all of the individual linked lists. */

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

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    int n = lists.size(); 
    if(n == 0) return nullptr; 
    while(n > 1)
    {
        for(int i = 0; i < n/2; ++i)
        {
            lists[i] = mergeTwoLists(lists[i], lists[n-i-1]);
        }
        n = (n+1)/2;
    }
    return lists.front(); 
}

int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(1);
    ListNode* node5 = new ListNode(3);
    ListNode* node6 = new ListNode(5);
    ListNode* node7 = new ListNode(7);
    ListNode* node8 = new ListNode(8);

    vector<ListNode*> v; 
    
    node1 -> next = node2; 
    node2 -> next = node4; 
    v.push_back(node1); 

    node3 -> next = node5; 
    node5 -> next = node6; 
    v.push_back(node3); 

    node7 -> next = node8; 
    v.push_back(node7);

    for(ListNode* l : v)
    {
        printList(l); 
        cout << endl; 
    }
    /* Output : 
    1 2 1 
    4 3 5 
    7 8 */

    ListNode* res = mergeKLists(v); 
    printList(res); //Output : 1 2 1 4 3 5 7 8 
    
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6; 
    delete node7; 
    delete node8; 

    return 0; 
}