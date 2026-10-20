class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(),piles.end());
        int ans = hi;

        while(lo <= hi){
            int k = (lo+hi) / 2;
            int totTime = 0;
            for(auto p : piles){
                totTime += (p+k-1) / k;
            }
            if(totTime <= h){
                ans = k;
                hi = k - 1;
            }else{
                lo = k + 1;
            }
        }

        return  ans;
    }
};
