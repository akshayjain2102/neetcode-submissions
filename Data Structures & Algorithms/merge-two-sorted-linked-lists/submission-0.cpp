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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = list1;
        ListNode* temp2 = list2;
        vector<int> arr;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        while(temp2 != NULL){
            arr.push_back(temp2->val);
            temp2 = temp2->next;
        }
        if(arr.empty()) return NULL;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        ListNode* head = new ListNode(arr[0]);
        ListNode* mover = head;
        for(int i=1;i<n;i++){
            ListNode* temp1 = new ListNode(arr[i]);
            mover->next = temp1;
            mover = temp1;
        }
        return head;
    }
};
