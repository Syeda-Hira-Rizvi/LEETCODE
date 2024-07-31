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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<TreeNode*> elementQueue;

        elementQueue.push(root);

        int numberOfLevels = 0;

        while (!elementQueue.empty()) {

            int nodeCountAtLevel = elementQueue.size();

            while (nodeCountAtLevel > 0) {

                TreeNode* element = elementQueue.front();

                elementQueue.pop();

                if (element->left != nullptr) {

                    elementQueue.push(element->left);

                }

                if (element->right != nullptr) {

                    elementQueue.push(element->right);

                }

                nodeCountAtLevel--;

            }

            numberOfLevels++;

        }
        return numberOfLevels;
    }
};