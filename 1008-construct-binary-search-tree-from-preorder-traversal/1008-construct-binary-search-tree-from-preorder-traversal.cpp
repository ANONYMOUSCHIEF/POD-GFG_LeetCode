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
    TreeNode* make(TreeNode * root,int val){
        if(!root) return new TreeNode(val);
        if(val > root->val) root->right=make(root->right,val);
        else root->left=make(root->left,val);
        return root;
    } 
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        if(preorder.size()==0) return NULL;
        TreeNode * head =NULL;
        for(auto i:preorder){
            head = make(head,i);
        }
        return head;
        
        
    }
};