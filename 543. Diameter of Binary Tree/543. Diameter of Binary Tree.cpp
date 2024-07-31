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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;

        depth(root, diameter);

        return diameter;

    }

private:

    int depth(TreeNode* node, int& diameter) {

        if (node == nullptr) {

            return 0;

        }

        int leftDepth = depth(node->left, diameter);

        int rightDepth = depth(node->right, diameter);

        // Update the diameter if the path through the current node is larger

        diameter = std::max(diameter, leftDepth + rightDepth);

        // Return the height of the tree rooted at the current node

        return std::max(leftDepth, rightDepth) + 1;

    
    }
};