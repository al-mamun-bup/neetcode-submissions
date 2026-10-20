class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
    deque<int> dq;
    int n = nums.size();

    for (int r = 0; r < n; r++) {
        // Remove indices outside the current window
        while (!dq.empty() && dq.front() <= r - k) {
            dq.pop_front();
        }

        // Remove smaller elements from the back
        while (!dq.empty() && nums[dq.back()] <= nums[r]) {
            dq.pop_back();
        }

        // Insert current index
        dq.push_back(r);

        // Record maximum when the window is complete
        if (r >= k - 1) {
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;
    }
};
