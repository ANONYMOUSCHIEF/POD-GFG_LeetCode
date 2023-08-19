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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>m;
        if(!root)
        return ans;
        
        q.push({root,{0,0}});
        
        while(!q.empty()){
            TreeNode * temp=q.front().first;
            int index1=q.front().second.first;
             int index2=q.front().second.second;
            m[index1][index2].insert(temp->val);
            q.pop();
            if(temp->left)
            q.push({temp->left,{index1-1,index2+1}});
            
            if(temp->right)
            q.push({temp->right,{index1+1,index2+1}});
        }
        
        for(auto x:m){
            vector<int>last;
            for(auto y:x.second){
                last.insert(last.end(),y.second.begin(),y.second.end());
            }
            // sort(last.begin(),last.end());
            ans.push_back(last);
        }
        return ans;
    }
};