/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     vector<vector<int>> pathSum(TreeNode* root, int sum) {
//         vector<vector<int>> res;
//         vector <int> path;
//         DFS(path, root, sum, res);
//         return res;
//     }
    
//     void DFS(vector <int> path, TreeNode* root, int sum, vector<vector<int>> &res)
//     {
//         if (root == NULL)
//             return;
//         if (root->left == NULL && root->right == NULL)
//         {
//             if (root->val == sum)
//             {
//                 path.push_back(root->val);
//                 res.push_back(path);
//                 path.pop_back();
//             }
//         }
//         path.push_back(root->val);
//         DFS(path, root->left, sum - root->val, res);
//         DFS(path, root->right, sum - root->val, res);
//         path.pop_back();
//     }
// };



// class Solution {
// public:
//     vector<vector<int>> ans;
//     int sum;
    
//     void backtrack(TreeNode* cur, vector<int>& path){
//         //cur must not be nullptr
//         //when entering this function, cur is added in "path"
//         if(!cur->left && !cur->right){
//             // for(const int& e : path) cout << e << " ";
//             // cout << endl;
//             if(accumulate(path.begin(), path.end(), 0) == sum){
//                 ans.push_back(path);
//             }
//         }else{
//             if(cur->left){
//                 path.push_back(cur->left->val);
//                 backtrack(cur->left, path);
//                 path.pop_back();
//             }
            
//             if(cur->right){
//                 path.push_back(cur->right->val);
//                 backtrack(cur->right, path);
//                 path.pop_back();
//             }
//         }
//     }
    
//     vector<vector<int>> pathSum(TreeNode* root, int sum) {
//         if(!root) return vector<vector<int>>();
        
//         this->sum = sum;
        
//         vector<int> path = {root->val};
//         backtrack(root, path);
        
//         return ans;
//     }
// };



// class Solution {
// public:
//     vector<vector<int> > pathSum(TreeNode *root, int sum) {
//         vector<vector<int> > result;
//         vector<int> v;
//         generatePathSum(root, sum, 0, v, result);
//         return result;
//     }

//     void generatePathSum(TreeNode *root, int sum, int s, vector<int> v, vector<vector<int> >& result) {
//         if (root==NULL) return ;

//         s += root->val;
//         v.push_back(root->val);

//         if ( root->left==NULL && root->right==NULL) {
//             if (s == sum) result.push_back(v);
//             return;
//         }

//         generatePathSum(root->left, sum, s, v, result);
//         generatePathSum(root->right, sum, s, v, result);
//     }
// };


class Solution {

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        vector<vector<int>> res;
        if(!root)
            return res;

        vector<int> tres;
        dfs(root, tres, 0, sum, res);
        return res;
    }

private:
    void dfs(TreeNode* node, vector<int>& tres, int tsum,
             int sum, vector<vector<int>>& res){

        tres.push_back(node->val);
        tsum += node->val;

        if(!node->left && !node->right){
            if(tsum == sum)
                res.push_back(tres);
        }
        else {
            if (node->left)
                dfs(node->left, tres, tsum, sum, res);

            if (node->right)
                dfs(node->right, tres, tsum, sum, res);
        }

        tres.pop_back();
        return;
    }
};
