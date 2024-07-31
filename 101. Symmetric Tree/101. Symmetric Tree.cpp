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
    bool isSymmetric(TreeNode* root) {
        // An empty tree is symmetric

        if (root == nullptr) {

            return true;

        }

        // Check if the left and right subtrees are mirrors of each other

        return isMirror(root->left, root->right);

    }

private:

    // Helper function to check if two trees are mirror images of each other

    bool isMirror(TreeNode* left, TreeNode* right) {

        // If both trees are empty, they are mirrors of each other

        if (left == nullptr && right == nullptr) {

            return true;

        }

        // If one tree is empty and the other is not, they are not mirrors

        if (left == nullptr || right == nullptr) {

            return false;

        }

        // Check if the current nodes are equal and the left subtree of the first tree

        // is a mirror of the right subtree of the second tree, and vice versa

        return (left->val == right->val)

            && isMirror(left->left, right->right)

            && isMirror(left->right, right->left);

    }
};