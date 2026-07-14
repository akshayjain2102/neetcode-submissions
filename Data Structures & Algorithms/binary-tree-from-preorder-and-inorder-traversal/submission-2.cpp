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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       unordered_map<int,int> mpp;
       for(int i=0;i<inorder.size();i++){
        mpp[inorder[i]] = i;
       }
       TreeNode* root = treebuild(preorder,0,preorder.size()-1,
                                  inorder,0,inorder.size()-1,mpp);
       return root;
    }

    TreeNode* treebuild(vector<int>& preorder,int prest, int preen
                        ,vector<int>& inorder ,int inst , int inen,unordered_map<int,int> mpp){
        if(prest > preen || inst > inen) return NULL;
        TreeNode* root = new TreeNode(preorder[prest]);
        int idx = mpp[root->val];
        int numsleft = idx - inst;
        root->left = treebuild(preorder,prest+1,prest+numsleft,
                               inorder,inst,idx-1,mpp);
        root->right = treebuild(preorder,prest+1+numsleft,preen,
                               inorder,idx+1,inen,mpp);
        return root;
        }
        
};
