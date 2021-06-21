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


 // iterative approach First travels through left tree until null and creates a stack
 // Once at the end of the stack pop out the top of the stack and add to list
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> list;

        // traverse through left tree until null
        // reason why we check if stack is not empty is so we can backtrack the tree
        while (!stack.empty() || root != NULL)    {
            // pushes on to stack as we traverse
            while(root != NULL) {
                stack.push(root);
                root = root -> left;
            }
            root = stack.top();
            stack.pop();
            list.push_back(root -> val);
            root = root -> right;

        }
        return list;        
    }
};

// Recursive approach
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }

    void inorder(TreeNode* root, vector<int>& nodes) {
        if (root == NULL) {
            return;
        }

        inorder(root -> left, nodes);
        result.push_back(root -> val);
        inorder(root -> right, nodes);
    }
};

//Morris traversal
// creates temp link on right most branch to backtrack the tree

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        TreeNode* cur = root;

        while(cur != NULL) {
            // left is null then print the node and go to right
            if (cur -> left == NULL) {
                nodes.push_back(cur -> val);
                cur = cur -> right;
            }
            else {
                // find the predecessor
                TreeNode* pre = cur -> left;
                // To find the predecessor keep traversing right till the right node is not null or right node is not current
                while (pre -> right != cur && pre -> right != NULL) {
                    pre = pre -> right;
                }
                // if right node is null then go left after establishing link from predecessor to current
                if (pre -> right == NULL) {
                    pre -> right = cur;
                    cur = cur -> left;
                }
                // left already visit, go right after visiting current
                else {
                    pre -> right = NULL;
                    nodes.push_back(cur -> val);
                    cur = cur -> right;
                }
            }
        }
        return nodes;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        while (root) {
            if (root -> left) {
                TreeNode* pre = root -> left;
                while (pre -> right && pre -> right != root) {
                    pre = pre -> right;
                }
                if (!pre -> right) {
                    pre -> right = root;
                    root = root -> left;
                } else {
                    pre -> right = NULL;
                    nodes.push_back(root -> val);
                    root = root -> right;
                }
            } else {
                nodes.push_back(root -> val);
                root = root -> right;
            }
        }
        return nodes;
    }
};