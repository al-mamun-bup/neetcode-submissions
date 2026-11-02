class Solution {
public:
    int climbStairs(int n) {
        // curr stands on n - 2 th indx or n-1 th position.and prev : nth position
        int curr = 1, prev = 1;
        // for n = 5
        //   8 5 3 2 1 1
        for(int i = 0 ; i < n-1; i++){
            int temp = curr;
            curr = curr + prev;
            prev = temp;
        }

        return curr;
    }
};
