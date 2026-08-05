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
    vector<int> vt;

    void add_nodes(TreeNode* root) {
        if (!root)
            return;
        
        add_nodes(root -> left);
        vt.push_back(root -> val);
        add_nodes(root -> right);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        add_nodes(root);
        return vt[k - 1];
    }
};





