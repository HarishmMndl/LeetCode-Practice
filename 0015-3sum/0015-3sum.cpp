class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
     vector<vector<int>> ans;
    sort(nums.begin(),nums.end());

    for(int i = 0; i < n-2; i++){
        // i first pointer

         // Skip duplicate first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

                
        int left = i + 1; // 2nd pointer
        int last = n-1;  // 3rd pointer
        while(left < last){
            if(nums[left] + nums[last] + nums[i] < 0)
            left++;
            else if(nums[left] + nums[last] + nums[i] > 0)
            last--;
            else{
            ans.push_back({nums[i],nums[left],nums[last]});
            left++;
            last--;

             while (left < last && nums[left] == nums[left - 1])
                        left++;

                    // Skip duplicate third element
              while (left < last && nums[last] == nums[last + 1])
                        last--;
            }
        }
    }
    return ans;
    }
};