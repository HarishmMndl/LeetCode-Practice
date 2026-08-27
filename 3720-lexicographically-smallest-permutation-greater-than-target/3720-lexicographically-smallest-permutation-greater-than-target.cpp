class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        sort(s.begin(), s.end());

        int n = s.size();

        // Try all positions from right to left
        for (int i = n - 1; i >= 0; i--) {

            string prefix = target.substr(0, i);

            // Check whether prefix can be formed from s
            string temp = s;

            bool possible = true;

            for (char c : prefix) {
                auto it = lower_bound(temp.begin(), temp.end(), c);

                if (it == temp.end() || *it != c) {
                    possible = false;
                    break;
                }

                temp.erase(it);
            }

            if (!possible)
                continue;

            // At position i, find smallest character > target[i]
            auto it = upper_bound(temp.begin(), temp.end(), target[i]);

            if (it != temp.end()) {

                string ans = prefix;

                ans += *it;
                temp.erase(it);

                // Remaining characters smallest order
                ans += temp;

                return ans;
            }
        }

        return "";
    }
};