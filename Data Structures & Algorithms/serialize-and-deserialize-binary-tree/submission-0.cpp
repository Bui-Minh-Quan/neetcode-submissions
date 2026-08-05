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

class Codec {

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "null";
        queue<TreeNode*> q;

        string encode;

        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                encode += "null|";
                continue;
            }

            encode += to_string(curr -> val) + '|';

            q.push(curr -> left);
            q.push(curr -> right);
        }
        
        cout << encode;
        return encode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null")
            return nullptr;
        
        vector<string> tokens;
        string curr;

        for (char c : data) {
            if (c == '|') {
                tokens.push_back(curr);
                curr.clear();
            } else {
                curr += c;
            }
        }

        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                continue;
            }


            if (tokens[i] == "null") {
                node -> left = nullptr;
            } else {
                int value = stoi(tokens[i]);
                TreeNode* left = new TreeNode(value);
                node -> left = left;
            }
            ++i;

            if (tokens[i] == "null") {
                node -> right = nullptr;
            } else {
                int value = stoi(tokens[i]);
                TreeNode* right = new TreeNode(value);
                node -> right = right;
            }
            ++i;



            q.push(node -> left);
            q.push(node -> right);
        }

        return root;

    }
};








