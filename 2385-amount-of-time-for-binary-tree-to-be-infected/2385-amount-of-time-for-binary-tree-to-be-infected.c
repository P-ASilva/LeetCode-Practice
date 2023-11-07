/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define max(x,y) ((x>y))?x:y

int relativeDepth(struct TreeNode* root, int level) {
    if (root != NULL) {
       int l = relativeDepth(root->left, level +1);
       int r = relativeDepth(root->right, level +1);
       if (r > l) {
            return r;
       } 
       return l;
    }
    return level-1;
}

int findInfected(struct TreeNode* root, int start, int level, int* infectedD) {
    if (root != NULL) {
        if (root->val == start) {
            *infectedD = 0;
            return relativeDepth(root,0);
        }
        int ld = -1;
        int rd = -1;
        int left = findInfected(root->left, start, level+1, &ld);
        int right = findInfected(root->right, start, level+1, &rd);

        if (ld != -1) {
            *infectedD = ld+1;
            return max(relativeDepth(root->right,1)+*infectedD,left);
        } else if (rd != -1) {
            *infectedD = rd+1;
            
            return max(relativeDepth(root->left,1)+*infectedD,right);
        }
        return max(left, right);
    }
    return level-1;
}

int amountOfTime(struct TreeNode* root, int start) {
    if (root != NULL) {
        int infected = -1;
        return findInfected(root, start, 0, &infected);
    }
    return 0;
}