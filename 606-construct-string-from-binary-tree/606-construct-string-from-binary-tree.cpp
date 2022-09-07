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
    string tree2str(TreeNode* t) {
        string abc = "";
        preOrder(t, abc);
        return abc;
    }

private:
    void preOrder(TreeNode* t, string& abc) {
        if(t) {
            abc += to_string(t->val);
            if(t->left) {
                abc += "(";       
                preOrder(t->left, abc);
                abc += ")";
            }
            else if (t->right) {
                abc += "()";
            }
            if(t->right) {
                abc += "(";
                preOrder(t->right, abc);
                abc += ")";
            }
        }
    }
};