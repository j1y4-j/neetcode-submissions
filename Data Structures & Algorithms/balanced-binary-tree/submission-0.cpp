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
    int findHeight(TreeNode* node){
        if(node==NULL) return 0;
        int lh=findHeight(node->left);
        int rh=findHeight(node->right);
        return 1+max(lh,rh);

    }
    bool check(TreeNode* node){
        if(node==nullptr) return true;
        int lh=findHeight(node->left);
        int rh=findHeight(node->right);
        if(abs(lh-rh)>1) return false;
        bool left=check(node->left);
        bool right=check(node->right);
        if(!left || !right) return false;
        return true;
    }
    bool isBalanced(TreeNode* root) {
        return check(root);
    }
};
