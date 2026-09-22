class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int max_c = 0;
        int i = 0;

        while(i < n) {
            int count = 0;

            
            while(i < n && nums[i] == 1) {
                count++;
                i++;
            }

            max_c = max(max_c, count);
            i++; 
        }

        return max_c;
    }
};