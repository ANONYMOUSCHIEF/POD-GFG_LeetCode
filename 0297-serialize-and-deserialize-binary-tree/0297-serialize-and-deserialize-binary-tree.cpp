/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s = "";
        if (!root)
            return s;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *front = q.front();
                q.pop();
                if (!front)
                    s.push_back('#');
                else
                    s += to_string(front->val);
                if (front)
                {
                    q.push(front->left);
                    q.push(front->right);
                }
                s.push_back(',');
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (!data.size())
            return NULL;
      stringstream s(data);
        string str; 
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int j = 0; j < size; j++)
            {
                TreeNode *front = q.front();
                q.pop();
                 getline(s, str, ',');
                if (str=="#")
                    front->left = NULL;
                else
                    front->left = new TreeNode(stoi(str)), q.push(front->left);
                 getline(s, str, ',');
                if (str == "#")
                    front->right = NULL;
                else
                     front->right = new TreeNode(stoi(str)),q.push(front->right);
                ;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));