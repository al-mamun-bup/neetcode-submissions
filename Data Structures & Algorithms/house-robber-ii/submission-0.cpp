class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
         if(nums.size()==1) return nums[0];
         vector<int>temp1,temp2;
         for(int i = 1; i < n; i++) temp1.push_back(nums[i]);
         for(int i = 0; i < n-1; i++) temp2.push_back(nums[i]);

         int ans = max(solve(temp1),solve(temp2));

         return ans;
    }

    int solve(vector<int>&v){
        int n = v.size();
        int prev = v[0];
        int prev2 = 0;

        for(int i = 1; i < n ; i++){
            int take = v[i];
            if(i > 1) take += prev2;
            int notTake = 0 + prev;

            int curr = max(take,notTake);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};
