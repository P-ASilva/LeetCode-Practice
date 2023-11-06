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
    int heritage(TreeNode* root, bool parentEven, bool grandParentEven) {
        if (root != NULL) {
            bool even = false;
            if ((root->val)%2 == 0) {
                even = true;
            }
            if (grandParentEven) {
                return root->val + heritage(root->right, even, parentEven) + heritage(root->left, even, parentEven);
            }
            return heritage(root->right, even, parentEven) + heritage(root->left, even, parentEven);
        }
        return 0;   
    }

    int sumEvenGrandparent(TreeNode* root) {
        return heritage(root, false, false);
    }
};