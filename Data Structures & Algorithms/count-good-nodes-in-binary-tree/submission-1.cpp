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
    int ans = 0;
    
    void helper(TreeNode* root, int prev_max = 0) {
        if (!root)
            return;
        
        if (root -> val >= prev_max) {
            ++ans;
            prev_max = root -> val;
        }

        helper(root -> left, prev_max);
        helper(root -> right, prev_max);
    }

public:
    int goodNodes(TreeNode* root) {
        helper(root, INT_MIN);
        return ans;
    }
};
