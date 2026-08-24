class Solution {
public:
    int strStr(string hayst, string needle) {
     // RabinKarp Algorithm
     int n = hayst.length();
     int m = needle.length();

     if(m > n) return -1;

     long long base = 26;
     long long mod = 1e9 + 7;

     long long patternhash = 0;
     long long windowhash = 0;

     long long power = 1;
     for(int i = 1; i < m; i++){
         power = (power * base) % mod;
     }

     // Calculating pattern hash
     for(int i = 0; i < m; i++){
        int value = needle[i] - 'a' + 1;
        patternhash = ( patternhash * base + value ) % mod;
     }

     // calculating window hash
     for(int i = 0; i < m; i++){
        int value = hayst[i] - 'a' + 1;
        windowhash = (windowhash * base + value) % mod;
     }

     // sliding Window

     for(int i = 0; i <= n-m; i++){
        if(patternhash == windowhash){
            // Check characters
            if(hayst.substr(i,m) == needle)
            return i;
        }
     
        // Calculate of Next Window

        if(i < n - m){
            int oldValue = hayst[i] - 'a' + 1;
            int newValue = hayst[i + m] - 'a' + 1;

            windowhash =
                    (windowhash - oldValue * power) % mod;

                if (windowhash < 0)
                    windowhash += mod;

                windowhash =
                    (windowhash * base + newValue) % mod;
            }
     
     }
    return -1;
    

    }
};