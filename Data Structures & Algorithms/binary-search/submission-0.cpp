class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = -1;
        int lo = 0, hi = nums.size()-1;
        while(hi >= lo){
            int mid = lo + (hi-lo) / 2;
            if(nums[mid]==target){
                index = mid;
                break;
            }else if(nums[mid] < target){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }

        return index;

    }

};