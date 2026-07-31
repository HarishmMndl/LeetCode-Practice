class Solution {
public:
    int minimumPushes(string word) {

        // Frequency of each character
        vector<int> freq(26, 0);

        for(char ch : word){
            freq[ch - 'a']++;
        }

        // Store only non-zero frequencies
        vector<int> v;

        for(int x : freq){
            if(x > 0)
                v.push_back(x);
        }

        // Sort frequencies in descending order
        sort(v.rbegin(), v.rend());

        int ans = 0;

        // First 8 characters -> cost 1
        // Next 8 characters -> cost 2
        // Next 8 characters -> cost 3
        // Next 8 characters -> cost 4
        for(int i = 0; i < v.size(); i++){
            ans += v[i] * (i / 8 + 1);
        }

        return ans;
    }
};