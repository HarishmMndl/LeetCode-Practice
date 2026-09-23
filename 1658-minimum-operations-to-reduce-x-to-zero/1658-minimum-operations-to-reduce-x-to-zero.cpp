class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total = 0;
        for(int num : nums)
            total += num;

        int target = total - x;

        if(target < 0)
            return -1;

        if(target == 0)
            return n;

        int i = 0;
        int sum = 0;
        int maxLen = -1;

        for(int j = 0; j < n; j++) {
            sum += nums[j];

            while(sum > target && i <= j) {
                sum -= nums[i];
                i++;
            }

            if(sum == target)
                maxLen = max(maxLen, j - i + 1);
        }

        if(maxLen == -1)
            return -1;

        return n - maxLen;
    }
};