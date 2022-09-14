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
bool palindrome(unordered_map<int,int>& mp,int n){
int v=0;
for(auto val:mp){
if(val.second%2)
v++;
}
return v<=1;
}
void solve(TreeNode* root,unordered_map<int,int>& mp,int n,int& count){
if(root==NULL)
return ;
if(root!=NULL && root->left==NULL && root->right==NULL){
n++;
mp[root->val]++;
if(palindrome(mp,n)){
count++;
}
n--;
mp[root->val]--;
if(mp[root->val]==0)
mp.erase(root->val);
return ;
}
int val=root->val;
mp[val]++;
solve(root->left,mp,n+1,count);
solve(root->right,mp,n+1,count);
mp[val]--;
if(mp[val]==0)
mp.erase(val);
}
int pseudoPalindromicPaths (TreeNode* root) {
if(root!=NULL && root->left==NULL && root->right==NULL)
return 1;
unordered_map<int,int> mp;
int count=0;
solve(root,mp,0,count);
return count;
}
};