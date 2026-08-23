class Solution {
public:
    void getsubsets(vector<int>& nums,vector<int> &ans,int i,vector<vector<int>> &allsubsets){

        int n = nums.size();

        // Base case
        if(i == n){
            allsubsets.push_back(ans);
            return;
        }

        // inclusion
        ans.push_back(nums[i]);
        getsubsets(nums,ans,i+1,allsubsets);

        // Backtracking
        ans.pop_back();

        // Remove duplication
        int idx = i+1;
        while(idx < n && nums[idx] == nums[idx-1]) idx++;

        // exclusion
        getsubsets(nums,ans,idx,allsubsets);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // sorting 
        sort(nums.begin(),nums.end());
        vector<vector<int>> allsubsets;
        vector<int> ans;

        getsubsets(nums,ans,0,allsubsets);
        return allsubsets;
    }
};