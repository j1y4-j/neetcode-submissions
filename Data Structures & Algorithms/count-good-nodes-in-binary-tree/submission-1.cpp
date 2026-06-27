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
int count=0;
    void countGood(TreeNode* node, int maxSoFar){
        if(node==NULL) return;
        
        if(node->val >= maxSoFar) count++;
        countGood(node->left,max(maxSoFar,node->val));
        countGood(node->right,max(maxSoFar,node->val));

        
    }
    int goodNodes(TreeNode* root) {
        countGood(root,root->val);
        return count;
    }
};
