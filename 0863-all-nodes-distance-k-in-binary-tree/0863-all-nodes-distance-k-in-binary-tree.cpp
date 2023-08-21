/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>parent;
         queue<TreeNode*>q;
         q.push(root);
         while(!q.empty()){
             int size=q.size();
             for(int i=0;i<size;i++){
                 TreeNode* front=q.front();
                 q.pop();
                 if(front->left){
                     parent[front->left]=front;
                     q.push(front->left);
                 }
                 if(front->right){
                     parent[front->right]=front;
                     q.push(front->right);
                 }
             }
         }
         q.push(target);
         map<TreeNode*,bool>visited;
         visited[target]=1;
         int ans=0;
         while(!q.empty()){
              int size=q.size();
              int flag=0;
            if(ans==k) break;
             for(int i=0;i<size;i++){
                 auto front=q.front();
                 cout<<front->val<<" ";
                  q.pop();
                 if(front->left && !visited[front->left]){
                     flag=1;
                     visited[front->left]=1;
                     q.push(front->left);
                 }
                 if(front->right && !visited[front->right]){
                     flag=1;
                     visited[front->right]=1;
                     q.push(front->right);
                 }
                 if(parent[front] && !visited[parent[front]]){
                     flag=1;
                    visited[parent[front]]=1;
                     q.push(parent[front]);
                 }
             }
             ans+=flag;
         }
         vector<int>ans2;
         while(!q.empty()){
             ans2.push_back(q.front()->val);
             q.pop();
         }
         return ans2;
    }
};