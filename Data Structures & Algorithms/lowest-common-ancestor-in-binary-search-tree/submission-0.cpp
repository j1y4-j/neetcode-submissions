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
    TreeNode* lca(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node==NULL) return NULL;
        if(node->val==p->val || node->val ==q->val){
            return node;
        }
        TreeNode* left=lca(node->left,p,q);
        TreeNode* right=lca(node->right,p,q);
        if(left!=NULL && right!=NULL) return node;
        else if(left!=NULL) return left;
        else return right;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
    }
};
