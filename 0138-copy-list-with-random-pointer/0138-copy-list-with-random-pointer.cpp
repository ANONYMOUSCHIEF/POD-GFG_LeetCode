/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    map<Node *,Node *>addr;
    Node* copyRandomList(Node* head) {
        Node * temp=head;
        while(temp){
           addr[temp]=new Node(temp->val);
           temp=temp->next;
        }
        temp=head;
        while(temp){
            addr[temp]->next=addr[temp->next];
            addr[temp]->random=addr[temp->random];
            temp=temp->next;
        }
        return addr[head];
    }
};