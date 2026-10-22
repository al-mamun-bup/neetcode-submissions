class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        // Find any meeting point inside the cycle.
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                break;
            }
        }
        // now find the duplicate
        int slow2 = 0;
        while(1){
            // slow will go throught the cycle value 4 2 4 2 4 2... like this
            slow = nums[slow];
            slow2 = nums[slow2];
            if(slow == slow2){
                return slow;
            }
        }
    }
};
