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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        v.push_back(k);
        dfs(root, v);
        return v[k];
    }
    void dfs(TreeNode* node, vector<int> &v) {
        if (!node) return;
        dfs(node -> left, v);
        if (v[0] == 0) return;
        v.push_back(node -> val);
        v[0]--;
        dfs(node -> right, v);
    }
};
