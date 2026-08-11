class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int sum = nums[0];

        // Find sequential prefix sum
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            }
            else {
                break;
            }
        }

        // Find smallest integer >= sum
        // which is not present in nums
        while(find(nums.begin(), nums.end(), sum) != nums.end()) {
            sum++;
        }

        return sum;
    }
};