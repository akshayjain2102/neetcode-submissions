/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        int size = 0;
        ListNode* temp = head;
        while(temp != NULL){
            size++;
            temp = temp->next;
        }
        if(size == n) return head->next;
        int a = 1;
        temp = head;
        ListNode* prev = NULL;
        while( temp != NULL){
            if(a == size-n+1){
                prev->next = temp->next;
                delete(temp);
                break;
            }
            a++;
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};
