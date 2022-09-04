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
    
    void traverse(map<int, map<int, vector<int>>>& mp, int level, int dist, TreeNode* root)
    {
        mp[dist][level].push_back(root->val);
        
        if(root->left)
        {
            traverse(mp, level+1, dist-1, root->left);
        }
        if(root->right)
        {
            traverse(mp, level+1, dist+1, root->right);
        }
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp;
        map<int, map<int, vector<int>>>::iterator mit;
        map<int, vector<int>>::iterator it;
        vector<vector<int>> res;
        
        traverse(mp, 0, 0, root);
      
        for (mit = mp.begin(); mit != mp.end(); mit++)
        {
            vector<int> tmp;
            for(it = (mit->second).begin(); it != (mit->second).end(); it++)
            {
                sort((it->second).begin(), (it->second).end());
                for (auto i: it->second)
                {
                    tmp.push_back(i);
                }
            }
            res.push_back(tmp);
        }
        
        return res;
        
    }
};