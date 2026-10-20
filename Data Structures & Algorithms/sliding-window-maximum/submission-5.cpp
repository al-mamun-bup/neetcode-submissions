class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            // remove elements that are outside the windows
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }

            // remove elements that are smaller than curr
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
