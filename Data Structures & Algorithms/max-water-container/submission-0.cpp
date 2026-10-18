class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size()-1;
        int ans = 0;
        while(l < r){
            if(heights[l] <= heights[r]){
                ans = max(ans,(r-l)*min(heights[l],heights[r]));
                l++;
            }else{
                ans = max(ans,(r-l)*min(heights[l],heights[r]));
                r--;
            }
        }

        return ans;
    }
};