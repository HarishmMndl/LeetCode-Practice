class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());

        int multiple = 1;

        while (st.count(multiple * k)) {
            multiple++;
        }

        return multiple * k;
    }
};