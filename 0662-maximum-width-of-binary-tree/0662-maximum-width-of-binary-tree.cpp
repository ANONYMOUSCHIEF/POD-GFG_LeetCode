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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans=1;
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,0*1LL});
        while(!q.empty()){
            int size=q.size();
            int start=0,end=0;
            int mini=q.front().second;
            for(int i=0;i<size;i++){
                auto front= q.front().first;
                long long ind=q.front().second-mini;
                q.pop();
                if(i==0) start=ind;
                if(i==size-1) end=ind;
                if(front->left) q.push({front->left,((2*ind )+ 1)*1LL});
                if(front->right) q.push({front->right,((2*ind) +2)*1LL });
            }
            ans=max(ans,end-start+1);
        }
        return ans;
    }
};