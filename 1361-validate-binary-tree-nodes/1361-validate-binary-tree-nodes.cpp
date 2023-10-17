class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        unordered_set<int> set1;
        set1.insert(leftChild.begin(), leftChild.end());
        set1.insert(rightChild.begin(), rightChild.end());
        int root = -1;
        for (int i = 0; i < n; i++)
        {
            if (set1.find(i) == set1.end())
            {
                root = i;
                break;
            }
        }
        if (root == -1)
            return false;
        map<int, int> map1;
        queue<int> q;
        q.push(root);
        map1[root] = 1;
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            int left = leftChild[top];
            int right = rightChild[top];

            if (map1.find(right)==map1.end() && map1.find(left)==map1.end())
            {
                if (left != -1)
                {
                    q.push(left);
                    map1[left] = 1;
                }
                if (right != -1)
                {
                    q.push(right);
                    map1[right] = 1;
                }
            }
            else
                return false;
        }
        return map1.size()==n;
    }
};