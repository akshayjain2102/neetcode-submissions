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
    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int count = 0;
        queue<pair<TreeNode*,int>> Q;
        Q.push({root,root->val});
        while(!Q.empty()){
            auto curr = Q.front();
            Q.pop();
            TreeNode* temp = curr.first;
            int newmax = curr.second;
            if(temp->val >= newmax){
                count++;
                newmax = temp->val;
            }
            if( temp->left) Q.push({temp->left,newmax});
            if( temp->right) Q.push({temp->right,newmax});
        }
        return count;
    }
};
