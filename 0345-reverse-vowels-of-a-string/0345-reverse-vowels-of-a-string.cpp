class Solution {
public:
    string reverseVowels(string s) {
       set<char> vowels = {
        'a','e','i','o','u','A','E','I','O','U'
       };

       int n = s.length();
       int i = 0;
       int j = n - 1;

       while(i < j){
        
         if(!vowels.count(s[i])){
             i++;
         }
         if(!vowels.count(s[j])){
            j--;
         }

         if(vowels.count(s[i]) && vowels.count(s[j])){
            swap(s[i],s[j]);
            i++;
            j--;
         }
       }
       return s;
    }
};