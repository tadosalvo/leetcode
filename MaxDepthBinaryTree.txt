// Solve by recursion

class Solution {
public:
    int count = 0;
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
    }
};

//https://www.youtube.com/watch?v=dvmoHr5cN80
// recursively travels through left and right children of root and sees which one is greater
// base case is when root is NULL
// traverses up once it hits base case