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
    int maxPathSum(TreeNode* root) {
        int maxi  = INT_MIN;
        maxPathDown(root, maxi);
        
        return maxi;
    }
   int maxPathDown(TreeNode* node, int &maxi){
    if(node == NULL) return 0;

    int left = maxPathDown(node->left, maxi);
    int right = maxPathDown(node->right, maxi);

    int mx_straight =
        max(max(left, right) + node->val, node->val);

    int mx_caseVal =
        max(mx_straight, left + right + node->val);

    maxi = max(maxi, mx_caseVal);

    // maxi is global maxi found anywhere in the tree that's why I should return mx_straight 
    return mx_straight;
}
};