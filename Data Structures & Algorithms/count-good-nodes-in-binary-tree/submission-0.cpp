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
    int cnt = 0;
    int goodNodes(TreeNode* root) {
        dfs(root, root -> val);
        return cnt;
    }
    void dfs(TreeNode* node, int max_till_now) {
        if (!node) return;
        if (node -> val >= max_till_now) {
            cnt++;
            max_till_now = node -> val;
        }
        dfs(node -> left, max_till_now);
        dfs(node -> right, max_till_now);
    }
};