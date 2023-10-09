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

    TreeNode* origin = nullptr;

    bool findTarget(TreeNode* root, int k) {
        if (root != nullptr) {
            if (origin == nullptr) {
                origin = root;
            } else {
                if (partialSum(origin, k, root)) {
                    return true;
                }
            }
            return findTarget(root->left, k) || findTarget(root->right, k);
        }
        return false;
    } 

    bool partialSum(TreeNode* root, int k, TreeNode* node) {
        if (root != nullptr) {
            if (node->val + root->val == k && node != root) {
                return true;
            } 
            return partialSum(root->left, k, node) || partialSum(root->right, k, node);
        }
        return false;
    }
};