 class Solution {
    public:
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            return help(nums, 0, nums.size()-1);
        }
        
        TreeNode* help(vector<int> &nums, int start, int end){
            int _size=end-start;
            if(_size<0)    return NULL;
            if(_size==0)    return new TreeNode(nums[start]);
            int mid=(start+end)/2;
            TreeNode* root=new TreeNode(nums[mid]);
            root->left=help(nums, start, mid-1);
            root->right=help(nums, mid+1, end);
        }
    };

// using recursion and helper method
class Solution {
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end){
        if(end<=start) return NULL; 
        int midIdx=(end+start)/2;
        TreeNode* root=new TreeNode(nums[midIdx]);
        root->left=sortedArrayToBST(nums, start, midIdx);
        root->right=sortedArrayToBST(nums, midIdx+1,end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0,nums.size());
    }
};
