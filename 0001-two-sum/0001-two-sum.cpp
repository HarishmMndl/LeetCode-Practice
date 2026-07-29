class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> mp; // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];

            // if "need" already exists in map, return its index + current index
            if (mp.count(need)) {
                return { mp[need], i };
            }

            // store current value and index
            mp[nums[i]] = i;
        }

        return {}; // not needed but keeps compiler happy   
    }
};