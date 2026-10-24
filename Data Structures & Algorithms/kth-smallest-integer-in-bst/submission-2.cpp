class Solution {
public:
    int ans;
    int count = 0;

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }

    void inorder(TreeNode* root, int k) {
        if (root == nullptr) {
            return;
        }

        inorder(root->left, k);

        count++;
        if (count == k) {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }
};