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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsSerialize(root, res);
        return join(res, ",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data, ',');
        int i = 0;
        return dfsDeserialize(vals, i);
    }
private:
    void dfsSerialize(TreeNode* node, vector<string>& res){
        if(node == nullptr){
            res.push_back("N");
            return;
        }
        
        res.push_back(to_string(node->val));
        dfsSerialize(node->left, res);
        dfsSerialize(node->right, res);
    }

    TreeNode* dfsDeserialize(vector<string>& vals, int& i){
        if(vals[i]=="N"){
            i++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;
        node->left = dfsDeserialize(vals, i);
        node->right = dfsDeserialize(vals, i);

        return node;
    }

    string join(vector<string>& vals, string delimiter) {
    string result = "";

    for (int i = 0; i < vals.size(); i++) {
        if (i > 0) {
            result += delimiter;
        }
        result += vals[i];
    }

      return result;
   }

   vector<string> split(string s, char delimiter) {
    vector<string> result;
    string temp = "";

    for (char c : s) {
        if (c == delimiter) {
            result.push_back(temp);
            temp = "";
        } else {
            temp += c;
        }
    }

    result.push_back(temp);

      return result;
   }

};
