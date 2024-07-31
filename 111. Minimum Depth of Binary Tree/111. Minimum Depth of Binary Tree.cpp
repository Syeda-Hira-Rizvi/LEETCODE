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
    int minDepth(TreeNode* root) {
        if (root == nullptr)

            return 0;

        int depth = 1;

        std::queue<TreeNode*> q;

        q.push(root);

        // Level order traversal

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();

                q.pop();

                // If a leaf node is found just return depth

                if (node->left == nullptr && node->right == nullptr) {

                    return depth;

                }

                if (node->left != nullptr) {

                    q.push(node->left);

                }
                if (node->right != nullptr) {

                    q.push(node->right);

                }

            }

            depth++;

        }

        return depth;
    }
};