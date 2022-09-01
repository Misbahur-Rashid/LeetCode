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
    int count=0;
    void goodnodes(TreeNode* root,stack<int>&s){
        if(!root)return;
        if(!s.size())s.push(root->val);
        else{
            if(root->val>=s.top())s.push(root->val);
        }
        goodnodes(root->left,s);
        goodnodes(root->right,s);
        if(root->val==s.top()){
            count++;
            s.pop();
        }
        return;
    }
    int goodNodes(TreeNode* root) {
       stack<int>s;
        goodnodes(root,s);
        return count;
    }
};