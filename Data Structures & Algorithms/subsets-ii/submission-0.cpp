class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, 0,subset, res);
        return res;
    }

private:
    void dfs(const vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& res){
       
       res.push_back(subset);
        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1]) {
                continue;
            }

            subset.push_back(nums[j]);
            dfs(nums, j + 1, subset, res);
            subset.pop_back();
        }
    }
};
