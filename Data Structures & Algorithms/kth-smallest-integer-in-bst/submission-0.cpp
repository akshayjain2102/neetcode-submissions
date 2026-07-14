/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return 0;
        vector<int> ans;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            TreeNode* temp = Q.front();
            Q.pop();
            if(temp->left) Q.push(temp->left);
            if(temp->right) Q.push(temp->right);
            ans.push_back(temp->val);
        }
        sort(ans.begin(),ans.end());
        int n = ans.size();
        int res = 0;
        for(int i=0;i<n;i++){
            if( i+1 == k) {
                res = ans[i];
                break;
                }
        }
        return res;
    }
};
