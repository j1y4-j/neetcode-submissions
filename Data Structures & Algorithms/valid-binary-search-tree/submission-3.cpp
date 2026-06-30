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
    bool checkValid(TreeNode* root,int mini,int maxi){
        if(root==nullptr) return true;
        if(root->val<=mini || root->val>=maxi) return false;
        return checkValid(root->left,mini,root->val) && checkValid(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root) {
        return checkValid(root,INT_MIN,INT_MAX);
    }
};
