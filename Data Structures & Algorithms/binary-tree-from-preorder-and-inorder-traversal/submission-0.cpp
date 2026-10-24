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
    unordered_map<int,int>mp;
    int preIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Using INORDER: store each value's index
        for(int i = 0; i < inorder.size();i++){
            mp[inorder[i]] = i;
        }

        return build(preorder,0,inorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, int left, int right){
        if(left > right){
            return nullptr;
        }

        // Using PREORDER: choose the next root
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Using INORDER: find where the root divides the tree
        int mid = mp[rootVal];

        // Using both: build the left and right subtrees
        root->left = build(preorder, left, mid -1 );
        root->right = build(preorder, mid + 1, right);

        return root;


    }
};
