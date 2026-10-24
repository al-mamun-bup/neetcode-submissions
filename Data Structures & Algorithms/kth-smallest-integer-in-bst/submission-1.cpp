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
    priority_queue<int,vector<int>,greater<int>>pq;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        int ans = -1;
        while(k-- and !pq.empty()){
            ans = pq.top();
            pq.pop();
        }

        return ans;
        
    }
    void dfs(TreeNode* root){
        if(root == nullptr){
            return;
        }
        pq.push(root->val);
        dfs(root->left);
        dfs(root->right);
    }
};
