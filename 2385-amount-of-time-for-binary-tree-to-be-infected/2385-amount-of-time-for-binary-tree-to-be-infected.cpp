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
    int amountOfTime(TreeNode* root, int start) {
        TreeNode * target;
         map<TreeNode*,TreeNode*>parent;
         queue<TreeNode*>q;
         q.push(root);
         while(!q.empty()){
             int size=q.size();
             for(int i=0;i<size;i++){
                 TreeNode* front=q.front();
                 if(front->val==start) target=front;
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
         return ans;
    }
};