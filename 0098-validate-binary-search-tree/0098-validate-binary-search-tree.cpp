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
    bool solve(TreeNode * root ,long long int mini,long long int maxi){
        if(!root) return true;
        if(root->val<=mini || root->val>=maxi) return false;
        return solve(root->left,mini,root->val) && solve(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,INT64_MIN,INT64_MAX);
    }
};