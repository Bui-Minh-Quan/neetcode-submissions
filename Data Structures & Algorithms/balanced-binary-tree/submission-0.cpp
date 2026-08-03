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
    int helper(TreeNode* root) {
        if (!root)
            return 0;
        
        return 1 + max(helper(root -> left), helper(root -> right));
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) 
            return true;
        
        int left_height = helper(root -> left);
        int right_height = helper(root -> right);

        if (abs(left_height - right_height) > 1)
            return false;

        return isBalanced(root -> left) && isBalanced(root -> right);
        
    
    }
};
