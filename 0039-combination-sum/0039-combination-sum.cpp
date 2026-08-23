class Solution {
public:
      vector<vector<int>> ans;
      vector<int> subset;
    void checksubset(vector<int>& cand, int target,int i,int sum){
        // base Case
        int n = cand.size();
        if(sum == target){
            ans.push_back(subset);
            return;
        }

        if(i == n || sum > target) return;

        // Inclusion 
        subset.push_back(cand[i]);
        checksubset(cand,target,i,cand[i]+sum);

        // backtrack
        subset.pop_back();

        // Exclusion
        checksubset(cand,target,i+1,sum);

    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
      
      
      checksubset(cand,target,0,0); 
      return ans; 
    }
};