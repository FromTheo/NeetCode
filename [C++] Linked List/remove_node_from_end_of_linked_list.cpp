#include <iostream>
#include <vector>

using namespace std; 

/* -------- Subject --------  
You are given the beginning of a linked list head, and an integer n.
Remove the nth node from the end of the list and return the beginning of the list. */

/* -------- Explanation --------
We will extract all nodes and store them in a vector. 
If this vector has a size of 1, it means only one node is present in the list, so we return nullptr.
Otherwise, we remove the nth element from the end, connect the nodes together, and return the resulting list.*/

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

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    std::vector<ListNode*> v; 
    ListNode* copy = head; 
    int compteur = 0;

    while(copy != nullptr)
    {
        ListNode* node = new ListNode(copy->val); 
        v.push_back(node);
        copy = copy->next; 
    }

    if(v.size() == 1) return nullptr; 

    vector<ListNode*> v_end; 
    for(int i = 0; i < v.size(); ++i)
    {
        if(i != v.size()-n) v_end.push_back(v[i]);
    }

    for(int i = 0; i < v_end.size()-1; ++i)
    {
        v_end[i]->next = v_end[i+1]; 
    }

    return v_end.front();
}

int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4; 

    printList(node1); // Output : 1 2 3 4 

    ListNode* res1 = removeNthFromEnd(node1, 2); 
    printList(res1); // Output : 1 2 4 

    ListNode* res2 = removeNthFromEnd(node5, 1);
    printList(res2); // Output : 

    return 0; 
}