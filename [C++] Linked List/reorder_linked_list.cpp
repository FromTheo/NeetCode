#include <iostream>
#include <vector> 

using namespace std; 

/* -------- Subject --------  
You are given the head of a singly linked-list.
The positions of a linked list of length = 7 for example, can intially be represented as:

[0, 1, 2, 3, 4, 5, 6]

Reorder the nodes of the linked list to be in the following order:

[0, 6, 1, 5, 2, 4, 3]

Notice that in the general case for a list of length = n the nodes are reordered to be in the following order:

[0, n-1, 1, n-2, 2, n-3, ...]

You may not modify the values in the list's nodes, but instead you must reorder the nodes themselves. */

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

// Method 1 : without two pointers. 
void reorderList_1(ListNode*& head) 
{
    vector<ListNode*> v; 
    while(head != nullptr)
    {
        ListNode* node = new ListNode(head->val);
        v.push_back(node);  
        head = head->next; 
    }

    int n = v.size();  

    if (n == 1)
    {
        head = v.front(); 
        return; 
    }

    for(int i = 0; i < n/2; ++i)
    {
        v[i]-> next = v[n-i-1]; 
    } //0 -> n-1, 1-> n-2.... 

    if(n%2 == 0)
    {
        for(int i = 1; i < n/2; ++i)
        {
            v[n-i]->next = v[i]; 
        }
    }
    else
    {
        for(int i = 1; i < n/2; ++i)
        {
            v[n-i]->next = v[i]; 
        }
        v[n-n/2]-> next = v[n/2]; 
    }
    head = v[0]; 
}

// Method 2 : with two pointers.
void reorderList(ListNode* head) 
{
    if (!head || !head->next) return; // Handle empty or single node list
        
    // Extract nodes into a vector
    vector<ListNode*> nodes;
    ListNode* curr = head;
    while (curr) 
    {
        nodes.push_back(curr);
        curr = curr->next;
    }
        
    int n = nodes.size();
    int left = 0, right = n - 1;
        
    // Rearrange nodes as specified
    while (left < right) 
    {
        nodes[left]->next = nodes[right];
        left++;
        if (left == right) break; // Break if it's the last element
        nodes[right]->next = nodes[left];
        right--;
    }
        
    // Set the next of the last node to nullptr
    nodes[left]->next = nullptr;
}

int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4; 
    
    printList(node1); //Output : 1 2 3 4 
    reorderList(node1); //Output : 1 4 2 3 
    printList(node1); 

    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0; 
}