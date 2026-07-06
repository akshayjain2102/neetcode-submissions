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
    bool hasCycle(ListNode* head) {
        ListNode* temp = head;
        map<int,int> mpp;
        while( temp != NULL){
            if(mpp[temp->val] > 1) return true;
            mpp[temp->val]++;
            temp = temp->next;
        }
        return false;
    }
};
