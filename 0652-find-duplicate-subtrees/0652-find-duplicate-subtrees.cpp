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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>a;
        vector<TreeNode*>ans;
        solve(root,a,ans);
        return ans;
    }
    string solve(TreeNode* root, unordered_map<string,int>&a,vector<TreeNode*>&ans)
    {
        
        if(!root)
        {
            return "";
        }
        string s=to_string(root->val)+","+solve(root->left,a,ans)+","+solve(root->right,a,ans);
        
        a[s]++;
        if(a[s]==2)
        {
            ans.push_back(root);
        }
        return s;
    }
};