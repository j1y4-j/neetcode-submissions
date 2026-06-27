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
    bool checkIsSame(TreeNode* p, TreeNode* q){
        if(p==NULL || q==NULL) return p==q;
        if(p->val==q->val){
            return (checkIsSame(p->left,q->left)&& checkIsSame(p->right,q->right));
        }
        return false;
    }
    bool check(TreeNode* root, TreeNode* subRoot){
        if(root==NULL) return false;
        if(root->val==subRoot->val){
            TreeNode* newRoot=root;
            if(checkIsSame(root,subRoot)) return true;
        }
       return( check(root->left,subRoot) || check(root->right,subRoot));
    
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return check(root,subRoot);
    }
};
