class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int left = 0;
        int right = 0;

        int currSum = 0;

        // First window
        while(right < k) {
            currSum += nums[right];
            right++;
        }

        int maxSum = currSum;

        // Slide the window
        while(right < nums.size()) {

            currSum = currSum + nums[right] - nums[left];

            maxSum = max(maxSum, currSum);

            left++;
            right++;
        }

        return (double)maxSum / k;
    }
};