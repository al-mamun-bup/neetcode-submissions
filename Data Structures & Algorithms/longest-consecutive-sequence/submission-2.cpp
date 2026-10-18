class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        set<int>st;
        int n = nums.size();
        vector<int>temp;
        for(int i = 0 ; i < n ; i++){
            st.insert(nums[i]);
        }
        for(auto it : st){
            temp.push_back(it);
        }

        int ans = 0;
        for(int i = 1 ; i < temp.size(); i++){
            int cnt = 0;
            while(i < temp.size() and temp[i]-temp[i-1]==1){
                cnt++;
                i++;
            }

            ans = max(ans,cnt);

        }

        return ans+1;
    }
};
