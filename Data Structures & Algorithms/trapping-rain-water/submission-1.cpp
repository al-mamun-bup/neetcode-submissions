class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int ans = 0;
        vector<int>pref(r+1),suff(r+1);
        pref[0] = height[0];
        for(int i = 1; i < r+1; i++){
            pref[i] = max(pref[i-1],height[i]);
        }

        suff[r] = height[r];
        for(int i = r-1; i >= 0 ; i--){
            suff[i] = max(suff[i+1],height[i]);
        }

        for(int i = 0 ; i <= r ; i++){
            ans += min(pref[i],suff[i]) - height[i];
        }
       
        return ans;
    }
    
};
