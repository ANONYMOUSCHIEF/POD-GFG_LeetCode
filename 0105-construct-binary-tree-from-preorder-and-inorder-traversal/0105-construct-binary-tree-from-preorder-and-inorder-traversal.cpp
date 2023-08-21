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
    map<int,int>m;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd){
        if(inStart>inEnd || preStart>preEnd) return NULL;
        TreeNode* root=new TreeNode(preorder[preStart]);
        int mid=m[preorder[preStart]];
        int size=mid-inStart;
        root->left=solve(preorder,inorder,preStart+1,preStart+size,inStart,mid-1);
        root->right=solve(preorder,inorder,preStart+size+1,preEnd,mid+1,inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        if(!n) return NULL;
       for(int i=0;i<n;i++) m[inorder[i]]=i;
       return solve(preorder,inorder,0,n-1,0,n-1);
        
    }
};