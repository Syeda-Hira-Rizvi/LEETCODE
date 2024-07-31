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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;

        // Create 2 stacks for the path and the sums
        std::stack<TreeNode*> path;
        std::stack<int> sumPath;

        path.push(root);
        sumPath.push(root->val);

        while (!path.empty()) {
            TreeNode* temp = path.top();
            path.pop();
            int tempVal = sumPath.top();
            sumPath.pop();

            // If a child node and we find the sum total, return true
            if (temp->left == nullptr && temp->right == nullptr && tempVal == targetSum)
                return true;
            
            if (temp->right != nullptr) {

                path.push(temp->right);

                sumPath.push(temp->right->val + tempVal);

            }

            if (temp->left != nullptr) {

                path.push(temp->left);

                sumPath.push(temp->left->val + tempVal);

            }

        }

        return false;
    }
};