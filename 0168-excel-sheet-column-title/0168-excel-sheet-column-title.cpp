class Solution {
public:
    string convertToTitle(int n) {
        string ans;

        while(n > 0){
         n--;
         char ch = 'A' + (n % 26);
         ans += ch;
         n /= 26; 
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};