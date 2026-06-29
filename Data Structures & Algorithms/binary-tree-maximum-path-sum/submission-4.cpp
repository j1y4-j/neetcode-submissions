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
    int maxi=INT_MIN;
    
    int findMax(TreeNode* node){
        if(node==NULL) return 0;
        int leftMaxi=max(0,findMax(node->left)); // 0 to avoid -ve vals
        int rightMaxi=max(0,findMax(node->right));
        maxi=max(maxi,leftMaxi+rightMaxi+node->val);
        return node->val+max(leftMaxi,rightMaxi);

       

    }
    int maxPathSum(TreeNode* root) {
        
      findMax(root);  
      return maxi;
    }
};
