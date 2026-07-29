class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n - 3; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++) {

                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1;
                int last = n - 1;

                while (left < last) {

                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[last];

                    if (sum < target)
                        left++;

                    else if (sum > target)
                        last--;

                    else {

                        ans.push_back({nums[i], nums[j], nums[left], nums[last]});

                        left++;
                        last--;

                        while (left < last && nums[left] == nums[left - 1])
                            left++;

                        while (left < last && nums[last] == nums[last + 1])
                            last--;
                    }
                }
            }
        }

        return ans;
    }
};