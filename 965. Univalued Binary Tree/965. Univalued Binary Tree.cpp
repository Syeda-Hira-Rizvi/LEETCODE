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
    bool isUnivalTree(TreeNode* root) {
        int val = root->val;
        return ok(root, val);
    }

private:
    bool ok(TreeNode* root, int val) {
        if (root == NULL) return true;
        if (root->val != val) return false;

        return ok(root->left, val) && ok(root->right, val);
    
    }
};