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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;  // If the node is null, return 0

        int sum = 0;

        if (root->val >= low && root->val <= high) {

            sum += root->val;  // Include the node's value if it's within the range

        }

        if (root->val > low) {

            sum += rangeSumBST(root->left, low, high);  // Recur on the left subtree

        }

        if (root->val < high) {

            sum += rangeSumBST(root->right, low, high);  // Recur on the right subtree

        }

        return sum;
    }
};