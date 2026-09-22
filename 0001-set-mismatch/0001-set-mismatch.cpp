class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sum_of_n = 0;
        int dupli_num = 0;
        vector<int> ans;
        int n = nums.size();
        sum_of_n = (n * (n + 1)) / 2;
        
        // Find duplicate
        sort(nums.begin(),nums.end());

        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1])
            {
             dupli_num = nums[i];
             break;
            }
        }

        // Sum of nums
        int sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
        }  

        int missing_num = sum_of_n - (sum - dupli_num);

        ans.push_back(dupli_num);
        ans.push_back(missing_num);

       return ans;
    }
};
