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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while( fast!= NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode* temp = slow;
        ListNode* pre = NULL;
        while(temp != NULL){
            ListNode* curr = temp->next;
            temp->next = pre;
            pre = temp;
            temp = curr;
        }
        temp = head;
        while( temp != NULL && pre != NULL){
            ListNode* curr1 = temp->next;
            ListNode* curr2 = pre->next;
            temp->next = pre;
            temp = curr1;
            if(temp == NULL) break;
            pre->next = temp;
            pre = curr2;
        }
    }
};