class Solution {
public:
    bool isPalindromic(string s) {
        string binary = "";

        // Convert every character into 8-bit ASCII binary
        for(char c : s) {
            binary += bitset<8>(c).to_string();
        }

        // Check palindrome
        int i = 0;
        int j = binary.length() - 1;

        while(i < j) {
            if(binary[i] != binary[j])
                return false;

            i++;
            j--;
        }

        return true;
    }
};