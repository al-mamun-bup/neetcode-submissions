class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 1;
        for (int x : st) {
            if (!st.count(x - 1)) {          // x is the start of a run
                int cur = x;
                while (st.count(cur + 1)) cur++;
                longest = max(longest, cur - x + 1);
            }
        }
        return longest;
    }
};