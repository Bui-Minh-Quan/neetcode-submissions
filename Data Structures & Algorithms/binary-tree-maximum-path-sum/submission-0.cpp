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
    int ans = INT_MIN;
    int helper(TreeNode* root) {
        if (!root)
            return 0;
        
        int left = helper(root -> left);
        int right = helper(root -> right);

        left = max(0, left);
        right = max(0, right);

        ans = max(ans, root -> val + left + right);


        return max(root -> val + left, root -> val + right);
    }

public:
    int maxPathSum(TreeNode* root) {
        helper(root);

        return ans;

    }
};








