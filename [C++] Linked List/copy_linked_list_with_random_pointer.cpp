#include <iostream>
#include <map>

using namespace std; 

/* -------- Subject --------  
You are given the head of a linked list of length n. Unlike a singly linked list, each node contains an additional pointer random, which may point to any node in the list, or null.

Create a deep copy of the list.

The deep copy should consist of exactly n new nodes, each including:

The original value val of the copied node
A next pointer to the new node corresponding to the next pointer of the original node
A random pointer to the new node corresponding to the random pointer of the original node
Note: None of the pointers in the new list should point to nodes in the original list.

Return the head of the copied linked list. */

class Node 
{
    public:

    int val;
    Node* next;
    Node* random;
    
    Node(int _val) 
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

void printList(Node* head) 
{
    Node* cur = head;
    while (cur != NULL) {
        cout << "Node : [" << cur->val;
        if (cur->random)
            cout << ", " << cur->random->val << "]" << endl;
        else
            cout << ", nullptr]" << endl;
        cur = cur->next;
    }
    cout << endl;
}

Node* copyRandomList(Node* head) 
{
    map<Node*, Node*> M;
    M[nullptr] = nullptr;

    Node* cur = head;
    while (cur != nullptr) 
    {
        Node* copy = new Node(cur->val);
        M[cur] = copy;
        cur = cur->next;
    }

    cur = head;
    while (cur != nullptr) 
    {
        Node* copy = M[cur];
        copy->next = M[cur->next];
        copy->random = M[cur->random];
        cur = cur->next;
    }

    return M[head];
}

int main() {

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    node1->random = node3; 
    node2->random = node1; 
    node3->random = node4;
    node4->random = node2; 

    cout << "Original list:" << endl;
    printList(node1);
    /* Output : 
    Original list:
    Node : [1, 3]
    Node : [2, 1]
    Node : [3, 4]
    Node : [4, 2] */

    Node* copiedList = copyRandomList(node1);

    cout << "Copied list:" << endl;
    printList(copiedList);
    /* Output : 
    Copied list:
    Node : [1, 3]
    Node : [2, 1]
    Node : [3, 4]
    Node : [4, 2] */

    delete node1; 
    delete node2; 
    delete node3; 
    delete node4; 

    return 0;
}