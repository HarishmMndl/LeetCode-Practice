class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void solve(vector<int>& cand, int target, int start) {

        if(target == 0) {
            ans.push_back(subset);
            return;
        }

        for(int i = start; i < cand.size(); i++) {

            // Duplicate skip
            if(i > start && cand[i] == cand[i-1])
                continue;

            // Since sorted
            if(cand[i] > target)
                break;

            subset.push_back(cand[i]);

            // i + 1 because element can be used only once
            solve(cand, target - cand[i], i + 1);

            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {

        sort(cand.begin(), cand.end());

        solve(cand, target, 0);

        return ans;
    }
};