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
    bool checkSame(TreeNode* p, TreeNode* q){
        if(p==NULL || q==NULL) return p==q;
        if(p->val==q->val) return (checkSame(p->left,q->left) && checkSame(p->right,q->right));
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checkSame(p,q);
    }
};
