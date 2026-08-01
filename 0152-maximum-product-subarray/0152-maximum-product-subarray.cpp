class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxPr = nums[0];
        int minPr = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            int curr = nums[i];

            int prevMax = maxPr;
            int prevMin = minPr;

            maxPr = max({curr,
                          curr * prevMax,
                         curr * prevMin});

            minPr = min({curr,
                         curr * prevMax,
                         curr * prevMin});

            ans = max(ans, maxPr);
        }

        return ans;
    }
};   