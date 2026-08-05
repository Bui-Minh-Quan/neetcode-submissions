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
private:
    bool helper(TreeNode* root, int min_val=INT_MIN, int max_val=INT_MAX) {
        if (!root)  
            return true;
        
        if (root -> val <= min_val || root -> val >= max_val)
            return false;
        
        bool left = helper(root -> left, min_val, root -> val);
        bool right = helper(root -> right, root -> val, max_val);

        return left && right;
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MIN, INT_MAX);
         
    }
};













