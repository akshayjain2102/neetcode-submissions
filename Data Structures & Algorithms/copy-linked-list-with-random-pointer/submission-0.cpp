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
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* dummynode = new Node(-1);
        unordered_map<Node*,Node*> mpp;
        Node* temp = head;
        Node* temp1 = dummynode;
        while(temp != NULL){
            Node* newnode = new Node(temp->val);
            mpp[temp] = newnode;
            temp1->next = newnode;
            temp1 = temp1->next;
            temp = temp->next;
        }
        temp = head;
        temp1 = dummynode->next;
        while(temp != NULL){
            temp1->random = mpp[temp->random];
            temp1 = temp1->next;
            temp = temp->next;
        }
        return dummynode->next;
    }
};
