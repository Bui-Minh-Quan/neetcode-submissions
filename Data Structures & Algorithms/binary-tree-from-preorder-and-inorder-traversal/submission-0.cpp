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
    unordered_map<int, int> mp;

    TreeNode* helper(vector<int>& preorder, int pre_begin, int pre_end,
                     vector<int>& inorder, int in_begin, int in_end) {
        
        if (pre_begin > pre_end || in_begin > in_end) 
            return nullptr;
        

        // Create root
        TreeNode* root = new TreeNode(preorder[pre_begin]);

        // Root index in inorder
        int index = mp[root -> val];

        // Left size
        int left_size = index - in_begin;

        root -> left = helper(preorder, pre_begin + 1, pre_begin + left_size,
                              inorder, in_begin, index - 1);
        
        root -> right = helper(preorder, pre_begin + 1 + left_size, pre_end,
                               inorder, index + 1, in_end);
        
        return root;
    }
public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        
        return helper(preorder, 0, preorder.size() - 1,
                      inorder, 0, inorder.size() - 1);
    }
};







